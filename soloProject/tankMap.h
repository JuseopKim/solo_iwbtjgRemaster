#pragma once
#include "tileNode.h"
#include "gameNode.h"

class tankMap : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];
	DWORD _attribute[TILEX * TILEY]; //Ÿ�ϼӼ�

	int _pos[2];

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//�������� �׸� �� �ε��Լ�
	void load();

	//Ÿ�� �Ӽ� ������ ����� 2��°

	//Ÿ�� ���� ������
	tagTile* getTile() { return _tiles; }
	DWORD* getAttribute() { return _attribute; }

	//1p, 2p ������ 
	int getPosFirst() { return _pos[0]; }
	int getPosSecond() { return _pos[1]; }

	tankMap();
	~tankMap();
};

