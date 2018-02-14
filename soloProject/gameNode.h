#pragma once
#include "image.h"

//빈 비트맵 파일 백버퍼 생성
static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;

	gameNode* _self;			//셀프 그 자체
	gameNode* _parent;			//상위
	gameNode* _prev;			//이전
	gameNode* _next;			//다음
		
	gameNode* _childrenHead;	//연결된 노드들 중 젤 앞
	gameNode* _childrenTail;	//연결된 노드들 중 젤 뒤
	gameNode* _current;			//현재 노드

public:

	virtual HRESULT init(void);	//초기화
	virtual HRESULT init(bool managerInit);
	virtual void release(void);	//메모리 해제
	virtual void update(void);	//연산관련(타이머)
	virtual void render(void);	//그려주는 함수

	virtual void addChild(gameNode* node);
	virtual void removeChild(gameNode* node);

	inline void setSelf(gameNode* node) { _self = node; }
	inline gameNode* getSelf() { return _self; }

	inline void setChildrenHead(gameNode* node) { _childrenHead = node; }
	inline gameNode* getChildrenHead() { return _childrenHead; }

	inline void setChildrenTail(gameNode* node) { _childrenTail = node; }
	inline gameNode* getChildrenTail() { return _childrenTail; }

	inline void setParent(gameNode* node) { _parent = node; }
	inline gameNode* getParent() { return _parent; }

	inline void setPrev(gameNode* node) { _prev = node; }
	inline gameNode* getPrev() { return _prev; }

	inline void setNext(gameNode* node) { _next = node; }
	inline gameNode* getNext() { return _next; }

	image* getBackBuffer(void) { return _backBuffer; }

	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	gameNode();
	virtual ~gameNode();
};

