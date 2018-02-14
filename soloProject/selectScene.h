#pragma once
#include "gameNode.h"
#include "button.h"
#include "action.h"

static image* _cbImage = NULL;
static action* _cbAction = NULL;

class selectScene : public gameNode
{
private:
	button* _btnSceneChange;

	action* _action;
	image* _actionImage;

	button* _btnAngleUp;
	button* _btnAngleDown;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	static void cbSceneChange(void);

	static void cbAction();
	static void cbAngleUp();
	static void cbAngleDown();


	selectScene();
	~selectScene();
};

