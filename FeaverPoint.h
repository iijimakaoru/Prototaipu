#pragma once
#include "main.h"
#include "Struct.h"

class FeaverPoint
{
public:
	void Init();
	void Pop(int posX);
	void Update();
	void Draw();
	Transform GetTransform() { return transform; }
	void Dead();

private:
	Transform transform;
};

