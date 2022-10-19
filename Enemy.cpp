#include "Enemy.h"

void Enemy::Init()
{
	transform_.pos.x = WIN_WIDTH * 1 / 2;
	transform_.pos.y = GetRand(WIN_HEIGHT - transform_.height) + transform_.height / 2;
	transform_.width = 30;
	transform_.height = 30;
	speed_ = 2;
	moveVec_ = 1;
}

void Enemy::Update()
{
	if (transform_.pos.y - transform_.height/ 2 <= 0 ||
		transform_.pos.y + transform_.height / 2 >= WIN_HEIGHT)
	{
		moveVec_ *= -1;
	}

	transform_.pos.y += speed_ * moveVec_;

	if (transform_.pos.y - transform_.height / 2 <= 0)
	{
		transform_.pos.y = transform_.height / 2;
	}

	if (transform_.pos.y + transform_.height / 2 >= WIN_HEIGHT)
	{
		transform_.pos.y = WIN_HEIGHT - transform_.height / 2;
	}
}

void Enemy::Draw()
{
	DrawBox(transform_.pos.x - transform_.width / 2, transform_.pos.y - transform_.height / 2,
		transform_.pos.x + transform_.width / 2, transform_.pos.y + transform_.height / 2,
		GetColor(0, 255, 255), true);
}