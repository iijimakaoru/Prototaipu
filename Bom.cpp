#include "Bom.h"

void Bom::Init()
{
	transform.pos.x = WIN_WIDTH / 2;
	transform.pos.y = WIN_HEIGHT / 2;
	transform.width = 0;
	transform.height = 0;
	isAlive = true;
}

void Bom::Update()
{
	transform.width += 20;

	if (transform.width >= WIN_WIDTH)
	{
		isAlive = false;
	}
}

void Bom::Draw()
{
	if (isAlive)
	{
		DrawCircle(transform.pos.x, transform.pos.y, transform.width,
			GetColor(255, 255, 0), false);
	}
}
