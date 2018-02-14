#include "stdafx.h"
#include "animationTest.h"


animationTest::animationTest()
{
}


animationTest::~animationTest()
{

}

HRESULT animationTest::init()
{
	_camel = IMAGEMANAGER->addFrameImage("��Ÿ", "camel.bmp", 300, 267, 4, 3, true, RGB(255, 0, 255));

	//����Ʈ �ִϸ��̼�
	_ani1 = new animation;
	_ani1->init(_camel->getWidth(), _camel->getHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani1->setDefPlayFrame(true, true);
	_ani1->setFPS(1);

	//�迭 �ִϸ��̼�
	int arrAni[] = { 1, 10, 6, 3, 2 };
	_ani2 = new animation;
	_ani2->init(_camel->getWidth(), _camel->getHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani2->setPlayFrame(arrAni, 5, false);
	_ani2->setFPS(1);

	//���� �ִϸ��̼�
	_ani3 = new animation;
	_ani3->init(_camel->getWidth(), _camel->getHeight(), _camel->getFrameWidth(), _camel->getFrameHeight());
	_ani3->setPlayFrame(2, 8, false, true);
	_ani3->setFPS(1);

	return S_OK;
}

void animationTest::release()
{

}

void animationTest::update() 
{
	if (KEYMANAGER->isOnceKeyDown('Q')) _ani1->start();
	if (KEYMANAGER->isOnceKeyDown('W')) _ani2->start();
	if (KEYMANAGER->isOnceKeyDown('E')) _ani3->start();

	_ani1->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_ani2->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_ani3->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);

}

void animationTest::render() 
{
	_camel->aniRender(getMemDC(), 100, 200, _ani1);
	_camel->aniRender(getMemDC(), 200, 200, _ani2);
	_camel->aniRender(getMemDC(), 300, 200, _ani3);
}
