#pragma once
#include "Struct.h"

class Particle
{
public:
	void Init(const Vector2& pos, const Vector2& velocity);
private:
	Transform transform_;
};

