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

private:
	Transform transform;
	int popPos;
	int popVec;
};

