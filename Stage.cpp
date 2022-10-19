#include "Stage.h"

void Stage::Init()
{
	// ��{��
	leftX_ = WIN_WIDTH / 4;
	rightX_ = WIN_WIDTH * 3 / 4;
	// �d�؂��
	for (int i = 0; i < 2; i++)
	{
		sikiriRightX_[i] = rightX_;
		sikiriLeftX_[i] = leftX_;
	}
	sikiriRightY_[0] = sikiriLeftY_[0] = WIN_HEIGHT * 1 / 3;
	sikiriRightY_[1] = sikiriLeftY_[1] = WIN_HEIGHT * 2 / 3;

	HP = 3;

	isAlive = true;
}

void Stage::Update()
{
	if (HP <= 0)
	{
		isAlive = false;
	}
}

void Stage::Draw()
{
	if (isAlive)
	{
		DrawLine(leftX_, 0, leftX_, WIN_HEIGHT, GetColor(255, 255, 255), true);
		DrawLine(rightX_, 0, rightX_, WIN_HEIGHT, GetColor(255, 255, 255), true);
		for (int i = 0; i < 2; i++)
		{
			DrawLine(sikiriRightX_[i] - 4, sikiriRightY_[i], sikiriRightX_[i] + 4, sikiriRightY_[i], GetColor(255, 255, 255), true);
			DrawLine(sikiriLeftX_[i] - 4, sikiriLeftY_[i], sikiriLeftX_[i] + 4, sikiriLeftY_[i], GetColor(255, 255, 255), true);
		}
	}
}
