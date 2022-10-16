#include "Particle.h"

void Particle::Init(const Vector2& pos, const Vector2& velocity)
{
	transform_.pos = pos;
	transform_.width = 10;
	transform_.height = 10;
	moveVec_ = velocity;
}

void Particle::Update()
{
	transform_.pos += moveVec_;

	if (--transform_.width <= 0 &&
		--transform_.height <= 0)
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
