#include "stdafx.h"
#include "mainNodeTestScene.h"


mainNodeTestScene::mainNodeTestScene()
{
}


mainNodeTestScene::~mainNodeTestScene()
{

}

HRESULT mainNodeTestScene::init()
{
	gameNode::init();


	_nt1 = new nodeTest1;
	_nt1->init();

	_nt2 = new nodeTest2;
	_nt2->init();

	addChild(_nt1);
	addChild(_nt2);


	return S_OK;
}

void mainNodeTestScene::release()
{

}

void mainNodeTestScene::update() 
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) removeChild(_nt1);
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON)) removeChild(_nt2);

}

void mainNodeTestScene::render() 
{
	gameNode::render();

}
