#pragma once
#include "gameNode.h"
class mainMenu : public gameNode
{
	image* _charactor; //ĳ���� �̹��� 

	RECT _butten[5]; //���� ��ư
	int _buttenFrame[6]; //��ư �����ӵ�

	RECT _back; //�� ��ư
	
	//�ε��ư�̶� ���� ������ ��ǻ� �ɼǰ� �ε� ������ ����Ѵ�.
	RECT _loadButten[4]; //�ɼ� ��ư

	RECT _cloudLoopRect, _bgLoopRect; //��� ������ ��Ʈ

	int _cloudMove, _bgMove;//��� �����̴� ����
	int _optionFrame[4];//�ɼ� ��ư ������
	int _fps[3], //���� ���� ������
		_frameX; //ĳ���� ������

	//bool _saveSlot;


	bool _option,	//�ɼ� ��ư Ŭ�� ����
		_load,		//�ε� ��ư Ŭ�� ����
		_keyconfig;	//Ű ���� //�Ⱦ�
	bool _clear;	//Ŭ���� ����

	bool _bgm;		//���� ����
	bool _portlaits;//��Ʈ����Ʈ ���� ����

	bool _loadGame;	//���� �ҷ���?

public:
	HRESULT init();
	void release();
	void update();
	void render();
	void imageinit();
	void butteninit();
	
	bool getBgm() { return _bgm; }
	bool getportlaits() { return _portlaits; }
	bool getLoad() { return _loadGame; }

	bool getGameClear() { return _clear; }
	bool setGameClear(bool clear) { _clear = clear; }

	//void setSaveSlot() { _saveSlot; }
	//bool getSaveSlot() { return _saveSlot; }

	mainMenu();
	~mainMenu();
};

