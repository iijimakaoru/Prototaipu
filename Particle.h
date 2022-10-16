#pragma once
#include "Struct.h"
#include "DxLib.h"

class Particle
{
public:
	void Init(const Vector2& pos, const Vector2& velocity);
	void Update();
	void Draw();
	bool IsDead() { return isDead_; }

private:
	Transform transform_;
	Vector2 speed_;
	Vector2 moveVec_;
	bool isDead_;
};

