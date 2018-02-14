#pragma once
#include "gameNode.h"
#include "tile.h"
#include <vector>
#include <string>

#define TILEWIDTH 32
#define TILEHEIGHT 32

#define TILENUMX (WINSIZEX / TILEWIDTH)
#define TILENUMY (WINSIZEY / TILEHEIGHT)

class aStarTest : public gameNode
{
private:
	vector<tile*> _vTotalList;				//토탈 타일
	vector<tile*>::iterator _viTotalList;	

	vector<tile*> _vOpenList;				//갈수 있는 타일
	vector<tile*>::iterator _viOpenList;

	vector<tile*> _vCloseList;				//가장 가까운 타일
	vector<tile*>::iterator _viCloseList;

	tile* _startTile;
	tile* _endTile;
	tile* _currentTile;

	int _count;
	bool _start;

public:
	aStarTest();
	~aStarTest();

	HRESULT init();

	//타일 셋팅할 함수
	void setTiles();

	//현재 타일에서 갈수 있는 길 찾는 함수
	vector<tile*> addOpenList(tile* currentTile);
	//경로 탐색 함수
	void pathFinder(tile* currentTile);

	void release();
	void update();
	void render();

};

