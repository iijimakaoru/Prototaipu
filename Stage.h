#pragma once
#include "main.h"

class Stage
{
public:
	void Init();
	void Update();
	void Draw();
	int GetLeftX() { return leftX_; }
	int GetRightX() { return rightX_; }

private:
	int leftX_;
	int rightX_;
	float sikiriRightX_[2];
	float sikiriRightY_[2];
	float sikiriLeftX_[2];
	float sikiriLeftY_[2];

	//�V�F�C�N����Ă��邩�ǂ���
	//�w�i�̃V�F�C�N
	int isBackgroundShaking = 0;
};

