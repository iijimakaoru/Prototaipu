#pragma once
#include "main.h"

class Stage
{
public:
	void Init();
	void Update();
	void Draw(int randX, int randY);
	int GetLeftX() { return leftX_; }
	int GetRightX() { return rightX_; }
	int GetStageHP() { return HP; }
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

