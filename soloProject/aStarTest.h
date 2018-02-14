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
	vector<tile*> _vTotalList;				//��Ż Ÿ��
	vector<tile*>::iterator _viTotalList;	

	vector<tile*> _vOpenList;				//���� �ִ� Ÿ��
	vector<tile*>::iterator _viOpenList;

	vector<tile*> _vCloseList;				//���� ����� Ÿ��
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

	//Ÿ�� ������ �Լ�
	void setTiles();

	//���� Ÿ�Ͽ��� ���� �ִ� �� ã�� �Լ�
	vector<tile*> addOpenList(tile* currentTile);
	//��� Ž�� �Լ�
	void pathFinder(tile* currentTile);

	void release();
	void update();
	void render();

};

