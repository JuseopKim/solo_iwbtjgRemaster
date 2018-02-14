#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
	: _self(NULL),
	_parent(NULL),
	_prev(NULL),
	_next(NULL),
	_current(NULL),
	_childrenHead(NULL),
	_childrenTail(NULL)
{
}


gameNode::~gameNode()
{

}

HRESULT gameNode::init(void)
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;

	//본체 설정
	setSelf(this);

	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (_managerInit)
	{
		//SetTimer(_hWnd, 1, 10, NULL);
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TXTDATA->init();
		TIMEMANAGER->init();
		SOUNDMANAGER->init();
		EFFECTMANAGER->init();
		SCENEMANAGER->init();
		KEYANIMANAGER->init();
		DATABASE->init();
	}

	return S_OK;
}

void gameNode::release(void)
{

	if (_managerInit)
	{
		//KillTimer(_hWnd, 1);
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		TXTDATA->releaseSingleton();
		TIMEMANAGER->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		SCENEMANAGER->releaseSingleton();
		KEYANIMANAGER->releaseSingleton();
		DATABASE->releaseSingleton();
	}

	ReleaseDC(_hWnd, _hdc);

	_current = _childrenHead;

	gameNode* temp;

	while (_current != NULL)
	{
		temp = _current->getNext();
		_current->release();
		SAFE_DELETE(_current);
		_current = _childrenHead = temp;
	}

	
}

void gameNode::update(void)	
{
	//InvalidateRect(_hWnd, NULL, false);

	gameNode* current = _childrenHead;

	//연결된 노드(씬) 들은 다 알죠?
	while (current != NULL)
	{
		current->update();
		current = current->getNext();
	}

}

void gameNode::render(void)
{
	gameNode* current = _childrenHead;

	//연결된 노드(씬) 들은 다 알죠?
	while (current != NULL)
	{
		current->render();
		current = current->getNext();
	}
}

//씬을 추가하는 함수
void gameNode::addChild(gameNode* node)	  
{
	//아무런 씬도 추가되어있지않다면
	if (_childrenHead == NULL)
	{
		//나 자신을 부모로 삼고(젤 상위계층)
		node->setParent(this);

		//지금 들어온 씬이 젤 상위의 연결된 씬으로 설정
		setChildrenHead(node);

		setChildrenTail(NULL);
	}
	else
	{
		_current = _childrenHead;
		//포인터가 있다면
		while (_current->getNext() != NULL)
		{
			//그다음 노드를 받아라
			_current = _current->getNext();
		}

		//이 씬의 자식노드로 지정
		node->setParent(this);
		//이전노드를 가르키는 포인터
		node->setPrev(_current);

		_current->setNext(node);

		node->setNext(NULL);

		_childrenTail = node;
	}
}

void gameNode::removeChild(gameNode* node)
{
	int count = 0;

	_current = _childrenHead;

	gameNode* prev = NULL;

	//씬이 1개라도 달려있다면
	while (_current != NULL)
	{
		//지우고자 하는 씬이 현재 씬이냐
		if (_current == node)
		{
			//지우려고하는데 바로 췰드런 헤드는 또 아니야
			if (count != 0)
			{
				//
				prev->setNext(_current->getNext());
				if (_current->getNext() != NULL) _current->getNext()->setPrev(prev);
				else _childrenTail = _current;

			}
			else
			{
				//
				_childrenHead = _current->getNext();
				if (_childrenHead != NULL) _childrenHead->setPrev(NULL);
			}

			_current->release();
			SAFE_DELETE(_current);
			break;
		}

		prev = _current;
		_current = _current->getNext();
		count++;
	}

}



LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
		//윈도우 창이 켜질때만 실행이 되는 함수
		case WM_CREATE:
			//이닛함수
			
		break;
		case WM_PAINT:
		{
			hdc = BeginPaint(hWnd, &ps);
		
			this->render();
		
			EndPaint(hWnd, &ps);
		}
		break;
		case WM_MOUSEMOVE:
			_ptMouse.x = static_cast<float>LOWORD(lParam);
			_ptMouse.y = static_cast<float>HIWORD(lParam);

		
		break;
		case WM_KEYDOWN:
			switch (wParam)
			{
				case VK_ESCAPE:
					PostMessage(hWnd, WM_DESTROY, 0, 0);
				break;
			}
		break;
		case WM_DESTROY:
		//윈도우 창 종료 함수
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
