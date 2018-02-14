#pragma once
#include "gameNode.h"

class gameStartScene : public gameNode
{
public:
	HRESULT init();
	void release();
	void update();
	void render();


	gameStartScene();
	~gameStartScene();
};

