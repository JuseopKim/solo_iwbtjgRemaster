#include "stdafx.h"
#include "nodeTest2.h"


nodeTest2::nodeTest2()
{
}


nodeTest2::~nodeTest2()
{

}

HRESULT nodeTest2::init()
{
	IMAGEMANAGER->addImage("¸¶¼Ò", "ºô°ÔÀÌÃ÷.bmp", 300, 300, true, RGB(255, 0, 255));


	return S_OK;
}

void nodeTest2::release()
{

}

void nodeTest2::update() 
{

}

void nodeTest2::render() 
{
	IMAGEMANAGER->findImage("¸¶¼Ò")->render(getMemDC(), WINSIZEX / 2, WINSIZEY / 2);
}
