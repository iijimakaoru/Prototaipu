#pragma once
#include "Struct.h"
#include "main.h"
#include "DxLib.h"

class Enemy
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	// 死亡フラグ判定
	bool IsDead() const { return isDead_; }
	// 当たったとき
	void OnCollision() { isDead_ = true; }
	Transform GetTransform() { return transform_; }

private:
	// 形
	Transform transform_;
	// 死亡フラグ
	bool isDead_;
	// スピード
	float speed_;
	// 動く方向
	int moveVec_;
};