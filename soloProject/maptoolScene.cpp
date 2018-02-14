#include "stdafx.h"
#include "maptoolScene.h"

maptoolScene::maptoolScene(){}
maptoolScene::~maptoolScene(){}

HRESULT maptoolScene::init()
{
	_check = 0;
	_showTile = false;
	_showTileIndex = 0;

	imagesetup();
	palettSetup();

	_cameraX = _cameraY = 0;

	//그 - 리 - 드
	for (int i = 0; i < GRIDNUM; i++)
	{
		int x = (i % GRIDX) * TILESIZE;
		int y = (i / GRIDY) * TILESIZE;

		_mapRect[i].x = x;
		_mapRect[i].y = y;

		_mapRect[i].index = i;
		_mapRect[i].empty = true;
		_mapRect[i].rc = RectMake(x, y, TILESIZE, TILESIZE);
	}

	//팔레트 포-오쓰!
	int palPosX = _mapRect[GRIDX].rc.left;
	int palPosY = _mapRect[GRIDY].rc.top;

	//팔레트 렉-트!
	for (int i = 0; i < PALETTENUM; i++)
	{
		int x = (i % PALETTEX);
		int y = (i / PALETTEY);

		_paletRect[i].x = x;
		_paletRect[i].y = y;

		_paletRect[i].index = i;
		_paletRect[i].rc = RectMake(x + TILESIZE + palPosX + x,
									y * TILESIZE + palPosY + y,
									TILESIZE, TILESIZE);
	}

	//와! 몇번째 페이지?
	_paletPage = 0;

	//모드들
	_inputMode = MODE_FLOOR;
	_inputLayer = LAYER_TILE;
	_paletMode = MODE_TILE;

	//버튼들
	_buttonRect[0].rc = RectMake(0, 0, 0, 0);
	return S_OK;
}

void maptoolScene::release()
{

}

void maptoolScene::update()
{

}

void maptoolScene::render()
{

}

void maptoolScene::imagesetup()
{

}

void maptoolScene::palettSetup()
{

}

void maptoolScene::input()
{

}

void maptoolScene::input_ModeChange()
{

}

void maptoolScene::input_SelectMapGrid()
{

}

void maptoolScene::input_AddTile()
{

}

void maptoolScene::input_ClickPalet()
{

}

void maptoolScene::inPut_ClickButten()
{

}

void maptoolScene::cameraMove(int x, int y)
{

}

void maptoolScene::save()
{

}

void maptoolScene::load()
{

}
