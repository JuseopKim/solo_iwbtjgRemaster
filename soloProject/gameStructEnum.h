#pragma once


#define STAGEMAX 8

#define BAGSIZE 24
#define BUFFMAX 10

#define JUMPSTART 3
#define JUMPMAX 10
#define FALLMAX 12
#define MOVESTART 1
#define MOVEMXA 3

#define SLIDE 8
#define SLIDETIME 1.5

#define LADDERSPEED 2

struct  tagPlayerStatus
{
	int lv;	//레벨

	int place;	//레벨을 올릴수 있는 자원
	int money;	//아이템을 구매할수 있는 자원

	int maxHp;	//최대 체력
	int currentHp;	//현재 체력

	int maxSp;	//최대 스테미나
	int currentSp;	//현재 스테미나

	int str;	//힘, 무기를 들수 있게 해주고 강인함 및 방어력과 체력 그리고 스테미나에 영향을 준다.
	int	dex;	//민첩, 공격력, 공격속도 및 이동속도에 영향을 준다.

	int fir;	//불 저항, 불 속성 공격에 대한 속성 방어력, 높아지면 Burn 디버프의 데미지와 시간이 짧아진다.
	int ice;	//얼음 저항, 얼음 속성에 대한 반감, 불과 기터내용 동일
	int psn;	//독 저항
	int lig;	//신성 저항

	float atkLck;	//명중률, 높아지면 치명타의 확률이 비례하여 상승한다.
	float avdLck;	//회피율, 높아지면 적의 공격이 데미지를 주지 않을 확률이 높아진다.

	int def;	//방어력 물리공격방어
	int magDef;	//마법방어력(마법 공격 방어력)
	int Atk;	//공격력

	float crit;	//크리티컬 데미지 곱수, 크리티컬 발생시 해당 값을 곱해준다.

	float jumpSpeed;	//점프
	float speed;	//이동속도

	float attRate;	//공격속도

	int strongness; //강인함, 권총으로 패링을 먹일때 원래 상태로 돌아오기까지 걸리는 시간
};

enum PLAYERSTATE
{
	PLAYER_IDLE,

	PLAYER_MOVE,
	PLAYER_SLIDE,
	PLAYER_BACK_SLIDE,

	PLAYER_JUMP,
	PLAYER_JUMP_LOOKDOWN,

	PLAYER_LOOKUP,
	PLAYER_LOOKUP_MOVE,

	PLAYER_DOWN,
	PLAYER_FALL,

	PLAYER_DIE,

	PLAYER_END
};

enum PLAYERWEAPON
{
	WEAPON_HANDGUN,
	WEAPON_RIFLE,
	WEAPON_SHOTGUN,
	WEAPON_ROKET,

	WEAPON_END
};

enum BUFF
{
	BUFF_INVISIBLE,	//투명화

	BUFF_FROZEN,	//빙결	1,1
	BUFF_FIRE,		//연소	1.2
	BUFF_POISEN,	//독	1,3

	BUFF_AGING,		//노화			2,1
	BUFF_FASTER,	//이속 공속 업	2,2
	BUFF_CURSE,		//저주			2,3

	BUFF_ITEMDOWN,	//드랍률 다운	3,1
	BUFF_ITEMUP1,	//드랍률 업		3,2
	BUFF_ITEMUP2,	//드랍률2 업	3,3

	BUFF_MONEYDOWN,	//돈 드랍 하락	4,1
	BUFF_MONEYUP,	//돈 드랍 증가	4,2
	BUFF_MONEYUP2,	//돈 드랍 증가2	4,3

	BUFF_STATDOWN,	//스테이터스 다운	5,1
	BUFF_STATUP1,	//스테이터스 업1	5,2
	BUFF_STATUP2,	//스테이터스 업2	5,3

	BUFF_ENEMYDOWN,	//적 공격력 하락	6,1
	BUFF_ENEMYUP1,	//적 공격력 상승1	6,2
	BUFF_ENEMYUP2	//적 공격력 상승2	6,3
};

struct tagBuff
{
	BUFF type;
	bool debuff;

	float leftTime;
	int val;
};

struct tagPlayerInfo
{
	image* image;	
	PLAYERSTATE playerState;
	PLAYERWEAPON weapon;

	tagBuff buff[BUFFMAX];
	tagPlayerStatus status;

	float pointX, pointY;
	float xSpeed, ySpeed;

	bool LookRight;

	float jumpPower;
	RECT rc;

	float gravity;

	int lightAndDark;
	bool light;

	int currentFrameX, currentFrameY;

	int currentStage;
};


enum ENEMYSTATE
{
	ENEMY_SLEEP,

	ENEMY_IDLE,
	ENEMY_MOVE,
	ENEMY_ATTACK,
	ENEMY_USESKILL,

	ENEMY_DEAD
};

struct  tagEnemyStatus
{
	int lv;	//레벨

	int place;	//플레이어에게 넘길 자원
	int money;

	int maxHp;
	int currentHp;

	int maxSp;
	int currentSp;

	int str;
	int	dex;

	int fir;
	int ice;
	int psn;
	int lig;

