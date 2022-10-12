#include "Point.h"

void Point::Init(int posX)
{
	transform.x = posX;
	transform.y = WIN_HEIGHT / 2;
	transform.width = 8;
	transform.height = WIN_HEIGHT * 1 / 3;
	popPos = 0;
}

void Point::Update()
{
	popPos = GetRand(2);
}

void Point::Pop()
{
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
	//transform.y = GetRand(WIN_HEIGHT - transform.height) + transform.height / 2;
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
