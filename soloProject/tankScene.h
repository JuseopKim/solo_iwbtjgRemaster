#pragma once
#include "gameNode.h"
#include "tank.h"
#include "tankMap.h"

class tankScene : public gameNode
{
private:
	tank* _tank;
	tankMap* _tankMap;

public:
	HRESULT init();
	void release();
	void update();
	void render();


	tankScene();
	~tankScene();
};

