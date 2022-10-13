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

private:
	Transform pos;
	bool isDead;
	float speed;
	int moveVec;
};