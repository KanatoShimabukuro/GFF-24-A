#pragma once

#include "DxLib.h"
#include "inputCtrl.h"
#include "scene.h"

class ResultScene : public Scene
{
private:

	// 画像用変数
	//int img_map;
	//int img_branchPoint;
	//int img_weapon1;
	//int img_weapon2;
	//int img_background;
	int img_button_a;			// Aボタン

public:
	ResultScene();
	~ResultScene();

	// 更新
	Scene* update() override;

	// 描画
	void draw() const override;

};

