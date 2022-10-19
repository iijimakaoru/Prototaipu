#include "FeaverPoint.h"

void FeaverPoint::Init()
{
	transform_.pos.x = 114514;
	transform_.width = 8;
	transform_.height = 100;
	isDead_ = false;
	speed_ = 4;
	moveVec_ = 1;
}

void FeaverPoint::Pop(int posX)
{
	transform_.pos.x = posX;
	transform_.pos.y = GetRand(WIN_HEIGHT - transform_.height) + transform_.height / 2;
	transform_.height = 100;
	isDead_ = true;
}

void FeaverPoint::Update()
{
	if (transform_.pos.y + transform_.height / 2 >= WIN_HEIGHT ||
		transform_.pos.y - transform_.height / 2 <= 0)
	{
		moveVec_ *= -1;
	}

	if (transform_.pos.y - transform_.height / 2 <= 0)
	{
		transform_.pos.y = transform_.height / 2;
	}

	if (transform_.pos.y + transform_.height / 2 >= WIN_HEIGHT)
	{
		transform_.pos.y = WIN_HEIGHT - transform_.height / 2;
	}
	// ¬‚³‚­‚È‚éˆ—
	if (transform_.height > 0)
	{
		transform_.height -= 0.02f;
	}

	//transform_.pos.y += speed_ * moveVec_;
}

void FeaverPoint::Draw()
{	
	if (isDead_)
	{
		DrawBox(transform_.pos.x - transform_.width / 2, transform_.pos.y - transform_.height / 2,
			transform_.pos.x + transform_.width / 2, transform_.pos.y + transform_.height / 2,
			GetColor(255, 255, 0), true);
	}
}

void FeaverPoint::Dead()
{
	isDead_ = false;
}

//“¾“_‰ÁŽZ
void FeaverPoint::OnCollisionScore(int feverCombo)
{
	score_ = feverCombo * 10 + scoreNum_;
}
