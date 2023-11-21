#pragma once

#include "rest.h"

class GameScene;
class GameUI;

#define PATTERN_MAX 3
#define DATA_MAX 21

class Map
{
private:
	int MapData[DATA_MAX];

	// アイコン座標(初期)
	const int icon_loc_def[PATTERN_MAX][DATA_MAX][2] = { {
		{430, 590}, {630, 590}, {830, 590}, {390, 470}, {530, 480},
		{730, 480}, {880, 470}, {630, 370}, {430, 270}, {630, 200},
		{870, 270}, {330, 80}, {530, 80}, {810, 140}, {930, 140},
		{870, 40}, {430, -100}, {630, -30}, {870, -100}, {630, -200},
		{630, -300},
	}, {
		{530, 590}, {730, 590}, {430, 470}, {630, 470}, {730, 470},
		{530, 370}, {730, 370}, {630, 320}, {430, 220}, {780, 220},
		{430, 130}, {520, 130}, {780, 130}, {430, 30}, {730, 30},
		{830, 30}, {780, -40}, {560, -90}, {780, -130}, {630, -200},
		{630, -300},
	}, {
		{630, 590}, {530, 540}, {730, 540}, {470, 470}, {580, 470},
		{730, 470}, {530, 400}, {630, 320}, {530, 220}, {730, 220},
		{430, 120}, {530, 120}, {630, 120}, {480, 30}, {580, 30},
		{730, 30}, {530, -20}, {730, -70}, {630, -130}, {630, -200},
		{630, -300},
	} };
	int icon_loc[DATA_MAX][2];        // アイコン座標
	int icon_loc_center[DATA_MAX][2]; // アイコン座標(中央)
	int icon_vec;                     // アイコン移動量


	// マップ生成制御
	const int map_ctrl[PATTERN_MAX][4][4]{ {
		{7, 7, 1, 1},
		{3, 6, 1, 2},
		{8, 18, 2, 3},
		{16, 18, 1, 1},
		},{
		{7, 7, 1, 1},
		{3, 6, 1, 2},
		{8, 18, 2, 3},
		{15, 18, 1, 1},
		},{
		{7, 7, 1, 1},
		{3, 6, 1, 2},
		{8, 18, 2, 3},
		{15, 18, 1, 1},
		},
	};


	// 次に行けるステージ
	const int next_stage[PATTERN_MAX][DATA_MAX][3]{ {
			{3,-1,-1},{4,5,-1},{6,-1,-1},{7,-1,-1},{7,-1,-1},
		    {7,-1,-1},{7,-1,-1},{8,9,10},{11,12,-1},{17,-1,-1},
			{13,14,-1},{16,-1,-1},{16,-1,-1},{15,-1,-1},{15,-1,-1},
			{18,-1,-1},{19,-1,-1},{19,-1,-1},{19,-1,-1},{20,-1,-1},
			{0,1,2}
		}, {
			{2,3,-1},{4,-1,-1},{5,-1,-1},{5,-1,-1},{6,-1,-1},
			{7,-1,-1},{7,-1,-1},{8,9,-1},{10,11,-1},{12,-1,-1},
			{13,-1,-1},{17,-1,-1},{14,15,-1},{17,-1,-1},{16,-1,-1},
			{16,-1,-1},{18,-1,-1},{19,-1,-1},{19,-1,-1},{20,-1,-1},
			{0,1,-1}
		}, {
			{1,2,-1},{3,4,-1},{5,-1,-1},{6,-1,-1},{6,-1,-1},
			{7,-1,-1},{7,-1,-1},{8,9,-1},{10,11,12},{15,-1,-1},
			{13,-1,-1},{13,14,-1},{14,-1,-1},{16,-1,-1},{16,-1,-1},
			{17,-1,-1},{18,-1,-1},{18,-1,-1},{19,-1,-1},{20,-1,-1},
			{0,-1,-1}
		},
	};
	int stage_log[10];
	int pattern;
	const int pattern_data_max[PATTERN_MAX]{ 21,21,21 };
	int data_max;

	Rest* rest;
	GameUI* ui;

	int cursor_pos;    // カーソル位置(次ステージ)
	int cursor_loc;    // カーソル位置(全体マップ)
	int move_cool;     // カーソル移動クールタイム
	bool cursor_move;  // カーソル移動によるカメラ移動をするか(スクロール移動すると解除)
	int cursor_r;      // カーソル半径
	int now_stage;     // 現在のステージ

	bool is_map_mode;

	bool is_rest;		//休憩ステージのフラグ
	bool is_show_rest;	//休憩ステージを映す？

	// 画像
	int battle_img = 0;
	int event_img = 0;
	int rest_img = 0;
	int anvil_img = 0;
	int boss_img = 0;
	int icon_back_img = 0;
public:
	Map(GameUI* ui);

	~Map();

	int update(int&, bool&);


	void draw() const;

	bool GetIsMapMode() {
		return is_map_mode;
	}

	void SetIsMapMode(const bool flg) {
		is_map_mode = flg;
	}

	int NowStage() {
		return now_stage;
	}

	void ClearStage() {
		cursor_pos = 0;
		cursor_loc = next_stage[pattern][now_stage][0];
		for (int i = 0; i <= 10; i++) {
			if (stage_log[i] == -1) {
				stage_log[i] = now_stage;
				break;
			}
		}
	}

	void ResetStage();

	void SetStage(int st_min, int st_max, int rand_min, int rand_max, int data_num);
};