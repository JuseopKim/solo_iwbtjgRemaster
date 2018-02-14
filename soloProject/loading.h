#pragma once
#include "gameNode.h"
#include "progressBar.h"

//================================================
// NAME : LOAD_KIND
//
// Desc : 로딩하는 리소스의 종류를 이넘으로 정의함
//================================================

enum LOAD_KIND
{
	LOAD_KIND_IMAGE_0,		//이미지 초기화에 따른 열거
	LOAD_KIND_IMAGE_1,
	LOAD_KIND_IMAGE_2,
	LOAD_KIND_FRAMEIMAGE_0,
	LOAD_KIND_FRAMEIMAGE_1,
	LOAD_KIND_SOUND,
	LOAD_KIND_END
};

//=================================================
// NAME : IMAGERESOURCE STRUCT
//
// Desc : 로딩할 이미지 정보
//=================================================

struct tagImageResource
{
	const char* sceneName;
	string keyName;
	const char* fileName;
	float x, y;
	int width, height;
	int frameX, frameY;
	bool trans;
	COLORREF transColor;
};

struct tagSoundResource
{
	const char* sceneName;
	string keyName;
	const char* fileName;
	bool bgm;
	bool loop;
};

class loadResource
{
private:
	LOAD_KIND _kind;
	tagImageResource _imageResource;
	tagSoundResource _soundResource;

public:

	HRESULT initImage(const char* sceneName, string keyName, int width, int height);
	HRESULT initImage(const char* sceneName, string keyName, const char* fileName, int width, int height, BOOL trans = FALSE, COLORREF transColor = FALSE);
	HRESULT initImage(const char* sceneName, string keyName, const char* fileName, float x, float y, int width, int height, BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT initFrameImage(const char* sceneName, string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);
	HRESULT initFrameImage(const char* sceneName, string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT initSound(const char* sceneName, string keyName, const char* fileName, bool bgm, bool loop);

	LOAD_KIND getLoadingKind() { return _kind; }

	tagImageResource getImageResource(void) { return _imageResource; }
	tagSoundResource getSoundResource(void) { return _soundResource; }

	void release();

	loadResource();
	~loadResource();
};

class loading : public gameNode
{
private:
	typedef vector<loadResource*> arrLoadResource;
	typedef vector<loadResource*>::iterator arrLoadResourceIter;

private:
	arrLoadResource _vLoadResource;
	image* _background;
	progressBar* _loadingBar;

	int _currentGauge;

	int _lastLoading;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void loadImage(const char* sceneName, string keyName, int width, int height);
	void loadImage(const char* sceneName, string keyName, const char* fileName, int width, int height, BOOL trans = FALSE, COLORREF transColor = FALSE);
	void loadImage(const char* sceneName, string keyName, const char* fileName, float x, float y, int width, int height, BOOL trans = FALSE, COLORREF transColor = FALSE);
	
	void loadFrameImage(const char* sceneName, string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);
	void loadFrameImage(const char* sceneName, string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);

	void loadSound(const char* sceneName, string keyName, const char* fileName, bool bgm, bool loop);

	void releaseResource(const char* sceneName);

	BOOL loadingDone();

	vector<loadResource*> getLoadItem() { return _vLoadResource; }

	loading();
	~loading();
};

