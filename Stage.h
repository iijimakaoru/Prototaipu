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
};

