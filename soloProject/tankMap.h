#pragma once
#include "tileNode.h"
#include "gameNode.h"

class tankMap : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];
	DWORD _attribute[TILEX * TILEY]; //타일속성

	int _pos[2];

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//맵툴에서 그린 맵 로드함수
	void load();

	//타일 속성 접근자 만든다 2번째

	//타일 정보 접근자
	tagTile* getTile() { return _tiles; }
	DWORD* getAttribute() { return _attribute; }

	//1p, 2p 포지션 
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	tankMap();
	~tankMap();
};

