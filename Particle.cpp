#include "Particle.h"

void Particle::Init(const float posX, const float posY, const Vector2& velocity)
{
	transform_.pos.x = posX;
	transform_.pos.y = posY;
	transform_.width = 30;
	transform_.height = 30;
	moveVec_ = velocity;
}

void Particle::Update()
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

void Particle::Draw()
{
	DrawBox(transform_.pos.x - transform_.width / 2, transform_.pos.y - transform_.height / 2,
		transform_.pos.x + transform_.width / 2, transform_.pos.y + transform_.height / 2,
		GetColor(200, 200, 200), true);
}
