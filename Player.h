#pragma once
#include "main.h"
#include "Stage.h"
#include "Struct.h"
#include "Input.h"

class Player
{
public:
	enum class Vec
	{
		LEFT,
		RIGHT
	};
	void Init(Stage& stage);
	void Update(Stage& stage, Input& input);
	void Draw();
	Transform GetTransform() { return transform; }
	bool GetIsChange() { return isChange; }
	bool Left() { return vec == Vec::LEFT; }
	bool Right() { return vec == Vec::RIGHT; }
	void AddLevelupCount() 
	{
		if (speedLevel < 3)
		{
			levelupCount++;
		}
	}

private:
	Transform transform;
	bool isChange = false;
	Vec vec = Vec::LEFT;
	int speed;
	int speedLevel;
	int levelupCount;
	bool isSpeedUP = false;
};

