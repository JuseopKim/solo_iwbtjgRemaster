#pragma once
#include "gameNode.h"

class pixelCollisionTest : public gameNode
{
private:
	image* _hill;	//언덕배기 이미지
	image* _ball;	//공	 이미지

	RECT _rc;

	float _x, _y;
	int _probeY;	//Y 탐사축

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);




	pixelCollisionTest();
	~pixelCollisionTest();
};

