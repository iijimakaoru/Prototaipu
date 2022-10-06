#include "Point.h"

void Point::Init(int posX)
{
	transform.x = posX;
	transform.y = GetRand(WIN_HEIGHT - transform.height) + transform.height / 2;
	transform.width = 8;
	transform.height = 150;
}

void Point::Pop()
{
	transform.y = GetRand(WIN_HEIGHT - transform.height) + transform.height / 2;
	transform.height = 150;
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
