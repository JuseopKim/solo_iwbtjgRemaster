#include "stdafx.h"
#include "loadScene.h"

loadScene::loadScene(){}
loadScene::~loadScene(){}

HRESULT loadScene::init()
{
	_loading = new loading;
	_loading->init();


	imageInit();
	soundInit();

	_nextScene = "main";

	return S_OK;
}

HRESULT loadScene::init(char* scene)
{
	_loading->releaseResource(SCENEMANAGER->getCurrentScene());

	_nextScene = scene;

	if (strcmp(_nextScene, "main") == 0)
	{
		_loading->loadImage(_nextScene, "main_title", "image//main//title.bmp", 446, 150, true, RGB(255, 0, 255));
		_loading->loadSound(_nextScene, "01.main", "sound//43013.ogg", true, true);
	}
	else if (strcmp(_nextScene, "mapEdit") == 0)
	{

	}
	else if (strcmp(_nextScene, "worldMap") == 0)
	{

	}
	else if (strcmp(_nextScene, "1"))
	{

	}

	return S_OK;
}

void loadScene::release(){}

void loadScene::update()
{
	_loading->update();

	if (_loading->loadingDone())
	{
		//SCENEMANAGER->changeScene()
	}
}

void loadScene::render()
{
	_loading->render();
}

void loadScene::imageInit()
{
	_loading->loadImage("6stage", "bg_block", "image//bgBack//backBlock.bmp", 1024, 768, true, RGB(255, 0, 255));
	_loading->loadImage("2stage", "bg_mountin", "image//bgBack//backMountin.bmp", 1024, 768, true, RGB(255, 0, 255));
	_loading->loadImage("town", "bg_city", "image//bgBack//city.bmp", 1286, 768, true, RGB(255, 0, 255));
	_loading->loadImage("3stage", "bg_cave", "image//bgBack//cave.bmp", 1193, 768, true, RGB(255, 0, 255));
	_loading->loadImage("8stage", "bg_corridor", "image//bgBack//corridor.bmp", 1591, 768, true, RGB(255, 0, 255));
	_loading->loadImage("4stage", "bg_waterside", "image//bgBack//waterside2.bmp", 1295, 768, true, RGB(255, 0, 255));
	_loading->loadImage("4stage", "bg_waterside_long", "image//bgBack//waterside.bmp", 2613, 768, true, RGB(255, 0, 255));
	_loading->loadImage("8stage", "bg_palace", "image//bgBack//palace.bmp", 1296, 768, true, RGB(255, 0, 255));
	_loading->loadImage("6stage", "bg_starNight", "image//bgBack//nightstar.bmp", 1275, 768, true, RGB(255, 0, 255));
	_loading->loadImage("7stage", "bg_night", "image//bgBack//night.bmp", 1024, 768, true, RGB(255, 0, 255));
	_loading->loadImage("7stage", "bg_deusRoom", "image//bgBack//bossDeus.bmp", 1277, 768, true, RGB(255, 0, 255));

}

void loadScene::soundInit()
{

}