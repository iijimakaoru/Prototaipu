#include "ParticleManager.h"

void ParticleManager::Init()
{

}

void ParticleManager::Update()
{
	particles_.remove_if([](std::unique_ptr<Particle>& particle) {return particle->IsDead(); });
	smollParticles_.remove_if([](std::unique_ptr<SmollParticle>& smollParticles) {return smollParticles->IsDead(); });

	for (std::unique_ptr<Particle>& particle : particles_)
	{
		particle->Update();
	}

	for (std::unique_ptr<SmollParticle>& smollParticles : smollParticles_)
	{
		smollParticles->Update();
	}
}

void ParticleManager::Draw()
{
	for (std::unique_ptr<Particle>& particle : particles_)
	{
		particle->Draw();
	}

	for (std::unique_ptr<SmollParticle>& smollParticles : smollParticles_)
	{
		smollParticles->Draw();
	}
}

void ParticleManager::LeftDash(const float posX, const float posY)
{
	unsigned int color = GetColor(200, 200, 200);

	for (int i = 0; i < 15; i++)
	{
		angleMax = MyMath::PI / 6.0f;
		float halfAngle = angleMax / 2.0f;
		int rand = GetRand(RANDOM_MAX);
		angle = angleMax * rand / (float)RANDOM_MAX - halfAngle;

		float speed = 4;

		Vector2 velocity = { -speed * cosf(angle), speed * sinf(angle) };

		std::unique_ptr<SmollParticle> newParticle = std::make_unique<SmollParticle>();
		newParticle->Init(posX, posY, velocity, color);

		smollParticles_.push_back(std::move(newParticle));
	}
}

void ParticleManager::RightDash(const float posX, const float posY)
{
	unsigned int color = GetColor(200, 200, 200);

	for (int i = 0; i < 15; i++)
	{
		angleMax = MyMath::PI / 6.0f;
		float halfAngle = angleMax / 2.0f;
		int rand = GetRand(RANDOM_MAX);
		angle = angleMax * rand / (float)RANDOM_MAX - halfAngle;

		float speed = 4;

		Vector2 velocity = { speed * cosf(angle), speed * sinf(angle) };

		std::unique_ptr<SmollParticle> newParticle = std::make_unique<SmollParticle>();
		newParticle->Init(posX, posY, velocity, color);

		smollParticles_.push_back(std::move(newParticle));
	}
}

void ParticleManager::Clash(const float posX, const float posY)
{
	unsigned int color = GetColor(0, 255, 255);

	for (int i = 0; i < 10; i++)
	{
		angleMax = MyMath::PI / 6.0f;
		float halfAngle = angleMax / 2.0f;
		int rand = GetRand(RANDOM_MAX);
		angle = angleMax * rand / (float)RANDOM_MAX - halfAngle;

		float speed = 4;

		Vector2 velocity = { -speed * cosf(rand), speed * sinf(rand) };

		std::unique_ptr<Particle> newParticle = std::make_unique<Particle>();
		newParticle->Init(posX, posY, velocity, color);

		particles_.push_back(std::move(newParticle));
	}
}

void ParticleManager::FeaverClash(const float posX, const float posY)
{
	unsigned int color = GetColor(255, 255, 0);

	for (int i = 0; i < 10; i++)
	{
		angleMax = MyMath::PI / 6.0f;
		float halfAngle = angleMax / 2.0f;
		int rand = GetRand(RANDOM_MAX);
		angle = angleMax * rand / (float)RANDOM_MAX - halfAngle;

		float speed = 4;

		Vector2 velocity = { speed * cosf(rand), speed * sinf(rand) };

		std::unique_ptr<Particle> newParticle = std::make_unique<Particle>();
		newParticle->Init(posX, posY, velocity, color);

		particles_.push_back(std::move(newParticle));
	}
}

void ParticleManager::Dash(const float posX, const float posY)
{
	unsigned int color = GetColor(255, 255, 255);

	Vector2 velocity = { 0,0 };

	std::unique_ptr<Particle> newParticle = std::make_unique<Particle>();
	newParticle->Init(posX, posY, velocity, color);

	particles_.push_back(std::move(newParticle));
}

void ParticleManager::EnemysAndWall(const float posX, const float posY)
{
	unsigned int color = GetColor(255, 255, 255);

	for (int i = 0; i < 10; i++)
	{
		angleMax = MyMath::PI / 6.0f;
		float halfAngle = angleMax / 2.0f;
		int rand = GetRand(RANDOM_MAX);
		angle = angleMax * rand / (float)RANDOM_MAX - halfAngle;

		float speed = 8;

		Vector2 velocity = { speed * cosf(rand), speed * sinf(rand) };

		std::unique_ptr<Particle> newParticle = std::make_unique<Particle>();
		newParticle->Init(posX, posY, velocity, color);

		particles_.push_back(std::move(newParticle));
	}
}
