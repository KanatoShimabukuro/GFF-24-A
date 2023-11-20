﻿#pragma once
#include "EnemyBase.h"
#define BOX_MAX_WIDTH  50  //タックル攻撃予測の矩形の最大の幅
#define BOX_MAX_LENGTH 390 //タックル攻撃予測の矩形の最大の長さ

class Minotaur :public EnemyBase
{
private:
	//----------タックル----------//
	int tackleCoolTimeCnt;//タックルした後のクールタイム
	int tacklePrepTimeCnt;//タックル準備時間
	bool tackleFlg;//現在がタックル状態かどうか

	//薄い赤色の矩形
	float boxX_a;
	float boxY_a;

	//濃い赤色の矩形
	int lineSize;
	int lineSizeChageCnt;

	//----------咆哮----------//

public:
	Minotaur();
	void Update(Player* player);
	void Draw() const;

	//タックル
	void TackleUpdate();
	void TackleDraw() const;

	//咆哮
	void RoarUpdate();
	void RoarDraw() const;
};

