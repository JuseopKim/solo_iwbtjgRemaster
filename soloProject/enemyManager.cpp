#include "stdafx.h"
#include "enemyManager.h"
#include "spaceShip.h"

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{

}

HRESULT enemyManager::init(void)
{
	_bullet = new bullet;
	_bullet->init("bullet", 30, 700);

	return S_OK;
}

void enemyManager::release(void)
{

}

void enemyManager::update(void)	
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->update();
	}

	collision();

	_bullet->update();
	minionBulletFire();

}

void enemyManager::render(void)	
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		(*_viMinion)->render();
	}

	_bullet->render();
}


void enemyManager::setMinion(void)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			enemy* ufo;
			ufo = new minion;
			ufo->init("enemy", PointMake(80 + j * 80, 80 + i * 100));

			_vMinion.push_back(ufo);
		}
	}
}


void enemyManager::minionBulletFire(void)
{
	for (_viMinion = _vMinion.begin(); _viMinion != _vMinion.end(); ++_viMinion)
	{
		if ((*_viMinion)->bulletCountFire())
		{
			RECT rc = (*_viMinion)->getRect();

			//_bullet->fire(rc.left + (rc.right - rc.left) / 2,
			//	rc.bottom + 5,
			//	-(PI / 2), 7.0f);

			_bullet->fire(rc.left + (rc.right - rc.left) / 2,
				rc.bottom + 5,
				getAngle(rc.left + (rc.right - rc.left) / 2,
				rc.top + (rc.bottom - rc.top) / 2,
				_ship->getShipImage()->getCenterX(),
				_ship->getShipImage()->getY()), 7.0f);
		}
	}
}

void enemyManager::removeMinion(int arrNum)
{
	SAFE_DELETE(_vMinion[arrNum]);
	_vMinion.erase(_vMinion.begin() + arrNum);
}

void enemyManager::collision(void)
{
	for (int i = 0; i < _bullet->getVBullet().size(); i++)
	{
		RECT rc;
		if (IntersectRect(&rc, &_bullet->getVBullet()[i].rc,
			&RectMake(_ship->getShipImage()->getX(),
			_ship->getShipImage()->getY(),
			_ship->getShipImage()->getWidth(),
			_ship->getShipImage()->getHeight())))
		{
			_ship->hitDamage(10.0);
			_bullet->removeBullet(i);
			break;
		}
	}
}