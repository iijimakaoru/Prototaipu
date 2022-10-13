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
	// Ž€–Sƒtƒ‰ƒO”»’è
	bool IsDead() const { return isDead; }
	// “–‚½‚Á‚½‚Æ‚«
	void OnCollision() { isDead = true; }
	Transform GetTrans() { return transform; }

private:
	Transform transform;
	bool isDead;
	float speed;
	int moveVec;
};