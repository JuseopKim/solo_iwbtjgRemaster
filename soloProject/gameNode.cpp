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

	//��ü ����
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

	//����� ���(��) ���� �� ����?
	while (current != NULL)
	{
		current->update();
		current = current->getNext();
	}

}

void gameNode::render(void)
{
	gameNode* current = _childrenHead;

	//����� ���(��) ���� �� ����?
	while (current != NULL)
	{
		current->render();
		current = current->getNext();
	}
}

//���� �߰��ϴ� �Լ�
void gameNode::addChild(gameNode* node)	  
{
	//�ƹ��� ���� �߰��Ǿ������ʴٸ�
	if (_childrenHead == NULL)
	{
		//�� �ڽ��� �θ�� ���(�� ��������)
		node->setParent(this);

		//���� ���� ���� �� ������ ����� ������ ����
		setChildrenHead(node);

		setChildrenTail(NULL);
	}
	else
	{
		_current = _childrenHead;
		//�����Ͱ� �ִٸ�
		while (_current->getNext() != NULL)
		{
			//�״��� ��带 �޾ƶ�
			_current = _current->getNext();
		}

		//�� ���� �ڽĳ��� ����
		node->setParent(this);
		//������带 ����Ű�� ������
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

	//���� 1���� �޷��ִٸ�
	while (_current != NULL)
	{
		//������� �ϴ� ���� ���� ���̳�
		if (_current == node)
		{
			//��������ϴµ� �ٷ� ��己 ���� �� �ƴϾ�
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
		//������ â�� �������� ������ �Ǵ� �Լ�
		case WM_CREATE:
			//�̴��Լ�
			
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
		//������ â ���� �Լ�
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
