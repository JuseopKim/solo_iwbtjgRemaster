#pragma once
#include "gameNode.h"
#include "tankMap.h"

enum TANKDIRECTION
{
	DIRECTION_LEFT,
	DIRECTION_UP,
	DIRECTION_RIGHT,
	DIRECTION_BOTTOM
};

class tank : public gameNode
{
private:
	tankMap* _tankMap;

	TANKDIRECTION _direction;

	image* _image;
	RECT _rc;

	float _x, _y;
	float _speed;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void tankMove();

	void setTankPosition();

	void setTankMapAddressLink(tankMap* tm) { _tankMap = tm; }

	tank();
	~tank();
};

