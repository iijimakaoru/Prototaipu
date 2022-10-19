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
	void Draw(int randX);
	Transform GetTransform() { return transform_; }
	int GetScore() { return score_; }

	void OnCollisionScore(int combo);

private:
	Transform transform_;
	int popPos_;
	int popVec_;
	//“¾“_
	const int scoreNum = 100;
	int score_;
};

