#pragma once
#include "Struct.h"
#include "DxLib.h"
#include "main.h"

class Bom
{
public:
	void Init();
	void Update();
	void Draw();
	void IsAliveUpdate()
	{
		isAlive = true;
	}
	bool IsAlive()
	{
		if (isAlive)
		{
			return true;
		}
	
		return false;
	}

private:
	Transform transform;
	bool isAlive;
};

