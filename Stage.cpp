#include "Stage.h"

void Stage::Init()
{
	leftX = WIN_WIDTH / 4;
	rightX = WIN_WIDTH * 3 / 4;
}

void Stage::Update()
{

}

void Stage::Draw()
{
	DrawLine(leftX, 0, leftX, WIN_HEIGHT, GetColor(255, 255, 255), true);
	DrawLine(rightX, 0, rightX, WIN_HEIGHT, GetColor(255, 255, 255), true);
}
