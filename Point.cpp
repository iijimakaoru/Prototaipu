#include "Point.h"

void Point::Init(int posX)
{
	transform_.pos.x = posX;
	transform_.pos.y = WIN_HEIGHT / 2;
	transform_.width = 8;
	transform_.height = WIN_HEIGHT * 1 / 3;
	popPos_ = 1;
	popVec_ = 0;
}

void Point::Update()
{
	
}

void Point::Pop()
{
	// �ۂ��Ռ����w��
	popVec_ = GetRand(1);
	if (popVec_ == 1)
	{
		popPos_++;
	}
	else if (popVec_ == 0)
	{
		popPos_--;
	}
	// ��ԏ�̎���ԉ���
	if (popPos_ < 0)
	{
		popPos_ = 2;
	}
	// ��ԉ��̎���ԏ��
	if (popPos_ > 2)
	{
		popPos_ = 0;
	}
	// �ۂ��Տꏊ�w��
	switch (popPos_)
	{
	case 0:
		transform_.pos.y = WIN_HEIGHT * 1 / 6;
		break;
	case 1:
		transform_.pos.y = WIN_HEIGHT * 1 / 2;
		break;
	case 2:
		transform_.pos.y = WIN_HEIGHT * 5 / 6;
		break;
	default:
		break;
	}

	transform_.height = WIN_HEIGHT * 1 / 3;
}

void Point::FeaverUpdate()
{
	transform_.pos.y = WIN_HEIGHT / 2;
	transform_.height = WIN_HEIGHT;
}

void Point::Draw(int randX)
{
	DrawBox(transform_.pos.x - transform_.width / 2 + randX, transform_.pos.y - transform_.height / 2,
		transform_.pos.x + transform_.width / 2 + randX, transform_.pos.y + transform_.height / 2,
		GetColor(0, 255, 255), true);
}

//���_���Z
void Point::OnCollisionScore(int combo) 
{
	score_ = combo * 10 + scoreNum;
}