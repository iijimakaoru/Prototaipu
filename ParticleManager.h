#pragma once
#include <list>
#include <memory>
#include "Particle.h"

class ParticleManager
{
public:
	void Init();
	void Update();
	void Draw();
	void Dash(const Vector2& pos);

private:
	std::list<std::unique_ptr<Particle>> particles_;
};

