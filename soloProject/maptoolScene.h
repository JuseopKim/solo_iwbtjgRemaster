#pragma once
#include "gameNode.h"
#include <list>

#define TILESIZE 32

#define TILEXMAX 128
#define TILEYMAX 128
#define TILEMAX TILEXMAX * TILEYMAX

#define GRIDX 1
#define GRIDY 1
#define GRIDNUM GRIDX*GRIDY

#define PALETTEX 1
#define PALETTEY 1
#define PALETTENUM PALETTEX * PALETTEY

#define BUTTENMAX 20

enum LAYER
{
	LAYER_TILE,
	LAYER_DECO,
	LAYER_OBJECT,
	LAYER_ITEM,
	LAYER_NPC,
	LAYER_ENEMY
};

enum INPUTMODE
{
	MODE_NULL,

	//TREEAIN
	MODE_FLOOR, MODE_WATER, MODE_LIGHT,
	MODE_TRAP, MODE_DOWNABLE,

	//OBJECT
	MODE_CHEST,
	MODE_START, MODE_END,

	MODE_MOREITME,

	MODE_GRAVE, MODE_TUBE,
	MODE_CHANDELIER,
	MODE_SEWER,
	
	MODE_SAVE_POINT,

	MODE_DOOR,
	MODE_LADDER,

	MODE_CHAIR, MODE_PILLAR,

	MODE_VIEWING,
	MODE_VIEWINGTILE,

	MODE_DELET
};

enum PALETTEMODE
{
	MODE_TILE,
	MODE_DECO,

	MODE_BACKGROUND,
	MODE_FRONTGROUND,

	MODE_OBJECT,
	MODE_NPC,
	MODE_ENEMY
};

class maptoolScene : public gameNode
{
	typedef vector<GRID> vGrid;
	typedef vector<GRID>::iterator viGrid;

	typedef vector<TILE> vTile;
	typedef vector<TILE>::iterator viTile;

	typedef vector<SELTILE> vSelTile;
	typedef vector<SELTILE>::iterator viSelTile;

	typedef	vector<OBJ> vObj;
	typedef vector<OBJ>::iterator viObj;

private:
	int _mapStage;

	RECT _backGroundRect;

	RECT _mapToolMiniMap;
	RECT _miniMapCam;

	bool _leftClicking;
	vector<string> _backImgNameList;
	vector<image*> _backImgList;

	vector<string> _imgNameList;
	vector<image*> _imgList;

	vector<string> _imgNameListEnemy;
	vector<image*> _imgListEnemy;

	RECT _selectRangeRect;
	POINT _selectRangePoint;

	vGrid _vMapSelect;
	viGrid _viMapSelect;
	GRID _mapRect[GRIDNUM];

	vTile _vMapTile;
	viTile _viMapTile;

	vTile _vDecoTile;
	viTile _viDecoTile;

	vObj _vObj;
	viObj _viObj;

	vTile _vItem;
	viTile _viItem;

	vTile _vNpc;
	viTile _viNpc;

	vTile _vEnemy;
	viTile _viEnemy;

	vTile _vPaletTile;
	viTile _viPaletTile;

	vSelTile _vPaletSel;
	viSelTile _viPaletSel;

	GRID _paletRect[PALETTNUM];

	int _paletPage;

	bool _showTile;
	int _showTileIndex;

	int _check;

	vTile _vCopyTile;
	viTile _viCopyTile;

	INPUTMODE _inputMode;
	LAYER _inputLayer;
	PALETTEMODE _paletMode;

	vector<RECT> _tileButten;

	BUTTEN _buttonRect[BUTTENMAX];

	float _inpCountDown;

	int _cameraX, _cameraY;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void imagesetup();
	void palettSetup();

	void input();

	void input_ModeChange();
	void input_SelectMapGrid();
	void input_AddTile();
	void input_ClickPalet();
	void inPut_ClickButten();

	void cameraMove(int x, int y);

	void save();
	void load();

	maptoolScene();
	~maptoolScene();
};

