#include "stdafx.h"
#include "aStarScene.h"


aStarScene::aStarScene()
{
}


aStarScene::~aStarScene()
{

}

HRESULT aStarScene::init(void)
{
	_aStar = new aStarTest;
	_aStar->init();

	return S_OK;
}

void aStarScene::release(void)
{

}

void aStarScene::update(void) 
{
	_aStar->update();
}

void aStarScene::render(void) 
{
	_aStar->render();
}
