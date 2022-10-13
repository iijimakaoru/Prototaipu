#pragma once
#include "Struct.h"
#include "main.h"
#include "DxLib.h"

class Enemy
{
public:
	void Init();
	void Update();
	void Draw();
	void Pop();
	// 死亡フラグ判定
	bool IsDead() const { return isDead; }
	// 当たったとき
	void OnCollision() { isDead = true; }
	Transform GetTrans() { return transform; }

private:
	Transform transform;
	bool isDead;
	float speed;
	int moveVec;
};