#include "stdafx.h"
#include "mainMenu.h"

mainMenu::mainMenu(){}
mainMenu::~mainMenu(){}

HRESULT mainMenu::init()
{
	imageinit();
	butteninit();

	//프레임 이동용 렉트 초기화
	_cloudLoopRect = RectMake(0, 50, 1024, 410);
	_bgLoopRect = RectMake(0, 0, 1024, 768);

	//arr init
	for (int i = 0; i < 6; i++)
	{
		_fps[i] = 0;
		//실수로 1번 프레임에 비활성 상태를 집어넣어서 1번으로 초기화
		_buttenFrame[i] = 1;
		_optionFrame[i] = 1;
	}

	//프레임 변수 초기화
	_cloudMove = 0;
	_frameX = 0;
	_bgMove = 0;

	//기타 초기화
	_clear = false;
	_charactor = IMAGEMANAGER->findImage("ma_guy2");

	_option = false;
	_load = false;
	_keyconfig = false;
	//on
	_bgm = true;

	//default
	_portlaits = true;

	_loadGame = false;
	//_saveSlot = false;

	return S_OK;
}

void mainMenu::release(){}

void mainMenu::update()
{
	//맵툴 진입
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("03.mapToolScene");

	//게임 클리어 여부에 따라 서있는 캐릭터가 달라짐
	if (!_clear) _charactor = IMAGEMANAGER->findImage("ma_guy2");
	else _charactor = IMAGEMANAGER->findImage("ma_guy1");

	//캐릭터 변경 테스트
	if (KEYMANAGER->isStayKeyDown('Q')) _clear = true;

	_fps[1]++;
	//구름을 움직이는 프레임
	if (_fps[1] >= 10)
	{
		_cloudMove++;
		_fps[1] = 0;
		_fps[2]++;
		_frameX++;

	}
	//배경을 움직이는 프레임
	if (_fps[2] >= 3)
	{
		_bgMove++;
		_fps[2] = 0;
	}
	//캐릭터 프레임이 다 돌면 다시 0으로
	if (_frameX >= _charactor->getMaxFrameX()) _frameX = 0;

	for (int i = 0; i < 5; i++)
	{
		if (PtInRect(&_butten[i], _ptMouse) && !_option && !_load)
		{
			_buttenFrame[i] = 0;
			if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON))
			{
				switch (i)
				{
					//뉴게임
				case 1:
					_loadGame = false;
					SCENEMANAGER->changeScene("02.inGameScene");

					break;

					//옵션
				case 2: _option = true; break;

					//로드 게임
				case 3: 
					_load = true;
					_loadGame = true;
					break;

					//나가기
				case 4: PostQuitMessage(0);break;

					//디폴트
				default: PostQuitMessage(0); break;
				}
			}
		}
		else if (PtInRect(&_loadButten[i], _ptMouse) && _option)
		{
			_buttenFrame[i] = 0;
			if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON))
			{
				switch (i)
				{
				case 1:
					if (!_bgm) _portlaits = true;
					else _portlaits = false;
					break;
				case 2:
					if (!_bgm) _bgm = true;
					else _bgm = false;
					break;
				default: _option = false; break;
				}
			}
		}
		else if (PtInRect(&_loadButten[i], _ptMouse) && _load)
		{
			_buttenFrame[i] = 0;
			_loadGame = true;
			SCENEMANAGER->changeScene("02.inGameScene");
			//게임씬으로 넘어간다.
		}
		else _buttenFrame[i] = 1;
	}

	if (PtInRect(&_back, _ptMouse) && (_option || _load))
	{
		_buttenFrame[5] = 0;
		if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON))
		{
			_load = false;
			_option = false;
		}
	}
	else _buttenFrame[5] = 1;
}

void mainMenu::render()
{
	IMAGEMANAGER->findImage("bg_night")->loopRender(getMemDC(), &_bgLoopRect, _bgMove, 0);
	IMAGEMANAGER->findImage("fg_cloud")->loopRender(getMemDC(), &_cloudLoopRect,_cloudMove, 0);
	
	IMAGEMANAGER->findImage("rock")->render(getMemDC(), 0, WINSIZEY - 174);
	
	IMAGEMANAGER->findImage("ma_castle")->render(getMemDC(), 600, 75);

	_charactor->frameRender(getMemDC(), 170, 330, _frameX, 0);

	IMAGEMANAGER->findImage("title")->render(getMemDC(), (WINSIZEX - 446) - 75, 120);

	//Rectangle(getMemDC(), _back.left, _back.top, _back.right, _back.bottom);

	if (!_option && !_load)
		for (int i = 0; i < 5; i++) 
			IMAGEMANAGER->findImage("ma_butten")->frameRender(getMemDC(), _butten[i].left, _butten[i].top, _buttenFrame[i], i - 1);
	
	else if (_option)
	{
		for (int i = 0; i < 3; i++)
		{
			IMAGEMANAGER->findImage("option")->frameRender(getMemDC(), _loadButten[i].left, _loadButten[i].top, _buttenFrame[i], i - 1);
		}
		IMAGEMANAGER->findImage("onoff")->frameRender(getMemDC(), 850 + 75, 480, 0, !_bgm);
		IMAGEMANAGER->findImage("option_portlaits")->frameRender(getMemDC(), 850 + 75, 415, 0, !_portlaits);

		IMAGEMANAGER->findImage("main_back")->frameRender(getMemDC(), _back.left, _back.top, _buttenFrame[5], 0);
	}
}


void mainMenu::imageinit()
{
	IMAGEMANAGER->addImage("bg_night", "image//bgBack//night.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_cloud", "image//bgFront//cloud.bmp", 1024, 410, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("rock", "image//main//rock.bmp", 364, 174, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("title", "image//main//title.bmp", 446, 150, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("ma_guy1", "image//main//charactor.bmp", 1104, 308, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ma_guy2", "image//main//charactor2.bmp", 1104, 334, 8, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("ma_castle", "image//main//castle.bmp", 370, 483, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("ma_butten", "image//main//butten.bmp", 246, 92, 2, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("option", "image//main//option.bmp", 240, 69, 2, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("option_keyConfig", "image//main//keyconfig.bmp", 89, 240, 1, 9, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("saveSlot", "image//main//load.bmp", 234, 57, 2, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("option_portlaits", "image//main//portlaits.bmp", 164, 48, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("onoff", "image//main//onoff.bmp", 74, 36, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("main_back", "image//ui//back.bmp", 106, 19, 2, 1, true, RGB(255, 0, 255));
}

void mainMenu::butteninit()
{
	//none option butten
	_butten[1] = RectMake(680, 350, 123, 23);
	_butten[2] = RectMake(720, 415, 123, 23);
	_butten[3] = RectMake(760, 480, 123, 23);
	_butten[4] = RectMake(800, 545, 123, 23);

	//_back = RectMake(WINSIZEX - 74, WINSIZEY - 36, 37, 18);
	_back = RectMake(WINSIZEX - 74, WINSIZEY - 36, 53, 18);

	_loadButten[1] = RectMake(760, 415, 120, 23);
	_loadButten[2] = RectMake(760, 480, 120, 23);
	_loadButten[3] = RectMake(760, 545, 120, 23);
}