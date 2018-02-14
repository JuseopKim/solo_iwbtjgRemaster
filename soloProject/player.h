#pragma once
#include "gameNode.h"

enum CHARACTORTYPE
{
	TYPE_IWBTBG,
	TYPE_IWBTTT,

	TYPE_END
};

class player : public gameNode
{
	int _type;

	tagPlayerInfo _playerinfo;

	int _currentFrameX,
		_currentFrameY;


public:
	HRESULT init();
	void release();
	void update();
	void render();

	player();
	~player();
};