	float atkLck;
	float avdLck;

	int def;
	int magDef;
	int Atk;

	float crit;

	float jumpSpeed;
	float speed;

	float attRate;

	int strongness;
};

struct tagEnemyInfo
{
	image* image;
	ENEMYSTATE state;
	tagEnemyStatus status;

	float pointX, pointY;
	float xSpeed;
	float ySpeed;
	
	bool lookRight;
	RECT rc;

	float gravity;

	int currentFrameX, currentFrameY;

	int currentStage;
};


enum BOSSSTATE
{
	BOSS_SLEEP,

	BOSS_IDLE,
	BOSS_MOVE,

	BOSS_ATTACK_NOMAL,
	BOSS_ATTACK_PATTEN1,
	BOSS_ATTACK_PATTEN2,
	BOSS_ATTACK_PATTEN3,

	BOSS_TELEAPORT,
	BOSS_SKILL1,
	BOSS_SKILL2,
	BOSS_SKILL3,

	BOSS_DEAD

};

enum BOSSTYPE
{
	TYPE_MACHINE,
	TYPE_WARRER,
	TYPE_MAGITION
};

struct tagBossStatus
{
	int lv;

	int place;
	int money;

	int maxHp;
	int currentHp;

	int maxSp;
	int currentSp;

	int str;
	int dex;

	int fir;
	int ice;
	int psn;
	int lig;

	float atkLck, avdLck;

	int def;
	int mageDef;

	int atk;

	float crit;

	float jumpSpeed;
	float speed;

	float attRate;

	int strongness;
};

struct tagBossInfo
{
	image* image;
	BOSSSTATE state;
	tagBossStatus status;

	float pointX, pointY;
	float xSpeed, ySpeed;

	bool lookRight;
	RECT rc;

	float gravity;

	int currentFrameX, currentFrameY;

	int currentStage;

	int phase;
};


enum ITEMTYPE
{
	TYPE_POTION,
	TYPE_BUFF,
	TYPE_CLOTH,
	TYPE_BOOK,
	TYPE_SCROLL,
	TYPE_WEAPON,
	TYPE_PLACE,
	TYPE_GEM,
	TYPE_ETC
};

enum ITEMNAME
{
	//===포션===
	NAME_BLOOD_VIAL,		//수혈팩 30%회복
	NAME_BLOOD_COCKTAIL,	//혈주	50%회복
	NAME_HP_ELIXIR,			//체력회복 물약 스테미나 감소
	NAME_SP_ELIXIR,			//스테미나 회복 물약
	NAME_GREEN_ELIXIR,		//용기의 물약
	NAME_TUNDER_ELIXIR,		//번개물약
	NAME_POISEN_ELIXIR,		//독 물약
	NAME_BLUE_ELIXIR,		//푸른물약 은폐
	NAME_LEAD_ELIXIR,		//수은비약 방어력 대폭 상승
	NAME_WATER_FLASK,		//물
	NAME_GREEN_FLASK,
	NAME_HONEY_FLASK,
	NAME_RED_FLASK,
	NAME_POISEN_FLASK,
	NAME_APPLE,
	NAME_BANANA,
	NAME_STRAWBERRY,
	NAME_BURGER,
	NAME_CHERRY,
	NAME_CHOCOLET,
	NAME_PEAR,
	NAME_PINEAPPLE,

	//====버프====
	NAME_FIRE_PAPER,	//발화 부싯깃
	NAME_BONEMARROW,	//골수가루
	NAME_ARCANE_HAZE,	//신비로운 안개	//버프들 해제
	NAME_NUMBING_MIST,	//마비안개 //적의 HP 회복을 막는다. 나도
	NAME_ANTIDOTE,		//해독제 //독 회복
	NAME_SEDATIVE,		//진정제 //기타 상태이상 회복

	//=====옷=====
	NAME_CLOTH,

	//=====책=====
	NAME_BOOK_STATUP,	//스텟 업
	NAME_BOOK_DEFUP,	//방어력 업
	NAME_BOOK_FIREUP,	//불 저항 업
	MANE_BOOK_ICEUP,	//빙결 저항 업
	NAME_BOOK_LIGHTUP,	//신성 저항 업
	NAME_BOOK_CURSEBOOK,//저주받은 책
	NAME_BOOK_OLDBOOK,	//오래된 책
	NAME_SCROLL_GREEN,
	NAME_SCROLL_BLUE,
	NAME_SCROLL_YELLO,
	NAME_SCROLL_PURPLE,
	NAME_SCROLL_RED,
	NAME_SCROLL_BLACK,

	//무기
	NAME_WEAPON_BULLET,
	NAME_WEAPON_HANDGUN,
	NAME_WEAPON_RIFLE,

	//조각
	NAME_PLACE_METAL,
	NAME_PLACE_MICRON,
	NAME_PLACE_OLDPAPER,
	NAME_PLACE_MICROPHONE,
	NAME_PLACE_REDCASE,
	NAME_PLACE_SKULL,
	NAME_PLACE_WINGBONE,
	NAME_PLACE_BOTTLE,
	NAME_PLACE_BROKENGUN,
	NAME_PLACE_CIRCULT,
	NAME_PLACE_CROSS,
	NAME_PLACE_FEATHER,
	NAME_PLACE_HORN,
	NAME_PLACE_ICE,
	NAME_PLACE_MASK,

