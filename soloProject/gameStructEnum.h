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
	int lv;	//����

	int place;	//������ �ø��� �ִ� �ڿ�
	int money;	//�������� �����Ҽ� �ִ� �ڿ�

	int maxHp;	//�ִ� ü��
	int currentHp;	//���� ü��

	int maxSp;	//�ִ� ���׹̳�
	int currentSp;	//���� ���׹̳�

	int str;	//��, ���⸦ ��� �ְ� ���ְ� ������ �� ���°� ü�� �׸��� ���׹̳��� ������ �ش�.
	int	dex;	//��ø, ���ݷ�, ���ݼӵ� �� �̵��ӵ��� ������ �ش�.

	int fir;	//�� ����, �� �Ӽ� ���ݿ� ���� �Ӽ� ����, �������� Burn ������� �������� �ð��� ª������.
	int ice;	//���� ����, ���� �Ӽ��� ���� �ݰ�, �Ұ� ���ͳ��� ����
	int psn;	//�� ����
	int lig;	//�ż� ����

	float atkLck;	//���߷�, �������� ġ��Ÿ�� Ȯ���� ����Ͽ� ����Ѵ�.
	float avdLck;	//ȸ����, �������� ���� ������ �������� ���� ���� Ȯ���� ��������.

	int def;	//���� �������ݹ��
	int magDef;	//��������(���� ���� ����)
	int Atk;	//���ݷ�

	float crit;	//ũ��Ƽ�� ������ ����, ũ��Ƽ�� �߻��� �ش� ���� �����ش�.

	float jumpSpeed;	//����
	float speed;	//�̵��ӵ�

	float attRate;	//���ݼӵ�

	int strongness; //������, �������� �и��� ���϶� ���� ���·� ���ƿ������ �ɸ��� �ð�
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
	BUFF_INVISIBLE,	//����ȭ

	BUFF_FROZEN,	//����	1,1
	BUFF_FIRE,		//����	1.2
	BUFF_POISEN,	//��	1,3

	BUFF_AGING,		//��ȭ			2,1
	BUFF_FASTER,	//�̼� ���� ��	2,2
	BUFF_CURSE,		//����			2,3

	BUFF_ITEMDOWN,	//����� �ٿ�	3,1
	BUFF_ITEMUP1,	//����� ��		3,2
	BUFF_ITEMUP2,	//�����2 ��	3,3

	BUFF_MONEYDOWN,	//�� ��� �϶�	4,1
	BUFF_MONEYUP,	//�� ��� ����	4,2
	BUFF_MONEYUP2,	//�� ��� ����2	4,3

	BUFF_STATDOWN,	//�������ͽ� �ٿ�	5,1
	BUFF_STATUP1,	//�������ͽ� ��1	5,2
	BUFF_STATUP2,	//�������ͽ� ��2	5,3

	BUFF_ENEMYDOWN,	//�� ���ݷ� �϶�	6,1
	BUFF_ENEMYUP1,	//�� ���ݷ� ���1	6,2
	BUFF_ENEMYUP2	//�� ���ݷ� ���2	6,3
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
	int lv;	//����

	int place;	//�÷��̾�� �ѱ� �ڿ�
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
	//===����===
	NAME_BLOOD_VIAL,		//������ 30%ȸ��
	NAME_BLOOD_COCKTAIL,	//����	50%ȸ��
	NAME_HP_ELIXIR,			//ü��ȸ�� ���� ���׹̳� ����
	NAME_SP_ELIXIR,			//���׹̳� ȸ�� ����
	NAME_GREEN_ELIXIR,		//����� ����
	NAME_TUNDER_ELIXIR,		//��������
	NAME_POISEN_ELIXIR,		//�� ����
	NAME_BLUE_ELIXIR,		//Ǫ������ ����
	NAME_LEAD_ELIXIR,		//������� ���� ���� ���
	NAME_WATER_FLASK,		//��
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

	//====����====
	NAME_FIRE_PAPER,	//��ȭ �ν˱�
	NAME_BONEMARROW,	//�������
	NAME_ARCANE_HAZE,	//�ź�ο� �Ȱ�	//������ ����
	NAME_NUMBING_MIST,	//����Ȱ� //���� HP ȸ���� ���´�. ����
	NAME_ANTIDOTE,		//�ص��� //�� ȸ��
	NAME_SEDATIVE,		//������ //��Ÿ �����̻� ȸ��

	//=====��=====
	NAME_CLOTH,

	//=====å=====
	NAME_BOOK_STATUP,	//���� ��
	NAME_BOOK_DEFUP,	//���� ��
	NAME_BOOK_FIREUP,	//�� ���� ��
	MANE_BOOK_ICEUP,	//���� ���� ��
	NAME_BOOK_LIGHTUP,	//�ż� ���� ��
	NAME_BOOK_CURSEBOOK,//���ֹ��� å
	NAME_BOOK_OLDBOOK,	//������ å
	NAME_SCROLL_GREEN,
	NAME_SCROLL_BLUE,
	NAME_SCROLL_YELLO,
	NAME_SCROLL_PURPLE,
	NAME_SCROLL_RED,
	NAME_SCROLL_BLACK,

	//����
	NAME_WEAPON_BULLET,
	NAME_WEAPON_HANDGUN,
	NAME_WEAPON_RIFLE,

	//����
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

	//����
	NAME_BLUE_GEM,
	NAME_PUPLE_GEM,
	NAME_GREEN_GEM,
	NAME_YELLO_GEM,
	NAME_RED_GEM,
	NAME_WHITE_GEM,
	NAME_BLACK_GEM,

	//====��Ÿ====
	NAME_BLOODSTONE,	//���� ��ȭ��
	NAME_COLDBLOOD,		//���� ��ȭ��
	NAME_HANDLANTERN,	//����	//�Һ��� �Ÿ��� �÷��ش�. //���� ���� ó���� ��� �ؾ��ұ�
	NAME_EMPTY_FLASK,	

	//=====��======
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
#define ATTRIBUTE_FLOOR		0x000001 // �⺻ �ٴ�
#define ATTRIBUTE_UNSIGHT	0x000002 // �þ߸� ������ �Ӽ�
#define ATTRIBUTE_SIGHT		0x000004 // �þ߰� �Ȱ����� �Ӽ�
#define ATTRIBUTE_WATER		0x000008 // �� �Ӽ�, ��� ��ü�� ��������.
							
#define ATTRIBUTE_TRAP		0x000010 // ���� : ���Ǵ� ���� �Ѵ�.
#define ATTRIBUTE_OBJECT	0x000020 // ������Ʈ�� ������ Ÿ��(������Ʈ �� ��ü�� �ƴ�)
							
#define ATTRIBUTE_DOWNABLE	0x000100 // �������� �ִ� Ÿ��

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

//������Ʈ					
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
	image* buttenImage;	//��ư �̹���
	RECT rc;			//��ư ��Ʈ
	char buttenText[128];
	bool isCliked;

}BUTTEN;