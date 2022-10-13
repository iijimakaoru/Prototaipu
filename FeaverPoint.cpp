#include "FeaverPoint.h"

void FeaverPoint::Init()
{
	transform.x = 114514;
	transform.width = 8;
	transform.height = 100;
	isDead = false;
	speed = 4;
	moveVec = 1;
}

void FeaverPoint::Pop(int posX)
{
	transform.x = posX;
	transform.y = GetRand(WIN_HEIGHT - transform.height) + transform.height / 2;
	transform.height = 100;
	isDead = true;
}

void FeaverPoint::Update()
{
	if (transform.y + transform.height / 2 >= WIN_HEIGHT ||
		transform.y - transform.height / 2 <= 0)
	{
		moveVec *= -1;
	}

	if (transform.y - transform.height / 2 <= 0)
	{
		transform.y = transform.height / 2;
	}

	if (transform.y + transform.height / 2 >= WIN_HEIGHT)
	{
		transform.y = WIN_HEIGHT - transform.height / 2;
	}

	if (transform.height > 0)
	{
		transform.height -= 0.5f;
	}

	transform.y += speed * moveVec;
}

void FeaverPoint::Draw()
{
	
	if (isDead)
	{
		DrawBox(transform.x - transform.width / 2, transform.y - transform.height / 2,
			transform.x + transform.width / 2, transform.y + transform.height / 2,
			GetColor(0, 255, 255), true);
	}

}

void FeaverPoint::Dead()
{
	isDead = false;
}

//“¾“_‰ÁŽZ
void FeaverPoint::OnCollisionScore(int feverCombo)
{
	score_ = feverCombo * 10 + scoreNum_;
}
