#pragma once
#include "main.h"
#include "Stage.h"
#include "Struct.h"
#include "Input.h"

class Player
{
public:
	// 壁
	enum class Vec
	{
		LEFT,
		RIGHT
	};
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="stage"></param>
	void Init(Stage& stage);
	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="stage"></param>
	/// <param name="input"></param>
	void Update(Stage& stage, Input& input);
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	/// <summary>
	/// transformのゲッター
	/// </summary>
	/// <returns></returns>
	Transform GetTransform() { return transform_; }
	/// <summary>
	/// 跳んでるフラグ
	/// </summary>
	/// <returns></returns>
	bool GetIsChange() { return isChange_; }
	/// <summary>
	/// どっちの壁にいるかの判定
	/// </summary>
	/// <returns></returns>
	bool Left() { return vec_ == Vec::LEFT; }
	bool Right() { return vec_ == Vec::RIGHT; }
	/// <summary>
	/// スピードアップ
	/// </summary>
	void AddLevelupCount() 
	{
		if (speedLevel_ < 3)
		{
			levelupCount_++;
		}
	}
	/// <summary>
	/// スピードダウン
	/// </summary>
	void AddLevelDownCount()
	{
		if (speedLevel_ > 1)
		{
			levelDownCount_++;
		}
	}
	/// <summary>
	/// 数値変動フラグ
	/// </summary>
	/// <returns></returns>
	bool IsAddCount() { return isAddCount_; }
	void ChangeIsAddCount() { isAddCount_ = false; }

private:
	// 形
	Transform transform_;
	// 跳んでるフラグ
	bool isChange_ = false;
	// 現在の壁
	Vec vec_ = Vec::LEFT;
	// スピード
	int speed_;
	// スピードレベル
	int speedLevel_;
	// 動く向き
	int moveVec_;
	// レベルアップに必要な回数
	int levelupCount_;
	// レベルダウンまでの回数
	int levelDownCount_;
	// 数値変動フラグ
	bool isAddCount_;
};

