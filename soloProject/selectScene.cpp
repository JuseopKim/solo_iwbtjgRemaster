#include "stdafx.h"
#include "selectScene.h"


selectScene::selectScene()
{
}


selectScene::~selectScene()
{

}

HRESULT selectScene::init()
{
	_btnSceneChange = new button;
	_btnSceneChange->init("º¸Æ°", WINSIZEX / 2, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), cbSceneChange);

	//_action = new action;
	//_action->init();

	_actionImage = IMAGEMANAGER->findImage("RÆÄÄ«");
	_actionImage->setX(100);
	_actionImage->setY(100);

	//_cbAction = _action;
	//_cbImage = _actionImage;

	//_action->moveTo(_actionImage, 500, 500, 10.0f);
	//_action->moveTo(_actionImage, 500, 500, 5.0f, cbAction);

	_btnAngleDown = new button;
	_btnAngleDown->init("º¸Æ°", WINSIZEX / 2 - 200, WINSIZEY / 2 + 200,
		PointMake(0, 1), PointMake(0, 0), cbAngleDown);

	_btnAngleUp = new button;
	_btnAngleUp->init("º¸Æ°", WINSIZEX / 2 + 200, WINSIZEY / 2 + 200,
		PointMake(0, 1), PointMake(0, 0), cbAngleUp);

	return S_OK;
}

void selectScene::release()
{

}

void selectScene::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("½ºÅ¸¾À");
	}

	_btnSceneChange->update();
	//_action->update();

	_btnAngleDown->update();
	_btnAngleUp->update();
}

void selectScene::render() 
{
	_btnSceneChange->render();
	//_actionImage->render(getMemDC());

	_btnAngleDown->render();
	_btnAngleUp->render();

	char str[128];

	sprintf(str, "¼¿·ºÆ® ¾À");
	TextOut(getMemDC(), WINSIZEX / 2, 100, str, strlen(str));

}

void selectScene::cbSceneChange(void)
{
	SCENEMANAGER->changeScene("½ºÅ¸¾À");
}

void selectScene::cbAction()
{
	_cbAction->moveTo(_cbImage, 100, 100, 3.0f);
}

void selectScene::cbAngleUp()
{
	DATABASE->setElementDataAngle("battle", DATABASE->getElementData("battle")->angle += 0.2f);
}

void selectScene::cbAngleDown()
{
	DATABASE->setElementDataAngle("battle", DATABASE->getElementData("battle")->angle -= 0.2f);
}