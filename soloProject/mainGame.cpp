#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{

}


HRESULT mainGame::init(void)
{
	gameNode::init(true);

	//SCENEMANAGER->addScene("노드테스트", new mainNodeTestScene);
	//
	//SCENEMANAGER->changeScene("노드테스트");


	SCENEMANAGER->addScene("01.mainMenu", new mainMenu);
	SCENEMANAGER->addScene("02.inGameScene", new inGameScene);
	SCENEMANAGER->addScene("03.mapToolScene", new maptoolScene);
	//SCENEMANAGER->addScene("04.")
	SCENEMANAGER->changeScene("01.mainMenu");

	return S_OK;
}

void mainGame::release(void)
{
	
}


void mainGame::update(void)	
{
	gameNode::update();

	SCENEMANAGER->update();
	
}


void mainGame::render(void)	
{
	//흰색 도화지 한 장 필요
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============================================================
	
	SCENEMANAGER->render();
	
	//TIMEMANAGER->render(getMemDC());
	
	//========================================================================
	//백버퍼에 있는걸 HDC로 그려주는 역할
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

void mainGame::initImage()
{
	//backGrund
	//맨 뒤에 깔리는 이미지
	IMAGEMANAGER->addImage("bg_backBlock", "image//bgBack//backBlock.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_backMountin", "image//bgBack//backMountin.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_backForest", "image//bgBack//blackForest.bmp", 1276, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bg_cave", "image//bgBack//cave.bmp", 1193, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_city", "image//bgBack//city.bmp", 1286, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_corridor", "image//bgBack//corridor.bmp", 1373, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bg_forest", "image//bgBack//forest.bmp", 1527, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_blueForest", "image//bgBack//blueForest.bmp", 1276, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_loading", "image//bgBack//loading.bmp", 1024, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bg_nightStar", "image//bgBack//nightStar.bmp", 1275, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_noise", "image//bgBack//noise.bmp", 1533, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bg_palace", "image//bgBack//palace.bmp", 1296, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_twilight", "image//bgBack//twilight.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_twilight2", "image//bgBack//twilight2.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_waterSideLong", "image//bgBack//waterside.bmp", 2613, 769, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bg_waterSide", "image//bgBack//waterside2.bmp", 1295, 768, true, RGB(255, 0, 255));

	//frontGround
	//백그라운드보다 앞에 깔리는 이미지
	IMAGEMANAGER->addImage("fg_backCity", "image//bgFront//backCity.bmp", 1024, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_AylaRoom", "image//bgFront//bossAyla.bmp", 1024, 114, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_deusRoom", "image//bgFront//bossDeus.bmp", 1277, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_laplRoom", "image//bgFront//bossLaplace.bmp", 1024, 410, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_building", "image//bgFront//building.bmp", 158, 354, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_building2", "image//bgFront//building2.bmp", 160, 160, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_building3", "image//bgFront//building3.bmp", 224, 288, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_building4", "image//bgFront//building4.bmp", 160, 192, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_bush", "image//bgFront//bush.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_desert", "image//bgFront//desert.bmp", 1024, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_twilightCity", "image//bgFront//evnigCity.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_morningCity", "image//bgFront//mornigCity.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_nightCity", "image//bgFront//nightCity.bmp", 1024, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_flag1", "image//bgFront//flag1.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_flag2", "image//bgFront//flag2.bmp", 64, 96, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_flag3", "image//bgFront//flag3.bmp", 64, 96, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_flag4", "image//bgFront//flag4.bmp", 192, 128, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_floor", "image//bgFront//FloorDeus.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_forestRail", "image//bgFront//forestRail.bmp", 1130, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_hand", "image//bgFront//hand.bmp", 50, 206, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_hand2", "image//bgFront//hand2.bmp", 59, 223, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_hand3", "image//bgFront//hand3.bmp", 57, 205, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_hand4", "image//bgFront//hand4.bmp", 59, 223, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_harpMooon", "image//bgFront//harpMoon.bmp", 196, 210, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_moon", "image//bgFront//moon.bmp", 229, 230, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_iceBerg1", "image//bgFront//iceBerg.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_iceBerg2", "image//bgFront//iceBurg.bmp", 1024, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_iceMountin", "image//bgFront//iceMountin.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_mountin", "image//bgFront//mountin.bmp", 1024, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_island", "image//bgFront//island.bmp", 662, 248, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_seaIsland", "image//bgFront//islandToSea.bmp", 1024, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_redSea", "image//bgFront//redSea.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fg_sea", "image//bgFront//sea.bmp", 1024, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("fg_knifeField", "image//bgFront//knifeField.bmp", 1024, 768, true, RGB(255, 0, 255));

	//floor
	//타일맵 이외에 바닥역활을 하는 픽셀충돌용 이미지

	IMAGEMANAGER->addImage("fl_car", "image//floor//car.bmp", 189, 88, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fl_train", "image//floor//train.bmp", 4606, 264, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("fl_train1", "image//floor//train1.bmp",)

	//월드맵
	IMAGEMANAGER->addFrameImage("arrow", "image//worldmap//arrow.bmp", 406, 44, 14, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cancel", "image//worldmap//cancel.bmp", 722, 41, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("chack", "image//worldmap//chack.bmp", 206, 86, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("difficulty", "image//worldmap//difficulty.bmp", 722, 123, 2, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("play", "image//worldmap//play.bmp", 722, 41, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playType", "image//worldmap//playType.bmp", 722, 81, 2, 2, true, RGB(255, 0, 225));
	IMAGEMANAGER->addImage("select", "image//worldmap//select.bmp", 428, 18, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("stage", "image//worldmap//stage.bmp", 48, 16, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("discript", "image//worldmap//stageDiscript.bmp", 178, 624, 1, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("stageName", "image//worldmap//stageName.bmp", 233, 432, 1, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("selectStage", "image//worldmap//stageSelect.bmp", 1024, 155, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("worldmap", "image//worldmap//worldmap.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("black", "image//worldmap//black.bmp", 1024, 768, true, RGB(255, 0, 255));

	//ui
	IMAGEMANAGER->addFrameImage("back", "image//ui//back.bmp", 106, 19, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("backpack", "image//ui//backpack.bmp", 620, 500, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bluePrint", "image//ui//bossBlueprint.bmp", 844, 134, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("buff", "image//ui//buff.bmp", 46, 96, 3, 6, true, RGB(255, 0, 255));

	//IMAGEMANAGER->addImage("buff_bossDmgUp", "image//ui//buff_bossDmgUp.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_clock", "image//ui//buff_clock.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_dropUp", "image//ui//buff_dropUp.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_faster", "image//ui//buff_faster.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_dropDown", "image//ui//buff_itemDropDown.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_itemUp", "image//ui//buff_itemUp.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_moneyDropDown", "image//ui/buff_moneyDropDown.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_moneyDropUp", "image//ui//buff_moneyDropUp.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_moneyUp2", "image//ui//buff_moneyUup.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_range", "image//ui//buff_range.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_slow", "image//ui//buff_slow.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_statDown", "image//ui//buff_statDown.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_statUp", "image//ui//buff_statUo.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_statup2", "image//ui//buff_statUup.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_trapDmgDown", "image//ui//buff_trapDmgDown.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_trapDmgUp", "image//ui//buff_trapDmgUp.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_trapDmgup2", "image//ui//buff_trapDmgUup.bmp", 16, 16, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("buff_fury", "image//ui//buff_fury.bmp", 16, 16, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("ui_butten", "image//ui//butten.bmp", 180, 136, 1, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ui_dual", "image//ui//dual107frame.bmp", 268, 4066, 1, 107, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("exp_top", "image//ui//exp_bar.bmp", 384, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("exp_bottom", "image//ui//exp_bar2.bmp", 384, 3, true, RGB(255, 0, 255));

	//
	//IMAGEMANAGER->addImage("hp_top", "image//ui//hp_bar.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("hp_bottom", "image//ui//hp_bar2.bmp", 150, 12, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("hpBarBottom", "image//ui//hpBarBottom.bmp", 224, 26, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("hpBarTop", "image//ui//hpBarTop.bmp", 184, 14, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("inventorytile", "image//ui//inventorytile.bmp", 90, 90, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("key", "image//ui//key.bmp", 140, 68, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("icon_money", "image//ui//money_icon.bmp", 32, 32, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("nameTag", "image//ui//nameTag.bmp", 453, 124, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("num", "image//ui//num.bmp", 150, 63, 10, 3, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("portlate", "image//ui//portlate.bmp", 3580, 449, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cog", "image//ui//recognition.bmp", 145, 31, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("say", "image//ui//say.bmp", 116, 31, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shot", "image//ui//shot.bmp", 47, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skip", "image//ui//skip.bmp", 47, 57, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("statusUi", "image//ui//status_pane2.bmp", 381, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("weapon", "image//ui//weapon.bmp", 120, 30, 4, 1, true, RGB(255, 0, 255));

	//
	//item
	IMAGEMANAGER->addFrameImage("books", "image//item//book.bmp", 224, 32, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("buffItem", "image//item//buffItem.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cloth", "image//item//cloth.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("effectItem", "image//item//effectItem.bmp", 128, 32, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("elixir", "image//item//elixir.bmp", 256, 32, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("flask", "image//item//flask.bmp", 192, 32, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("food", "image//item//food.bmp", 256, 32, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("gem", "image//item//gem.bmp", 224, 32, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("hpItem", "image//item//hpItem", 128, 32, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("money", "image//item//money.bmp", 160, 32, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("place", "image//item//place.bmp", 480, 32, 15, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("scroll", "image//item//scroll.bmp", 64, 192, 2, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("store", "image//item//weapon.bmp", 96, 32, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bloodStone", "image//item//bloodStone.bmp", 32, 32, true, RGB(255, 0, 255));

	//
	//object
	IMAGEMANAGER->addImage("boom", "image//object//boom.bmp", 15, 15, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("boxs", "image//object//box3.bmp", 192, 32, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("door", "image//object//door.bmp", 1728, 96, 27, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("fieldArrow", "image//object//fieldArrow.bmp", 220, 80, 11, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gottSowrd", "image//object//gottfriedSowrd.bmp", 12, 62, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("kingdomDoor", "image//object//kingdomDoor1.bmp", 192, 244, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mine", "image//object//mine.bmp", 16, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("potal", "image//object//potal.bmp", 440, 180, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("spear", "image//object//spear.bmp", 28, 319, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tantacle", "image//object//tantacle.bmp", 600, 134, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("towerDoor", "image//object//towerDoor1.bmp", 148, 309, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("treeSpike", "image//object//treeSpike.bmp", 106, 94, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("waterTile", "image//object//water32frame.bmp", 4096, 285, 32, 3, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("waterFall", "image//object//water.bmp", 770, 758, 10, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("bookCase", "image//object//bookCase.bmp", 51, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("woodBox", "image//object//box.bmp", 64, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cemetery", "image//object//cemetery.bmp", 96, 32, 3, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("chandelier", "image//object//chandelier.bmp", 64, 54, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("pillar", "image//object//pillar.bmp", 64, 128, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("save", "image//object//savePoint.bmp", 32, 32, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("sewage", "image//object//sewage.bmp", 96, 96, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("sit", "image//object//sit.bmp", 24, 64, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("sit2", "image//object//sit2.bmp", 64, 96, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("trap", "image//object//trap.bmp", 32, 31, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("tube1", "image//object//tube1.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tube2", "image//object//tube2.bmp", 32, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tube3", "image//object//tube3.bmp", 64, 96, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("tv", "image//object//tv.bmp", 32, 32, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("seaMine", "image//object//seamine.bmp", 55, 55, true, RGB(255, 0, 255));

	//
	//effect
	IMAGEMANAGER->addFrameImage("aim", "image//effect//aim.bmp", 96, 32, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("arrPoint", "image//effect//arrow.bmp", 90, 24, 3, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("aura", "image//effect//aura.bmp", 1805, 330, 19, 3, true, RGB(255, 0, 255));


	IMAGEMANAGER->addFrameImage("bgChangeEffect", "image//effect//blackEffectNoneSet2.bmp", 6144, 683, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("blood", "image//effect//blood.bmp", 856, 190, 8, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("blueFire", "image//effect//blueFire.bmp", 40, 39, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("redFire", "image//effect//redFire.bmp", 29, 28, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("bluering", "image//effect//bluering.bmp", 640, 80, 8, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("boom1", "image//effect//boom1.bmp", 520, 67, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("boom2", "image//effect//boom2.bmp", 576, 91, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("boom2Small", "image//effect//boom2Small.bmp", 256, 40, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("boom3", "image//effect//boom3.bmp", 920, 44, 20, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("boom4", "image//effect//boom4.bmp", 448, 64, 7, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("buffEffect", "image//effect//buffEffect.bmp", 1321, 87, 19, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("buffEffect2", "image//effect//buffEffect2.bmp", 672, 117, 7, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("smoke", "image//effect//smoke.bmp", 140, 20, 7, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("bulletEffect", "image//effect//bulletEff.bmp", 45, 11, 5, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("clock", "image//effect//clock.bmp", 192, 192, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("eye", "image//effect//eye.bmp", 365, 365, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("fire", "image//effect//fire.bmp", 1500, 58, 30, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("fire2", "image//effect//fire2.bmp", 144, 166, 3, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("flameEffect", "image//effect//flameEffect.bmp", 1190, 3445, 2, 13, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("green", "image//effect//green.bmp", 216, 53, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("ink", "image//effect//ink.bmp", 798, 582, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("joyStick", "image//effect//joyStick.bmp", 273, 59, 3, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("lengthLaser", "image//effect//laser.bmp", 144, 2090, 6, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("widthLaser", "image//effect//laser2.bmp", 4096, 144, 4, 6, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("light", "image//effect//light.bmp", 135, 62, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("effect", "image//effect//magic.bmp", 2497, 225, 11, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("numKey", "image//effect//numKey.bmp", 192, 30, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("particel", "image//effect//particel.bmp", 512, 124, 16, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("pasture", "image//effect//pasture.bmp", 62, 32, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("laser", "image//effect//razer.bmp", 1024, 216, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("saveEffect", "image//effect//save.bmp", 880, 127, 9, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("scanEffect", "image//effect//scanEffect.bmp", 16384, 682, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("shotgunEffect", "image//effect//shotGunEffect.bmp", 451, 164, 11, 4, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("skull", "image//effect//skull.bmp", 15, 21, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("targetAim", "image//effect//targetAim.bmp", 34, 34, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("targeting", "image//effect//targeting.bmp", 256, 74, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("tunderbolt", "image//effect//tunderBolt.bmp", 2600, 500, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tunderbolt2", "image//effect//tunderBolt2.bmp", 4000, 300, 10, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("water1", "image//effect//water1.bmp", 672, 71, 21, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("water2", "image//effect//water2.bmp", 726, 73, 22, 1, true, RGB(255, 0, 255));

	//
	//ingameText
	IMAGEMANAGER->addFrameImage("bigNum", "image//text//bigNum.bmp", 230, 27, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bossName", "image//text//bossName.bmp", 270, 405, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("credit", "image//text//credit.bmp", 387, 1119, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("gameOver", "image//text//gameOver.bmp", 485, 130, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("goldnum", "image//text//goldnum.bmp", 444, 83, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("inStageName", "image//text//inStageName.bmp", 340, 576, 1, 10, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("inStageSubText", "image//text//instageSubText.bmp", 283, 256, 1, 8, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("item", "image//text//item.bmp", 82, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("save", "image//text//save.bmp", 98, 10, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("mainBossName", "image//text//mainBossName.bmp", 260, 312, 1, 13, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("stageBoss", "image//text//stageName.bmp", 258, 864, 1, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stageSelect2", "image//text//stageSelect.bmp", 249, 34, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("subBossName", "image//text//subBossName.bmp", 158, 110, 1, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("thank", "image//text//thank.bmp", 315, 38, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("bossSlay", "image//text//bossSlay.bmp", 810, 110, 1, 2, true, RGB(255, 0, 255));

	//
	//bullet
	IMAGEMANAGER->addImage("purpleBullet", "image//bullet//bullet.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bullet1", "image//bullet//bullet1.bmp", 80, 40, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bullet2", "image//bullet//bullet2.bmp", 192, 64, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bullet3", "image//bullet//bullet3.bmp", 848, 102, 16, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("bullet4", "image//bullet//bulletAni.bmp", 864, 55, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("canon", "image//bullet//canon.bmp", 448, 28, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("chestnut", "image//bullet//chestnut.bmp", 58, 62, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("enemyBullet", "image//bullet//eBullet.bmp", 512, 32, 16, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("handgun", "image//bullet//handgun.bmp", 8, 8, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("meteoriteMedium", "image//bullet//meteoriteMedium.bmp", 29, 29, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("meteoriteSmall", "image//bullet//meteoriteSmall.bmp", 16, 14, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("meteoriteSmall2", "image//bullet//meteoriteSmall2.bmp", 16, 15, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("meteoLarge", "image//bullet//meteoLarge.bmp", 55, 57, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("meteoLarge2", "image//bullet//meteoLarge2.bmp", 55, 56, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("missile", "image//bullet//missile.bmp", 125, 64, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("missile2", "image//bullet//missile2.bmp", 736, 45, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("nabe", "image//bullet//NaBe.bmp", 864, 54, 16, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("playerBullet", "image//bullet//pBullet.bmp", 28, 14, 2, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("roket", "image//bullet//roket.bmp", 32, 76, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("roket2", "image//bullet//roket2.bmp", 92, 184, 2, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("saver", "image//bullet//saver.bmp", 1600, 100, 16, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("swordAura", "image//bullet//swordAura.bmp", 192, 96, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("swordAura2", "image//bullet//swordAura2.bmp", 192, 192, 4, 2, true, RGB(255, 0, 255));

	//
	//npc
	IMAGEMANAGER->addImage("n_laplace", "image//npc//laplace.bmp", 45, 79, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("n_man1", "image//npc//man1.bmp", 38, 99, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("n_man2", "image//npc//man2.bmp", 36, 99, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("n_man3", "image//npc//man3.bmp", 55, 97, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("n_man5", "image//npc//man5.bmp", 48, 104, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("n_robot", "image//npc//robot.bmp", 61, 95, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("n_shop", "image//npc//shop.bmp", 36, 80, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("n_man4", "image//npc//man4.bmp", 243, 103, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("n_woman2", "image//npc//woman2.bmp", 34, 99, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("n_woman", "image//npc//woman.bmp", 120, 103, 2, 1, true, RGB(255, 0, 255));

	//
	//player
	IMAGEMANAGER->addFrameImage("1_down", "image//player//down.bmp", 120, 64, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("2_down", "image//player//down2.bmp", 36, 98, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("1_downLook", "image//player//downLook.bmp", 120, 64, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("2_downLook", "image//player//downLook2.bmp", 36, 98, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("1_idle", "image//player//idle.bmp", 150, 64, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("2_idle", "image//player//idle2.bmp", 35, 98, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("1_jump", "image//player//jump.bmp", 120, 64, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("2_jump", "image//player//jump2.bmp", 36, 98, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("1_move", "image//player//move2.bmp", 180, 64, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("2_move", "image//player//move.bmp", 216, 98, 6, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("1_slide", "image//player//slide.bmp", 30, 64, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("2_slide", "image//player//slide2.bmp", 36, 98, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("1_upLook", "image//player//up.bmp", 180, 64, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("2_upLook", "image//player//upLook.bmp", 36, 98, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("1_upLookMoving", "image//player//upLookMoving.bmp", 240, 64, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("2_upLookMoving", "image//player//upLookMoving2.bmp", 216, 98, 6, 2, true, RGB(255, 0, 255));

	//
	//enemy
	IMAGEMANAGER->addFrameImage("aircraft", "image//enemy//aircaft.bmp", 148, 130, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("canonBody", "image//enemy//canon.bmp", 55, 48, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("caterpillar", "image//enemy//caterpillar1.bmp", 592, 116, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("copter1", "image//enemy//copter1.bmp", 695, 226, 5, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("copter2attack", "image//ememy//copter2attack.bmp", 1332, 210, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("copter2stay", "image//enemy//copter2stay.bmp", 666, 180, 6, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("copter3attack", "image//enemy//copter3attack.bmp", 1332, 210, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("copter3stay", "image//enemy//copter3stay.bmp", 666, 180, 6, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("crocodile", "image//enemy//crocodile.bmp", 79, 160, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("eagleStay", "image//enemy//eagle.bmp", 345, 118, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("eagleAttack", "image//enemy//eagleAttack.bmp", 393, 172, 3, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("jellyfish", "image//enemy//jellyfish.bmp", 196, 61, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("machineGun", "image//enemy//marcingun.bmp", 72, 70, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("rider.bmp", "image//enemy//rider.bmp", 81, 126, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("robotAttack", "image//enemy//robotAttack.bmp", 110, 108, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("robotStanding", "image//enemy//robotUp.bmp", 275, 110, 5, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("roketLenchar", "image//enemy//roketLenchar.bmp", 112, 118, 2, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("sodAttack", "image//enemy//sodAttack.bmp", 705, 132, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sodDaed", "image//enemy//sodDaed.bmp", 141, 132, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sodFindIdle", "image//enemy//sodFindDead.bmp", 845, 132, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sodFindPlayer", "image//enemy//sodFindPlayer.bmp", 705, 132, 5, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("sodIdle", "image//enemy//sodIdle.bmp", 564, 132, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("sodJump", "image//enemy//sodJump.bmp", 141, 132, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("sodMove", "image//enemy//sodMove.bmp", 1692, 132, 12, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("tank", "image//enemy//tank.bmp", 412, 106, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tankTurret", "image//enemy//tankTurret.bmp", 101, 60, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("worm", "image//enemy//worm.bmp", 1815, 164, 11, 2, true, RGB(255, 0, 255));

	//
	//boss

	//
	//ayla
	IMAGEMANAGER->addImage("aylaHpTop", "image//boss//ayla//aylahpfront.bmp", 320, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("aylaHpBottom", "image//boss//ayla//aylahpback.bmp", 320, 10, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("devaHpBottom", "image//boss//ayla//hpback.bmp", 581, 18, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("devaHpTop", "image//boss//ayla//hpFront.bmp", 600, 42, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("aylaAttack", "image//boss//ayla//attack.bmp", 1106, 348, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("aylaDead", "image//boss//ayla//dead.bmp", 158, 174, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("aylaDown", "image//boss//ayla//down.bmp", 632, 174, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("aylaHit", "image//boss//ayla//hit.bmp", 632, 348, 4, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("aylaMove", "image//boss//ayla//move.bmp", 632, 348, 4, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("aylaPhase2", "image//boss//ayla//phase2.bmp", 1264, 174, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("aylaRecovery", "image//boss//ayla//recovery.bmp", 316, 174, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("aylaStand", "image//boss//ayla//stand.bmp", 1264, 174, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("aylaStandDown", "image//boss//ayla//standDown.bmp", 474, 174, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("aylaUp", "image//boss//ayla//up.bmp", 632, 174, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("devaronP1", "image//boss//ayla//devaronPhase1.bmp", 1024, 768, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("devaronP2", "image//boss//ayla//devaronPhase2.bmp", 1024, 768, true, RGB(255, 0, 255));

	//
	//deus
	IMAGEMANAGER->addImage("deusHpbottom", "image//boss//deus//hpback.bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("deusHpTop", "image//boss//deus//hpfront.bmp", 667, 56, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("deusAttack1", "image//boss//deus//attack1.bmp", 540, 228, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("deusAttack2", "image//boss//deus//attack2.bmp", 450, 228, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("deusAttack3", "image//boss//deus//attack3.bmp", 450, 228, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("deusAttack4", "image//boss//deus//attack4.bmp", 360, 228, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("deusAttack5", "image//boss//deus//attack5.bmp", 180, 228, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("deusDead", "image//boss//deus//dead.bmp", 90, 228, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("deusIdle", "image//boss//deus//idle.bmp", 90, 228, 1, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("deusSalute", "image//boss//deus//salute.bmp", 450, 228, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("deusSpecialAttack", "image//boss//deus//specialAttack.bmp", 90, 228, 1, 2, true, RGB(255, 0, 255));

	//
	//flaco
	IMAGEMANAGER->addFrameImage("dovefly", "image//boss//fleakoRav//doveFly.bmp", 58, 56, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("doveIdle", "image//boss//fleakoRav//doveIdle.bmp", 28, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("fleako", "image//boss//fleakoRav//fleako.bmp", 256, 99, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ravFly", "image//boss//fleakoRav//ravFly.bmp", 114, 44, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ravMove", "image//boss//fleakoRav//ravMove.bmp", 87, 50, 3, 2, true, RGB(255, 0, 255));

	//
	//gottfread
	IMAGEMANAGER->addImage("gottfriedHpBottom", "image//boss//gottfried//hpback.bmp", 861, 27, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("gottfriedHpTop", "image//boss//gottfried//hpfront.bmp", 900, 70, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("grayAtttack", "image//boss//gottfried//grayAttack.bmp", 1441, 348, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("grayIdle", "image//boss//gottfried//grayIdle.bmp", 618, 348, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("grayMagic", "image//boss//gottfried//grayMagicAttack.bmp", 1441, 348, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("grayMove", "image//boss//gottfried//grayMove.bmp", 1441, 348, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("grayStand", "image//boss//gottfried//grayStand.bmp", 1030, 348, 5, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("gottIdle", "image//boss//gottfried//idle.bmp", 618, 348, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("gottMagic", "image//boss//gottfried//magicAttack.bmp", 1441, 348, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("gottmove", "image//boss//gottfried//move.bmp", 1441, 348, 7, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("gottSaver", "image//boss//gottfried//saver.bmp", 18, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("gottAttack", "image//boss//gottfried//sowrdAttack.bmp", 1441, 348, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("gottStand", "image//boss//gottfried//stand.bmp", 1030, 348, 5, 2, true, RGB(255, 0, 255));
	
	//
	//laplace
	IMAGEMANAGER->addImage("lapHpTop", "image//boss//laplace//hpBackTo.bmp", 900, 92, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("lapHpBottomPhase1", "image//boss//laplace//hpPhase1.bmp", 854, 27, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("lapChasting", "image//boss//laplace//chasting.bmp", 2664, 266, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapDash", "image//boss//laplace//dash.bmp", 1776, 266, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapDead", "image//boss//laplace//dead.bmp", 297, 266, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapDown", "image//boss//laplace//down.bmp", 4736, 266, 16, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapGun", "image//boss//laplace//gun.bmp", 3256, 266, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapHandUp", "image//boss//laplace//handUp.bmp", 2072, 266, 7, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("lapIdle1", "image//boss//laplace//idle1.bmp", 1776, 266, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapidle2", "image//boss//laplace//idle2.bmp", 3552, 266, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapKillMotion", "image//boss//laplace//killMotion.bmp", 5032, 268, 17, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapMove", "image//boss//laplace//move.bmp", 3256, 266, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapPray", "image//boss//laplace//pray.bmp", 2664, 266, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapLaser", "image//boss//laplace//razer.bmp", 4144, 266, 14, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapUp", "image//boss//laplace//up.bmp", 2960, 266, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapAttackRiplact", "image//boss//laplace//useAttackRiplact.bmp", 4144, 266, 14, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lapStab", "image//boss//laplace//zzirgi.bmp", 2072, 266, 7, 2, true, RGB(255, 0, 255));
	
	//
	//madLaina	
	IMAGEMANAGER->addImage("mLainaHpBottom", "image//boss/madRina//hpback.bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mLainaHpTop", "image//boss/madRina//hpFront.bmp", 697, 62, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("mLainaAttack1", "image//boss//madRina//attack1.bmp", 1326, 202, 16, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mLainaAttack2", "image//boss//madRina//attack2.bmp", 918, 202, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mLainaAttack3", "image//boss//madRina//attack3.bmp", 1224, 202, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mLainaAttack4", "image//boss//madRina//attack4.bmp", 1224, 202, 12, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("mLainaAttack5", "image//boss//madRina//attack5.bmp", 714, 202, 7, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("mLainaStay", "image//boss//madRina//stay.bmp", 918, 202, 9, 2, true, RGB(255, 0, 255));

	//
	//laina
	IMAGEMANAGER->addImage("lainaHpBottom", "image//boss//raina//hpback.bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("lainaHpTop", "image//boss//raina//hpfront.bmp", 663, 55, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("lainaAttack1", "image//boss//raina//attack1.bmp", 720, 226, 9, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lainaAttack2", "image//boss//raina//attack2.bmp", 480, 226, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lainaAttack3", "image//boss//raina//attack3.bmp", 400, 226, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lainaIdle", "image//boss//raina//Idle.bmp", 80, 226, 1, 2, true, RGB(255, 0, 255));
	//이 이미지는 나도 뭐하는건지 모르겠다. 공격 모션인가?
	IMAGEMANAGER->addFrameImage("lainaSpac", "image//boss//raina//spec.bmp", 80, 226, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("lainaDead", "image//boss//raina//dead.bmp", 80, 226, 1, 2, true, RGB(255, 0, 255));

	//
	//strider
	IMAGEMANAGER->addFrameImage("stridernAttack", "image//boss//strider//down.bmp", 500, 117, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("striderGunAttack", "image//boss//strider//gun.bmp", 300, 117, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("striderIdle", "image//boss//strider//idle.bmp", 100, 117, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("striderKick", "image//boss//strider//kick.bmp", 800, 117, 8, 1, true, RGB(255, 0, 255));

	//1StageBosssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
	IMAGEMANAGER->addImage("tankArm", "image//boss//tank//arm.bmp", 33, 257, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tankArm2", "image//boss//tank//arm2.bmp", 208, 182, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tankArm3", "image//boss//tank//arm3.bmp", 128, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tankArm4", "image//boss//tank//arm4.bmp", 72, 27, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("tankWheel", "image//boss//tank//gnlf.bmp", 55, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tankWheel2", "image//boss//tank//gnlf2.bmp", 37, 37, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tankWheel3", "image//boss//tank//gnlf2.bmp", 29, 29, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("tankGrap", "image//boss//tank//grap.bmp", 53, 43, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tankGun", "image//boss//tank//gun.bmp", 558, 49, 6, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("tankGun2", "image//boss//tank//gun2.bmp", 98, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tankBody", "image//boss//tank//tankbody.bmp", 357, 220, true, RGB(255, 0, 255));

	//etc boss
	IMAGEMANAGER->addImage("lainaDeusHBback", "image//boss//tank//ayladeusback.bmp", 640, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("lainaDeusHpTop", "image//boss//tank//ayladeusFront.bmp", 668, 54, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("2StageBoss", "image//boss//data42991.bmp", 1486, 864,2,2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("3StageBoss", "image//boss//data429912.bmp", 638, 658,1,2, true, RGB(255, 0, 255));

	//etc hp bar
	IMAGEMANAGER->addImage("etcBossHpTop", "image//boss//hpfront].bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("etcBossHpTop2", "image//boss//hpfront2.bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("etcBossHpTop3", "image//boss//hpfront3.bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("etcBossHpTop4", "image//boss//hpfront4.bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("etcBossHpTop5", "image//boss//hpfront5.bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("etcBossHpTop6", "image//boss//hpfront6.bmp", 640, 20, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("etcBossHpBottom", "image//boss//hpback.bmp", 640, 20, true, RGB(255, 0, 255));

	//1stagebosshp
	IMAGEMANAGER->addImage("etcBossHpBottom2", "image//boss//hpback2.bmp", 640, 20, true, RGB(255, 0, 255));
	
	//2stagebosshp
	IMAGEMANAGER->addImage("etcBossHpBottom3", "image//boss//hpback3.bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("etcBossHpTop4", "image//boss//hpback4.bmp", 664, 48, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("etcBossHpBottom5", "image//boss//hpback5.bmp", 640, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("etcBossHpBottom6", "image//boss//hpback6.bmp", 640, 20, true, RGB(255, 0, 255));
	
	//etc
	IMAGEMANAGER->addFrameImage("tile", "image//tile.bmp", 384, 160, 12, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enemySet", "image//enemyImg.bmp", 352, 32, 11,1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("haerth", "image//haerh.bmp", 32, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("loadingBackGround", "image//loadingBg.bmp", 1024, 768, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("loadingBottom", "image//loadingBottom.bmp", 500, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("loadingTop", "image//loadingTop.bmp", 500, 50, true, RGB(255, 0, 255));
}
	
void mainGame::initSound()
{

}