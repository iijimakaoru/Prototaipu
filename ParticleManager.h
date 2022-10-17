#pragma once
#include <list>
#include <memory>
#include "Particle.h"
#include "MyMath.h"

class ParticleManager
{
public:
	void Init();
	void Update();
	void Draw();
	void LeftDash(const float posX, const float posY);
	void RightDash(const float posX, const float posY);
	void Clash(const float posX, const float posY);
	void FeaverClash(const float posX, const float posY);

private:
	std::list<std::unique_ptr<Particle>> particles_;

	float angleMax;
	float angle;
	const int RANDOM_MAX = 60;
};

