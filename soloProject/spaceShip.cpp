#include "stdafx.h"
#include "spaceShip.h"
#include "enemyManager.h"

spaceShip::spaceShip()
{
}


spaceShip::~spaceShip()
{

}

HRESULT spaceShip::init(void)
{
	_ship = IMAGEMANAGER->addImage("¿ìÁÖ¼±", "rocket.bmp", 52, 64, true, RGB(255, 0, 255));
	_ship->setX(WINSIZEX / 2 - (_ship->getWidth() / 2));
	_ship->setY(WINSIZEY / 2 + 200);

	_missile = new missile;
	_missile->init(30, 400);

	_sonicBoom = new sonicBoom;
	_sonicBoom->init(3000, 500);

	_currentHP = _maxHP = 100;

	_hpBar = new progressBar;
	_hpBar->init(_ship->getX(), _ship->getY() - 15, 53, 5);
	_hpBar->setGauge(_currentHP, _maxHP);

	_alphaValue = 255;

	return S_OK;
}

void spaceShip::release(void)
{

}

void spaceShip::update(void) 
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _ship->getX() > 0)
	{
		_ship->setX(_ship->getX() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _ship->getX() + _ship->getWidth() < WINSIZEX)
	{
		_ship->setX(_ship->getX() + 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && _ship->getY() > 0)
	{
		_ship->setY(_ship->getY() - 5);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _ship->getY() + _ship->getHeight() < WINSIZEY)
	{
		_ship->setY(_ship->getY() + 5);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) _missile->fire(_ship->getCenterX(), _ship->getY() - 15);
	if (KEYMANAGER->isOnceKeyDown('X')) _sonicBoom->fire(_ship->getCenterX(), _ship->getY() - 10);

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		char temp[128];
		vector<string> vStr;

		vStr.push_back(itoa(_currentHP, temp, 10));
		vStr.push_back(itoa(_maxHP, temp, 10));
		vStr.push_back(itoa(_ship->getX(), temp, 10));
		vStr.push_back(itoa(_ship->getY(), temp, 10));

		TXTDATA->txtSave("IotaSave.txt", vStr);

	}

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		vector<string> vStr;

		vStr = TXTDATA->txtLoad("IotaSave.txt");

		_currentHP = (atoi(vStr[0].c_str()));
		_maxHP = (atoi(vStr[1].c_str()));
		_ship->setX(atoi(vStr[2].c_str()));
		_ship->setY(atoi(vStr[3].c_str()));

	}



	_missile->update();
	_sonicBoom->update();

	_hpBar->setX(_ship->getX());
	_hpBar->setY(_ship->getY() - 15);
	_hpBar->setGauge(_currentHP, _maxHP);

	_hpBar->update();

	collision();

	_alphaValue--;

	if (_alphaValue <= 0) _alphaValue = 255;

}

void spaceShip::render(void) 
{
	_ship->alphaRender(getMemDC(), _alphaValue);
	_missile->render();
	_sonicBoom->render();
	_hpBar->render();
}

void spaceShip::collision(void)
{
	for (int i = 0; i < _sonicBoom->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_sonicBoom->getVBullet()[i].rc,
				&_em->getVMinion()[j]->getRect()))
			{
				_sonicBoom->removeMissile(i);
				_em->removeMinion(j);
				break;
			}
		}
	}
}

void spaceShip::hitDamage(float damage)
{
	_currentHP -= damage;

}