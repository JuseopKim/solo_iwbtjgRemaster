#include "stdafx.h"
#include "tankScene.h"


tankScene::tankScene()
{
}


tankScene::~tankScene()
{

}

HRESULT tankScene::init()
{
	_tankMap = new tankMap;
	_tankMap->init();

	_tank = new tank;
	_tank->init();
	_tank->setTankMapAddressLink(_tankMap);
	_tank->setTankPosition();

	return S_OK;
}

void tankScene::release()
{

}

void tankScene::update() 
{
	_tank->update();
	_tankMap->update();
}

void tankScene::render() 
{
	
	_tankMap->render();
	_tank->render();
}
