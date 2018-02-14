#pragma once
#include "gameNode.h"
//#include "mainNodeTestScene.h"

#include "loadScene.h"

#include "mainMenu.h"
#include "maptoolScene.h"

#include "inGameScene.h"
#include "worldmap.h"

class mainGame : public gameNode
{
private:
	//loadingScene;
		
public:
	virtual HRESULT init(void);	
	virtual void release(void);	
	virtual void update(void);	
	virtual void render(void);	

	void initImage();
	void initSound();
	
	mainGame();
	~mainGame();
};