	//보석
	NAME_BLUE_GEM,
	NAME_PUPLE_GEM,
	NAME_GREEN_GEM,
	NAME_YELLO_GEM,
	NAME_RED_GEM,
	NAME_WHITE_GEM,
	NAME_BLACK_GEM,

	//====기타====
	NAME_BLOODSTONE,	//혈석 강화템
	NAME_COLDBLOOD,		//사혈 강화템
	NAME_HANDLANTERN,	//랜턴	//불빛의 거리를 늘려준다. //벽에 대한 처리는 어떻게 해야할까
	NAME_EMPTY_FLASK,	

	//=====돈======
	NAME_MONOCULAR,
	NAME_SHINIG_COIN,
	NAME_DIAMOND,
	NAME_GOLDBAR,
	NAME_GOLDNUGGET
};

typedef struct tagItemInfo
{
	image* img;

	ITEMNAME name;
	ITEMTYPE type;

	tagPlayerStatus status;

	POINT pt;
	RECT rc;

	bool equip;
	bool isCuresd;
	bool contentsHide;
	bool drop;

	int tier;
	int upgrade;
	int upgradeMax;

	int needStr;

	int num;
	int position;

	int stage;
}ITEM;

enum STAGE
{
	STAGE_MANSION,
	STAGE_SUBURB,
	STAGE_MOUNTIN,
	STAGE_WATERSIDE,
	STAGE_CANAL,
	STAGE_REMAINS,
	STAGE_VIADUCT,
	STAGE_TOWER,
	STAGE_ICEBERG,

	STAGE_END
};

//TERRAIN BIT
#define ATTRIBUTE_FLOOR		0x000001 // 기본 바닥
#define ATTRIBUTE_UNSIGHT	0x000002 // 시야를 가리는 속성
#define ATTRIBUTE_SIGHT		0x000004 // 시야가 안가리는 속성
#define ATTRIBUTE_WATER		0x000008 // 물 속성, 모든 객체가 느려진다.
							
#define ATTRIBUTE_TRAP		0x000010 // 함정 : 정의는 따로 한다.
#define ATTRIBUTE_OBJECT	0x000020 // 오브젝트가 놓여진 타일(오브젝트 그 자체는 아님)
							
#define ATTRIBUTE_DOWNABLE	0x000100 // 떨어질수 있는 타일

enum TERRAIN
{
	TERRAIN_NULL,

	TERRAIN_FLOOR = ATTRIBUTE_FLOOR + ATTRIBUTE_UNSIGHT,
	TERRAIN_LIGHT = ATTRIBUTE_SIGHT,
	TERRAIN_WATER = ATTRIBUTE_WATER,

	TERRAIN_OBJECT = ATTRIBUTE_OBJECT,
	TERRAIN_TRAP = ATTRIBUTE_FLOOR + ATTRIBUTE_TRAP,

	TERRAIN_DOWNABLE = ATTRIBUTE_FLOOR + ATTRIBUTE_DOWNABLE
};

//오브젝트					
enum OBJECT
{
	OBJECT_NONE,

	OBJECT_CHEST,
	OBJECT_BOX1,
	OBJECT_BOX2,

	OBJECT_START,
	OBJECT_END,

	OBJECT_MOREJUMP1,
	OBJECT_MOREJUMP2,
	OBJECT_MOREMOVE,
	OBJECT_MOREDOWN,

	OBJECT_GRAVE1,
	OBJECT_GRAVE2,
	OBJECT_GRAVE3,

	OBJECT_TUBE1,
	OBJECT_TUBE2,
	OBJECT_TUBE3,

	OBJECT_CHANDELIER,

	OBJECT_SEWER,

	OBJECT_SAVE,

	OBJECT_DOOR,

	OBJECT_LADDER,

	OBJECT_CHAIR1,
	OBJECT_CHAIR2,
	OBJECT_CHAIR3,

	OBJECT_PILLAR
};

enum TILEVIEW
{
	TILEVIEW_NO,
	TILEVIEW_HALF,
	TILEVIEW_FULL,

	TILEVIEW_END
};

typedef struct tagTile
{
	image* image;
	int sourX, sourY;
	int destX, destY;

	TILEVIEW tileView;
	TERRAIN terrain;

	int stage;
}TILE;

typedef struct tagObject
{
	image* image;
	int sourX, sourY;
	int destX, destY;

	OBJECT obj;

	int stage;
}OBJ;

typedef struct tagGrid
{
	image* image;
	int x, y;
	int index;
	RECT rc;
	bool empty;
}GRID;

typedef struct tagSelectTile
{
	image* image;
	int sourX, sourY;

	int index;
	RECT rc;

}SELTILE;

typedef struct tagButten
{
	image* buttenImage;	//버튼 이미지
	RECT rc;			//버튼 렉트
	char buttenText[128];
	bool isCliked;

}BUTTEN;