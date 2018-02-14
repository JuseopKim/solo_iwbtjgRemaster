#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* bulletImage;		//미싸일 이미지
	RECT rc;				//미싸일 충돌박스
	float x, y;				//미싸일 좌표
	float angle;			//미쏴일 앵글
	float radius;			//반지름
	float speed;			//속도
	float fireX, fireY;		//미싸일 발사시점 좌표
	bool fire;				//쐈어?
	int count;
};

//공용으로 사용하는 총알
class bullet : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	HRESULT init(const char* imageName, int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, float angle, float speed);

	void move(void);

	void draw(void);

	void removeBullet(int arrNum);

	vector<tagBullet> getVBullet(void) { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet(void) { return _viBullet; }

	bullet();
	~bullet();
};

//장전해놓고 쏘는 미쏼
class missile : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);

	void move(void);

	missile();
	~missile();
};

//쏠때 생성하는 미쏼
class sonicBoom : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	int _missileMax;
	float _range;

public:
	HRESULT init(int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y);

	void move(void);

	void removeMissile(int arrNum);

	//나중에 빅피쳐를 위한 게터세터
	vector<tagBullet> getVBullet(void) { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet(void) { return _viBullet; }

	sonicBoom();
	~sonicBoom();
};

//Public Frame Missile
class missilePF : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	HRESULT init(const char* imageName, int bulletMax, int range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, float angle, float speed);
	void move(void);
	void draw(void);

	vector<tagBullet> getVBullet(void) { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet(void) { return _viBullet; }

	missilePF();
	~missilePF();

};