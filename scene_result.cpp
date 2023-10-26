#include "scene_result.h"

ResultScene::ResultScene()
{
	// æÇ
	img_button_a = LoadGraph("resources/images/button_a.png");
	//img = LoadGraph("resources/images/slime_cat.png");
}

ResultScene::~ResultScene()
{
}

Scene* ResultScene::update()
{
	// ^CgÖJÚ
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS) {
		//return new Title;
	}

	return this;
}

void ResultScene::draw() const
{
	// wiF
	DrawBox(0, 0, 1280, 720, 0xa0a0a0, TRUE);

	// æ\¦
	DrawGraph(1100, 670, img_button_a, TRUE);

	// eLXg\¦
	SetFontSize(60);
	DrawFormatString(550, 10, 0x000000, "RESULT");
	SetFontSize(20);
	DrawFormatString(1150, 680, 0x000000, "TITLE");

	DrawFormatString(10, 50, 0x000000, "k¬}bv");

	DrawFormatString(700, 200, 0x000000, "íUIP");
	DrawFormatString(850, 150, 0x000000, "í¼P");
	DrawFormatString(850, 200, 0x000000, "Lv.              0");
	DrawFormatString(850, 250, 0x000000, "_[W      100000");

	DrawFormatString(700, 450, 0x000000, "íUIQ");
	DrawFormatString(850, 400, 0x000000, "í¼Q");
	DrawFormatString(850, 450, 0x000000, "Lv.              0");
	DrawFormatString(850, 500, 0x000000, "_[W      100000");

#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "J[\Êu: %d - %d", InputCtrl::GetMouseCursor().x, InputCtrl::GetMouseCursor().y);
#endif

}
