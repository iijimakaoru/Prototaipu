#pragma once
#include "main.h"
#include "Struct.h"

class Point
{
public:
	void Init(int posX);
	void Update();
	void Pop();
	void FeaverUpdate();
	void Draw();
	Transform GetTransform() { return transform; }
	int GetScore() { return score; }

	void OnCollisionScore(int combo);

private:
	Transform transform;
	int popPos;
	int popVec;
	//“¾“_
	const int scoreNum = 100;
	int score;
};

