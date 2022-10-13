#include "Enemy.h"

void Enemy::Init()
{
	pos.x = WIN_WIDTH / 2;
	pos.y = WIN_HEIGHT / 2;
	pos.width = 10;
	pos.height = 10;
	speed = 2;
	moveVec = 1;
}

void Enemy::Update()
{
	if (pos.y - pos.height / 2 <= 0 || pos.y + pos.height / 2 >= WIN_HEIGHT)
	{
		moveVec *= -1;
	}

	pos.y += speed * moveVec;
}

void Enemy::Draw()
{
	DrawBox(pos.x - pos.width / 2, pos.y - pos.height / 2,
		pos.x + pos.width / 2, pos.y + pos.height / 2,
		GetColor(255, 0, 0), true);
}