#include "stdafx.h"
#include "tank.h"


tank::tank()
{
}


tank::~tank()
{

}

HRESULT tank::init()
{
	_direction = DIRECTION_RIGHT;

	_image = IMAGEMANAGER->addFrameImage("tank", "tank.bmp", 0, 0, 256, 128, 8, 4, true, RGB(255, 0, 255));

	_speed = 100.0f;

	return S_OK;
}

void tank::release()
{

}

void tank::update()	
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_direction = DIRECTION_LEFT;
		
		
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_direction = DIRECTION_RIGHT;
		
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_direction = DIRECTION_UP;
		

	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_direction = DIRECTION_BOTTOM;
		
	}
	tankMove();
	//tankMove();
}

void tank::render()	
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top);
}


void tank::tankMove()
{
	//가상의 충돌박스
	RECT rcCollision;

	//가상의 충돌박스와 함께 타일검출을 할 준비물
	int tileIndex[2];
	int tileX, tileY;		//탱크가 몇 번째 타일을 밟고있는지 검출용

	rcCollision = _rc;

	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime* _speed;

	//탱크 방향에 맞는 이미지 셋팅 스위치
	switch (_direction)
	{
		case DIRECTION_LEFT:
			_image->setFrameX(0);
			_image->setFrameY(3);

			_x -= moveSpeed;

			rcCollision = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
		break;
		case DIRECTION_UP:
			_image->setFrameX(0);
			_image->setFrameY(0);

			_y -= moveSpeed;

			rcCollision = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
		break;
		case DIRECTION_RIGHT:
			_image->setFrameX(0);
			_image->setFrameY(2);

			_x += moveSpeed;

			rcCollision = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
		break;
		case DIRECTION_BOTTOM:
			_image->setFrameX(0);
			_image->setFrameY(1);

			_y += moveSpeed;

			rcCollision = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());
		break;
	
	}

	rcCollision.left += 2;
	rcCollision.top += 2;
	rcCollision.right -= 2;
	rcCollision.bottom -= 2;

	//Left, Top
	tileX = rcCollision.left / TILESIZE;
	tileY = rcCollision.top / TILESIZE;

	
	//타일 인덱스 검출용 스위치문
	switch (_direction)
	{
		case DIRECTION_LEFT:
			tileIndex[0] = tileX + (tileY * TILEX);
			tileIndex[1] = tileX + (tileY + 1) * TILEX;
		break;
		case DIRECTION_UP:
			tileIndex[0] = tileX + tileY * TILEX;
			tileIndex[1] = (tileX + 1) + tileY * TILEX;
		break;
		case DIRECTION_RIGHT:
			tileIndex[0] = (tileX + tileY * TILEX) + 1;
			tileIndex[1] = (tileX + (tileY + 1) * TILEX) + 1;
		break;
		case DIRECTION_BOTTOM:
			tileIndex[0] = (tileX + tileY * TILEX) + TILEX;
			tileIndex[1] = (tileX + 1 + tileY * TILEX) + TILEX;
		break;
	
	}

	for (int i = 0; i < 2; i++)
	{
		RECT rc;
		if (((_tankMap->getAttribute()[tileIndex[i]] & ATTR_UNMOVE) == ATTR_UNMOVE) &&
			IntersectRect(&rc, &_tankMap->getTile()[tileIndex[i]].rc, &rcCollision))
		{
			switch (_direction)
			{
				case DIRECTION_LEFT:
					_rc.left = _tankMap->getTile()[tileIndex[i]].rc.right;
					_rc.right = _rc.left + 30;

					_x = _rc.left + (_rc.right - _rc.left) / 2;
				break;
				case DIRECTION_UP:
					_rc.top = _tankMap->getTile()[tileIndex[i]].rc.bottom;
					_rc.bottom = _rc.top + 30;

					_y = _rc.top + (_rc.bottom - _rc.top) / 2;
				break;
				case DIRECTION_RIGHT:
					_rc.right = _tankMap->getTile()[tileIndex[i]].rc.left;
					_rc.left = _rc.right - 30;

					_x = _rc.left + (_rc.right - _rc.left) / 2;
				break;
				case DIRECTION_BOTTOM:
					_rc.bottom = _tankMap->getTile()[tileIndex[i]].rc.top;
					_rc.top = _rc.bottom - 30;

					_y = _rc.top + (_rc.bottom - _rc.top) / 2;
				break;
		
			}

			return;
		}
	}

	//멀티바이트 -> char -> 영어는 1byte 그외엔 2Byte 널값으로 문자열 끝을 알수있다
	//와이드바이트 -> (유니코드) -> 2바이트 유니코드 협약에 의해 
	//아스키코드  -> 미국꺼 -> 우리 방식에 니네가 맞춰라 꼬우면 쓰지말던가
	//Ameraican Standard Code 
	
	_rc = rcCollision;
	//렉트만 넣어놔도 움직인다 ㅋㅋㅋㅋ
	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

}


void tank::setTankPosition()
{
	_rc = _tankMap->getTile()[_tankMap->getPosFirst()].rc;

	_x = _rc.left + (_rc.right - _rc.left) / 2;
	_y = _rc.top + (_rc.bottom - _rc.top) / 2;
}
