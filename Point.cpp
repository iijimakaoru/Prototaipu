#include "Point.h"

void Point::Init(int posX)
{
	transform.x = posX;
	transform.y = WIN_HEIGHT / 2;
	transform.width = 8;
	transform.height = WIN_HEIGHT * 1 / 3;
	popPos = 0;
	popVec = 0;
}

void Point::Update()
{
	
}

void Point::Pop()
{
	// ぽっぷ向き指定
	popVec = GetRand(1);
	if (popVec == 1)
	{
		popPos++;
	}
	else if (popVec == 0)
	{
		popPos--;
	}
	// 一番上の時一番下へ
	if (popPos < 0)
	{
		popPos = 2;
	}
	// 一番下の時一番上へ
	if (popPos > 2)
	{
		popPos = 0;
	}
	// ぽっぷ場所指定
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
