#pragma once
#include "gameNode.h"

class pixelCollisionTest : public gameNode
{
private:
	image* _hill;	//������ �̹���
	image* _ball;	//��	 �̹���

	RECT _rc;

	float _x, _y;
	int _probeY;	//Y Ž����

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);




	pixelCollisionTest();
	~pixelCollisionTest();
};

