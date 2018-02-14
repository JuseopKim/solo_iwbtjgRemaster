#pragma once
#include "gameNode.h"
#include "loading.h"
class loadScene : public gameNode
{
private:
	loading* _loading;

	char* _nextScene;

public:
	HRESULT init();
	HRESULT init(char* scene);
	void release();
	void update();
	void render();

	void imageInit();
	void soundInit();

	loadScene();
	~loadScene();
};

