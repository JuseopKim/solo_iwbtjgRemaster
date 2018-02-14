#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

//상호참조를 하기 위한 전방선언
class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;
	missile* _missile;
	sonicBoom* _sonicBoom;
	enemyManager* _em;

	progressBar* _hpBar;
	float _maxHP, _currentHP;

	int _alphaValue;

public:
	virtual HRESULT init(void);	
	virtual void release(void);	
	virtual void update(void);	
	virtual void render(void);	

	void collision(void);

	void setEnemyManagerAddressLink(enemyManager* em) { _em = em; }

	void hitDamage(float damage);

	sonicBoom* getSonicBoom() { return _sonicBoom; }

	image* getShipImage() { return _ship; }

	spaceShip();
	~spaceShip();
};

