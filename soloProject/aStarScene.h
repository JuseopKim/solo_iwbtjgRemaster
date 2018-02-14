#pragma once
#include "gameNode.h"
#include "aStarTest.h"

class aStarScene : public gameNode
{
private:
	aStarTest* _aStar;
public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	aStarScene();
	~aStarScene();
};

