#include "Point.h"

void Point::Init(int posX)
{
	transform.x = posX;
	transform.y = WIN_HEIGHT / 2;
	transform.width = 8;
	transform.height = WIN_HEIGHT * 1 / 3;
	popPos = 1;
	popVec = 0;
}

void Point::Update()
{
	
}

void Point::Pop()
{
	// Ç€Ç¡Ç’å¸Ç´éwíË
	popVec = GetRand(1);
	if (popVec == 1)
	{
		popPos++;
	}
	else if (popVec == 0)
	{
		popPos--;
	}
	// àÍî‘è„ÇÃéûàÍî‘â∫Ç÷
	if (popPos < 0)
	{
		popPos = 2;
	}
	// àÍî‘â∫ÇÃéûàÍî‘è„Ç÷
	if (popPos > 2)
	{
		popPos = 0;
	}
	// Ç€Ç¡Ç’èÍèäéwíË
	switch (popPos)
	{
	case 0:
		transform.y = WIN_HEIGHT * 1 / 6;
		break;
	case 1:
		transform.y = WIN_HEIGHT * 1 / 2;
		break;
	case 2:
		transform.y = WIN_HEIGHT * 5 / 6;
		break;
	default:
		break;
	}

	transform.height = WIN_HEIGHT * 1 / 3;
}

void Point::FeaverUpdate()
{
	transform.y = WIN_HEIGHT / 2;
	transform.height = WIN_HEIGHT;
}

void Point::Draw()
{
	DrawBox(transform.x - transform.width / 2, transform.y - transform.height / 2,
		transform.x + transform.width / 2, transform.y + transform.height / 2,
		GetColor(255, 0, 0), true);
}

//ìæì_â¡éZ
void Point::OnCollisionScore(int combo) 
{
	score = combo * 10 + scoreNum;
}