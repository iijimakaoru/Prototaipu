#include "Enemy.h"

void Enemy::Init()
{
	transform_.pos.x = WIN_WIDTH / 2;
	transform_.pos.y = WIN_HEIGHT / 2;
	transform_.size.x = 30;
	transform_.size.y = 30;
	speed_ = 2;
	moveVec_ = 1;
}

void Enemy::Update()
{
	if (transform_.pos.y - transform_.size.y/ 2 <= 0 || transform_.pos.y + transform_.size.y / 2 >= WIN_HEIGHT)
	{
		moveVec_ *= -1;
	}

	transform_.pos.y += speed_ * moveVec_;
}

void Enemy::Draw()
{
	DrawBox(transform_.pos.x - transform_.size.x / 2, transform_.pos.y - transform_.size.y / 2,
		transform_.pos.x + transform_.size.x / 2, transform_.pos.y + transform_.size.y / 2,
		GetColor(255, 0, 0), true);
}