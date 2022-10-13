#pragma once
#include "main.h"
#include "Struct.h"

class FeaverPoint
{
public:
	void Init();
	void Pop(int posX);
	void Update();
	void Draw();
	Transform GetTransform() { return transform; }
	int GetScore() { return score_; }
	void Dead();
	bool IsDead() { return isDead; }
	int GetFeverCombo_() { return feverCombo_; }
	void OnCollisionScore(int feverCombo);

private:
	Transform transform;
	bool isDead;
	float speed;
	int moveVec;
	//�t�B�[�o�[�R���{
	int feverCombo_;
	//�t�B�[�o�[�̌Œ蓾�_
	const int scoreNum_ = 50;
	//�t�B�[�o�[�̓��_
	int score_;
};

