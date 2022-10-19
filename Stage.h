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

	//シェイクされているかどうか
	//背景のシェイク
	int isBackgroundShaking = 0;
};

