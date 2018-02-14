#pragma once
#include "gameNode.h"
class mainMenu : public gameNode
{
	image* _charactor; //캐릭터 이미지 

	RECT _butten[5]; //메인 버튼
	int _buttenFrame[6]; //버튼 프레임들

	RECT _back; //백 버튼
	
	//로드버튼이라 적긴 했지만 사실상 옵션과 로딩 모든것을 담당한다.
	RECT _loadButten[4]; //옵션 버튼

	RECT _cloudLoopRect, _bgLoopRect; //배경 루프용 렉트

	int _cloudMove, _bgMove;//배경 움직이는 변수
	int _optionFrame[4];//옵션 버튼 프레임
	int _fps[3], //배경과 구름 프레임
		_frameX; //캐릭터 프레임

	//bool _saveSlot;


	bool _option,	//옵션 버튼 클릭 여부
		_load,		//로드 버튼 클릭 여부
		_keyconfig;	//키 컨픽 //안씀
	bool _clear;	//클리어 여부

	bool _bgm;		//사운드 여부
	bool _portlaits;//포트레이트 설정 여부

	bool _loadGame;	//게임 불러옴?

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

