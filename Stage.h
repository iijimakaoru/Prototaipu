#pragma once
#include "main.h"

class Stage
{
public:
	void Init();
	void Update();
	void Draw();
	int GetLeftX() { return leftX; }
	int GetRightX() { return rightX; }

private:
	int leftX;
	int rightX;
	float sikiriRightX[2];
	float sikiriRightY[2];
	float sikiriLeftX[2];
	float sikiriLeftY[2];
};

