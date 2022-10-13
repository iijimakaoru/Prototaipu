#include "Enemy.h"

void Enemy::Init()
{
	transform.x = WIN_WIDTH / 2;
	transform.y = WIN_HEIGHT / 2;
	transform.width = 30;
	transform.height = 30;
	speed = 2;
	moveVec = 1;
}

void Enemy::Update()
{
	if (transform.y - transform.height / 2 <= 0 || transform.y + transform.height / 2 >= WIN_HEIGHT)
	{
		moveVec *= -1;
	}

	transform.y += speed * moveVec;
}

void Enemy::Draw()
{
	DrawBox(transform.x - transform.width / 2, transform.y - transform.height / 2,
		transform.x + transform.width / 2, transform.y + transform.height / 2,
		GetColor(255, 0, 0), true);
}