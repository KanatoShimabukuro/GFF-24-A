﻿//////////////////////////////////////////////////
// ゲームメイン シーン
// 作成：
//////////////////////////////////////////////////
#pragma once

#include "scene.h"

enum GameSceneMode {
	map,          // マップ
	blacksmith,   // 鍛冶屋
	rest,         // 休憩
	main,         // 戦闘
	weaponSelect, // 武器選択
	weaponLevelup // 武器強化
};

enum GameSceneState {
	pause,
	play,
	end
};

enum GameSceneBattleMode {
	normal,  // 通常戦闘
	midBoss, // 中ボス
	boss,    // 最終ボス
};

class GameScene : public Scene {
private:
	int mode, state, frameCounter;

	//////////////////////////////////////////////////

	Player* player;

	bool swordHitFlg; //魔剣の連続ヒットカウント用
	weapon* weaponA;
	second_weapon* weaponB;
	bool bookFlg;

	Stage* stage;

	//敵//
	//スライム
	Slime* slime[MAX_SLIME_NUM];
	int tmpSlimeNum = 0;
	//スケルトン
	Skeleton* skeleton[MAX_SKELETON_NUM];
	int tmpSkeletonNum = 0;
	//魔法使い
	Wizard* wizard[MAX_WIZARD_NUM];
	int tmpWizardNum = 0;
	//弾
	EnemyBullet* enemyBullet[MAX_BULLET_NUM];
	int tmpBulletNum = 0;
	//ミノタウロス
	Minotaur* minotaur;

	GameUI* gameUI;

	//////////////////////////////////////////////////

	Map* map;

	Weapon_Selection* weaponSelect;
	bool weapon_selected;

	WeaponLevelUp* weaponLevelup;
	bool restor_cursor_position; // レベルアップ画面のカーソル位置を元に戻すか

	Blacksmith* blacksmith;
	Rest* rest;

	//////////////////////////////////////////////////

	// 島袋

	int hp;    // プレイヤー体力
	int exp;   // 経験値
	int level; // レベル
	int point; // ポイント（武器強化に使用）

	//int score; // 累計スコア

	int currentFloor; // 現在の階
	//int currentStage; // 現在のステージ（戦闘か休憩かなど）
	int battleMode;   // 戦闘のタイプ（通常かボスか）

	int bossState; // 中ボスの討伐状態

	std::map<std::string, int> enemySpawnData; // 敵のスポーンデータ

	std::vector<int> expData; // 経験値データ

	std::vector<std::map<std::string, int>> shimabukuro; // 敵のスポーンデータの塊（なんらかのクラス（Enemy/Stage）で管理したい）

public:
	GameScene();

	~GameScene();

	virtual Scene* update() override;

	virtual void draw() const override;

	//////////////////////////////////////////////////

	// 初期化
	void init();

	// 敵の最大数
	int getEnemyMax(int);

	// 敵の数
	int getEnemyNum(int);

	// 累計経験値取得
	//int getEXP();

	// レベル取得
	//int getLevel();

	//////////////////////////////////////////////////

	void HitCheck();

	//プレイヤーと敵の当たり判定
	bool HitEnemy(EnemyBase* enemy);

	//////////////////////////////////////////////////

	//敵
	void EnemyInc();
	//スライム
	void SlimeUpdate();
	void SlimeDraw() const;
	//スケルトン
	void SkeletonUpdate();
	void SkeletonDraw() const;
	//魔法使い
	void WizardUpdate();
	void WizardDraw() const;
	//弾
	void EnemyBulletUpdate();
	void EnemyBulletDraw() const;
	//ミノタウロス
	void MinotaurUpdate();
	void MinotaurDraw() const;
};