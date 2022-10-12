#include "Stage.h"

void Stage::Init()
{
	leftX = WIN_WIDTH / 4;
	rightX = WIN_WIDTH * 3 / 4;
	for (int i = 0; i < 2; i++)
	{
		sikiriRightX[i] = rightX;
		sikiriLeftX[i] = leftX;
	}
	sikiriRightY[0] = sikiriLeftY[0] = WIN_HEIGHT * 1 / 3;
	sikiriRightY[1] = sikiriLeftY[1] = WIN_HEIGHT * 2 / 3;
}

void Stage::Update()
{

}

void Stage::Draw()
{
	DrawLine(leftX, 0, leftX, WIN_HEIGHT, GetColor(255, 255, 255), true);
	DrawLine(rightX, 0, rightX, WIN_HEIGHT, GetColor(255, 255, 255), true);
	for (int i = 0; i < 2; i++)
	{
		DrawLine(sikiriRightX[i] - 4, sikiriRightY[i], sikiriRightX[i] + 4, sikiriRightY[i], GetColor(255, 255, 255), true);
		DrawLine(sikiriLeftX[i] - 4, sikiriLeftY[i], sikiriLeftX[i] + 4, sikiriLeftY[i], GetColor(255, 255, 255), true);
	}
}
