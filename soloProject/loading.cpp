#include "stdafx.h"
#include "loading.h"

loadResource::loadResource(){}
loadResource::~loadResource(){}

//리소스를 본격적으로 로딩해서 구조체에 담아서 메니저에 넘겨준다.
//헤당 리소슬르 매니저에 넘겨주는것은 loadingDone이 한다.

HRESULT loadResource::initImage(const char* sceneName, string keyName, int width, int height)
{
	_kind = LOAD_KIND_IMAGE_0;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.sceneName = sceneName;
	_imageResource.keyName = keyName;
	_imageResource.width = width;
	_imageResource.height = height;

	return S_OK;
}

HRESULT loadResource::initImage(const char* sceneName, string keyName, const char* fileName, int width, int height, BOOL trans, COLORREF transColor)
{
	_kind = LOAD_KIND_IMAGE_1;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.sceneName = sceneName;
	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = trans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadResource::initImage(const char* sceneName, string keyName, const char* fileName, float x, float y, int width, int height,
	BOOL trans, COLORREF transColor)
{
	_kind = LOAD_KIND_IMAGE_2;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.sceneName = sceneName;
	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = trans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadResource::initFrameImage(const char* sceneName, string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	_kind = LOAD_KIND_FRAMEIMAGE_0;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.sceneName = sceneName;
	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = trans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadResource::initFrameImage(const char* sceneName, string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	_kind = LOAD_KIND_FRAMEIMAGE_1;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.sceneName = sceneName;
	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = trans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadResource::initSound(const char* sceneName, string keyName, const char* fileName, bool bgm, bool loop)
{
	_kind = LOAD_KIND_SOUND;

	_soundResource.sceneName = sceneName;
	_soundResource.keyName = keyName;
	_soundResource.fileName = fileName;
	_soundResource.bgm = bgm;
	_soundResource.loop = loop;

	return S_OK;
}

void loadResource::release()
{
	if (_kind == LOAD_KIND_END) return;
	else if (_kind == LOAD_KIND_SOUND) SAFE_RELEASE(*SOUNDMANAGER->findSound(_soundResource.keyName));
}

loading::loading(){}
loading::~loading(){}

HRESULT loading::init()
{
	//이미지를 바꿀것
	_background = IMAGEMANAGER->addImage("bg_loading", "image//bgBack//loading.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	//이미지 자동으로 정렬되니 bmp는 안적어도 된다.
	_loadingBar = new progressBar;
	_loadingBar->init("image//loadingTop", "image//loadingBottom", WINSIZEX / 2, WINSIZEY - 20, WINSIZEX, 20);
	_loadingBar->setGauge(0, 0);

	_currentGauge = 0;
	_lastLoading = 0;

	return S_OK;
}

void loading::release()
{
	SAFE_DELETE(_loadingBar);
}

void loading::update() 
{
	_loadingBar->update();
}

void loading::render() 
{
	_background->render(getMemDC(), 0, 0);
	_loadingBar->render();
}


void loading::loadImage(const char* sceneName, string keyName, int width, int height)
{
	loadResource* resource = new loadResource;
	resource->initImage(sceneName, keyName, width, height);

	_vLoadResource.push_back(resource);
}

void loading::loadImage(const char* sceneName, string keyName, const char* fileName, int width, int height, BOOL trans, COLORREF transColor)
{
	loadResource* resource = new loadResource;
	resource->initImage(sceneName, keyName, fileName, width, height, trans, transColor);

	_vLoadResource.push_back(resource);
}

void loading::loadImage(const char* sceneName, string keyName, const char* fileName, float x, float y, int width, int height, BOOL trans, COLORREF transColor)
{
	loadResource* resource = new loadResource;
	resource->initImage(sceneName, keyName, fileName, x, y, width, height, trans, transColor);

	_vLoadResource.push_back(resource);
}

void loading::loadFrameImage(const char* sceneName, string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	loadResource* resource = new loadResource;
	resource->initFrameImage(sceneName, keyName, fileName, width, height, frameX, frameY, trans, transColor);

	_vLoadResource.push_back(resource);
}

void loading::loadFrameImage(const char* sceneName, string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	loadResource* resource = new loadResource;
	resource->initFrameImage(sceneName, keyName, fileName, x, y, width, height, frameX, frameY, trans, transColor);

	_vLoadResource.push_back(resource);
}

void loading::loadSound(const char* sceneName, string keyName, const char* fileName, bool bgm, bool loop)
{
	loadResource* resource = new loadResource;
	resource->initSound(sceneName, keyName, fileName, bgm, loop);

	_vLoadResource.push_back(resource);
}


BOOL loading::loadingDone()
{
	//로딩이 끝났으면 다됐다고 전해라~
	if (_currentGauge >= _vLoadResource.size()) return TRUE;

	loadResource* resource = _vLoadResource[_currentGauge];

	switch (resource->getLoadingKind())
	{
		case LOAD_KIND_IMAGE_0:
		{
			tagImageResource img = resource->getImageResource();
			IMAGEMANAGER->addImage(img.keyName, img.width, img.height);
		}
		break;
		case LOAD_KIND_IMAGE_1:
		{
			tagImageResource img = resource->getImageResource();
			IMAGEMANAGER->addImage(img.keyName, img.fileName,
				img.width, img.height, img.trans, img.transColor);
		}
		break;
		case LOAD_KIND_IMAGE_2:
		{
			tagImageResource img = resource->getImageResource();
			IMAGEMANAGER->addImage(img.keyName, img.fileName,
				img.x, img.y, img.width, img.height, img.trans, img.transColor);
		}
		break;
		case LOAD_KIND_FRAMEIMAGE_0:
		{
			tagImageResource img = resource->getImageResource();
			IMAGEMANAGER->addFrameImage(img.keyName, img.fileName,
				img.width, img.height, img.frameX, img.frameY, img.trans, img.transColor);
		}
		break;
		case LOAD_KIND_FRAMEIMAGE_1:
		{
			tagImageResource img = resource->getImageResource();
			IMAGEMANAGER->addFrameImage(img.keyName, img.fileName, 
				img.x, img.y, img.width, img.height, img.frameX, img.frameY, img.trans, img.transColor);
		}
		break;
		case LOAD_KIND_SOUND:
		{
			tagSoundResource soundSour = resource->getSoundResource();
			SOUNDMANAGER->addSound(soundSour.keyName, soundSour.fileName, soundSour.bgm, soundSour.loop);
		}
		break;
	}

	_loadingBar->setGauge(_currentGauge, _vLoadResource.size());
	_currentGauge++;

	return FALSE;
}

void loading::releaseResource(const char* sceneName)
{
	for (arrLoadResourceIter arrLoadSourIter = _vLoadResource.begin(); arrLoadSourIter != _vLoadResource.end();)
	{

		if ((*arrLoadSourIter)->getLoadingKind() == LOAD_KIND_END) ++arrLoadSourIter;
		else if ((*arrLoadSourIter)->getLoadingKind() == LOAD_KIND_SOUND)
		{

			if (strcmp((*arrLoadSourIter)->getSoundResource().sceneName,sceneName) == 0)
			{
				SAFE_RELEASE((*arrLoadSourIter));
				SAFE_DELETE((*arrLoadSourIter));

				arrLoadSourIter = _vLoadResource.erase(arrLoadSourIter);
				_currentGauge--;
				_lastLoading--;
			}
			else ++arrLoadSourIter;
		}
		else
		{
			if (strcmp((*arrLoadSourIter)->getImageResource().sceneName,sceneName) == 0)
			{
				IMAGEMANAGER->deleteImage((*arrLoadSourIter)->getImageResource().keyName);
				arrLoadSourIter = _vLoadResource.erase(arrLoadSourIter);
				_currentGauge--;
				_lastLoading--;
			}
			else ++arrLoadSourIter;
		}
	}
}