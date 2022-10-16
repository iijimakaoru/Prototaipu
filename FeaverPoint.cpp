#include "FeaverPoint.h"

void FeaverPoint::Init()
{
	transform_.x = 114514;
	transform_.width = 8;
	transform_.height = 100;
	isDead_ = false;
	speed_ = 4;
	moveVec_ = 1;
}

void FeaverPoint::Pop(int posX)
{
	transform_.x = posX;
	transform_.y = GetRand(WIN_HEIGHT - transform_.height) + transform_.height / 2;
	transform_.height = 100;
	isDead_ = true;
}

void FeaverPoint::Update()
{
	if (transform_.y + transform_.height / 2 >= WIN_HEIGHT ||
		transform_.y - transform_.height / 2 <= 0)
	{
		moveVec_ *= -1;
	}

	if (transform_.y - transform_.height / 2 <= 0)
	{
		transform_.y = transform_.height / 2;
	}

	if (transform_.y + transform_.height / 2 >= WIN_HEIGHT)
	{
		transform_.y = WIN_HEIGHT - transform_.height / 2;
	}

	if (transform_.height > 0)
	{
		transform_.height -= 0.5f;
	}

	transform_.y += speed_ * moveVec_;
}

void FeaverPoint::Draw()
{
	
	if (isDead_)
	{
		DrawBox(transform_.x - transform_.width / 2, transform_.y - transform_.height / 2,
			transform_.x + transform_.width / 2, transform_.y + transform_.height / 2,
			GetColor(0, 255, 255), true);
	}

}

void FeaverPoint::Dead()
{
	isDead_ = false;
}

//���_���Z
void FeaverPoint::OnCollisionScore(int feverCombo)
{
	score_ = feverCombo * 10 + scoreNum_;
}
