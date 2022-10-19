#include "SmollParticle.h"

void SmollParticle::Init(const float posX, const float posY, const Vector2& velocity, unsigned int color)
{
	transform_.pos.x = posX;
	transform_.pos.y = posY;
	transform_.width = 10;
	transform_.height = 10;
	moveVec_ = velocity;
	color_ = color;
}

void SmollParticle::Update()
{
	transform_.pos += moveVec_;

	transform_.width--;
	transform_.height--;

	if (transform_.width <= 0 &&
		transform_.height <= 0)
	{
		isDead_ = true;
	}
}

void SmollParticle::Draw()
{
	DrawBox(transform_.pos.x - transform_.width / 2, transform_.pos.y - transform_.height / 2,
		transform_.pos.x + transform_.width / 2, transform_.pos.y + transform_.height / 2,
		color_, true);
}
