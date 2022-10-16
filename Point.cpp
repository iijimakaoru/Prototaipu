#include "Point.h"

void Point::Init(int posX)
{
	transform_.pos.x = posX;
	transform_.pos.y = WIN_HEIGHT / 2;
	transform_.size.x = 8;
	transform_.size.y = WIN_HEIGHT * 1 / 3;
	popPos_ = 1;
	popVec_ = 0;
}

void Point::Update()
{
	
}

void Point::Pop()
{
	// Ç€Ç¡Ç’å¸Ç´éwíË
	popVec_ = GetRand(1);
	if (popVec_ == 1)
	{
		popPos_++;
	}
	else if (popVec_ == 0)
	{
		popPos_--;
	}
	// àÍî‘è„ÇÃéûàÍî‘â∫Ç÷
	if (popPos_ < 0)
	{
		popPos_ = 2;
	}
	// àÍî‘â∫ÇÃéûàÍî‘è„Ç÷
	if (popPos_ > 2)
	{
		popPos_ = 0;
	}
	// Ç€Ç¡Ç’èÍèäéwíË
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

	transform_.size.y = WIN_HEIGHT * 1 / 3;
}

void Point::FeaverUpdate()
{
	transform_.pos.y = WIN_HEIGHT / 2;
	transform_.size.y = WIN_HEIGHT;
}

void Point::Draw()
{
	DrawBox(transform_.pos.x - transform_.size.x / 2, transform_.pos.y - transform_.size.y / 2,
		transform_.pos.x + transform_.size.x / 2, transform_.pos.y + transform_.size.y / 2,
		GetColor(255, 0, 0), true);
}

//ìæì_â¡éZ
void Point::OnCollisionScore(int combo) 
{
	score_ = combo * 10 + scoreNum;
}