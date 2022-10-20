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
	// 左壁時のダッシュ
	void LeftDash(const float posX, const float posY);
	// 右壁時のダッシュ
	void RightDash(const float posX, const float posY);
	// 赤ポイント、敵の撃破演出
	void Clash(const float posX, const float posY);
	// フィーバー棒の演出
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

