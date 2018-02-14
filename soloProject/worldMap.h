#pragma once
#include "gameNode.h"
enum STAGE
{
	STAGE_MANSION,
	STAGE_
};

class worldMap : public gameNode
{
	int _currentStage;
	int _mode;
	int _myType;

	RECT _stage[9];
	RECT _butten[4];

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void imageinit();
	void butteninit();
		
	int getStage() { return _currentStage; }


	worldMap();
	~worldMap();
};

