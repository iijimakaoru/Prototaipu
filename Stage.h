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
	void Damage() { HP--; }
	bool IsAlive() 
	{
		if (isAlive)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int StageHP() { return HP; }

private:
	int leftX_;
	int rightX_;
	float sikiriRightX_[2];
	float sikiriRightY_[2];
	float sikiriLeftX_[2];
	float sikiriLeftY_[2];

	int HP;

	bool isAlive;
};

