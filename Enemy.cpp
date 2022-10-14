#include "Enemy.h"

void Enemy::Init()
{
	transform_.x = WIN_WIDTH / 2;
	transform_.y = WIN_HEIGHT / 2;
	transform_.width = 30;
	transform_.height = 30;
	speed_ = 2;
	moveVec_ = 1;
}

void Enemy::Update()
{
	if (transform_.y - transform_.height / 2 <= 0 || transform_.y + transform_.height / 2 >= WIN_HEIGHT)
	{
		moveVec_ *= -1;
	}

	transform_.y += speed_ * moveVec_;
}

void Enemy::Draw()
{
	DrawBox(transform_.x - transform_.width / 2, transform_.y - transform_.height / 2,
		transform_.x + transform_.width / 2, transform_.y + transform_.height / 2,
		GetColor(255, 0, 0), true);
}