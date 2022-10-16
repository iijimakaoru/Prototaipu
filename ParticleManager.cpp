#include "ParticleManager.h"

void ParticleManager::Init()
{
}

void ParticleManager::Update()
{
	particles_.remove_if([](std::unique_ptr<Particle>& particle) {return particle->IsDead(); });

	for (std::unique_ptr<Particle>& particle : particles_)
	{
		particle->Update();
	}
}

void ParticleManager::Draw()
{
	for (std::unique_ptr<Particle>& particle : particles_)
	{
		particle->Draw();
	}
}

void ParticleManager::Dash(const Vector2& pos)
{
	Vector2 velocity[3];
	velocity[0] = { 4.75f, 4.75f };
	velocity[1] = { 5.0f, 0.0f };
	velocity[2] = { 4.75f,-4.75f };

	for (int i = 0; i < 3; i++)
	{
		std::unique_ptr<Particle> newParticle = std::make_unique<Particle>();
		newParticle->Init(pos, velocity[i]);

		particles_.push_back(std::move(newParticle));
	}
}
