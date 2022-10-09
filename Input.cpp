#include "Input.h"

Input::Input() {}

void Input::Init()
{
	keys = new char[keyNumLimit];

	oldkeys = new char[keyNumLimit];

	for (int i = 0; i < keyNumLimit; i++)
	{
		keys[i] = 0;
		oldkeys[i] = 0;
	}
}

void Input::KeyInit()
{
	for (int i = 0; i < keyNumLimit; i++)
	{
		oldkeys[i] = keys[i];
	}
	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys);
}

bool Input::isPush(int keyNum)
{
	if (keys[keyNum])return true;

	return false;
}

bool Input::isNPush(int keyNum)
{
	if (!keys[keyNum])return true;

	return false;
}

bool Input::isPress(int keyNum)
{
	if (keys[keyNum] && oldkeys[keyNum])return true;

	return false;
}

bool Input::isTriger(int keyNum)
{
	if (keys[keyNum] && !oldkeys[keyNum])return true;

	return false;
}

bool Input::isRelease(int keyNum)
{
	if (!keys[keyNum] && oldkeys[keyNum])return true;

	return false;
}