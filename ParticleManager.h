#pragma once
#include <list>
#include <memory>
#include "Particle.h"
#include "SmollParticle.h"
#include "MyMath.h"

class ParticleManager
{
public:
	void Init();
	void Update();
	void Draw();
	// ���ǎ��̃_�b�V��
	void LeftDash(const float posX, const float posY);
	// �E�ǎ��̃_�b�V��
	void RightDash(const float posX, const float posY);
	// �ԃ|�C���g�A�G�̌��j���o
	void Clash(const float posX, const float posY);
	// �t�B�[�o�[�_�̉��o
	void FeaverClash(const float posX, const float posY);
	// 
	void Dash(const float posX, const float posY);

	void EnemysAndWall(const float posX, const float posY);

private:
	std::list<std::unique_ptr<Particle>> particles_;
	std::list<std::unique_ptr<SmollParticle>> smollParticles_;

	float angleMax;
	float angle;
	const int RANDOM_MAX = 60;
};

