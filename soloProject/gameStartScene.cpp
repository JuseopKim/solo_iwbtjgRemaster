#include "stdafx.h"
#include "gameStartScene.h"


gameStartScene::gameStartScene()
{
}


gameStartScene::~gameStartScene()
{

}

HRESULT gameStartScene::init()
{

	return S_OK;
}

void gameStartScene::release()
{

}

void gameStartScene::update() 
{

}

void gameStartScene::render() 
{
	IMAGEMANAGER->findImage("·ÑÇù°î0")->render(getMemDC(), 0, 0);
}
