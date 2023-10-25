#include "scene_result.h"

ResultScene::ResultScene()
{
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
#ifdef _DEBUG
	DrawFormatString(0, 0, 0xffffff, "Result");
	if (InputCtrl::GetButtonState(XINPUT_BUTTON_A) == PRESS) {
		DrawFormatString(0, 0, 0xffffff, "³êÜµ½");
	}
#endif

	// æ\¦
	DrawGraph(1000, 600, img_button_a, TRUE);

	// eLXg\¦
	DrawFormatString(1150, 680, 0xffffff, "A:^Cg");

	DrawFormatString(10, 50, 0xffffff, "k¬}bv");

	DrawFormatString(700, 200, 0xffffff, "íUIP");
	DrawFormatString(850, 150, 0xffffff, "í¼P");
	DrawFormatString(850, 200, 0xffffff, "Lv.              0");
	DrawFormatString(850, 250, 0xffffff, "_[W      100000");

	DrawFormatString(700, 450, 0xffffff, "íUIQ");
	DrawFormatString(850, 400, 0xffffff, "í¼Q");
	DrawFormatString(850, 450, 0xffffff, "Lv.              0");
	DrawFormatString(850, 500, 0xffffff, "_[W      100000");

}
