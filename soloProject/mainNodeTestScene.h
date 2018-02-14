#pragma once
#include "gameNode.h"
#include "nodeTest1.h"
#include "nodeTest2.h"

class mainNodeTestScene : public gameNode
{
private:
	nodeTest1* _nt1;
	nodeTest2* _nt2;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	mainNodeTestScene();
	~mainNodeTestScene();
};

