#include "FeaverPoint.h"

void FeaverPoint::Init()
{
	transform.x = 114514;
	transform.width = 8;
	transform.height = 100;
}

void FeaverPoint::Pop(int posX)
{
	transform.x = posX;
	transform.y = GetRand(WIN_HEIGHT - transform.height) + transform.height / 2;
	transform.height = 100;
}

void FeaverPoint::Update()
{
	transform.y -= 2;
	if (transform.y - transform.height / 2 >= WIN_HEIGHT)
	{
		transform.y = -transform.height / 2;
	}
	else if (transform.y + transform.height / 2 <= 0)
	{
		transform.y = WIN_HEIGHT + transform.height / 2;
	}
	if (transform.height > 0)
	{
		transform.height -= 0.5f;
	}
}

void FeaverPoint::Draw()
{
	DrawBox(transform.x - transform.width / 2, transform.y - transform.height / 2,
		transform.x + transform.width / 2, transform.y + transform.height / 2,
		GetColor(0, 255, 255), true);
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%f", transform.height);
}

void FeaverPoint::Dead()
{
	transform.x = -114514;
	transform.y = -114514;
}
