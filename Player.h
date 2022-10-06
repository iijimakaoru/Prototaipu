#pragma once
#include "main.h"
#include "Stage.h"
#include "Struct.h"

class Player
{
public:
	enum class Vec
	{
		LEFT,
		RIGHT
	};
	void Init(Stage& stage);
	void Update(Stage& stage);
	void Draw();
	Transform GetTransform() { return transform; }
	bool GetIsChange() { return isChange; }
	bool Left() { return vec == Vec::LEFT; }
	bool Right() { return vec == Vec::RIGHT; }

private:
	Transform transform;
	bool isChange = false;
	Vec vec = Vec::LEFT;
};

