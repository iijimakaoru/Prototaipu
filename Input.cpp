#include "Input.h"

Input::Input() {}

void Input::Init()
{
	keys_ = new char[keyNumLimit];

	oldkeys_ = new char[keyNumLimit];

	for (int i = 0; i < keyNumLimit; i++)
	{
		keys_[i] = 0;
		oldkeys_[i] = 0;
	}
}

void Input::KeyInit()
{
	for (int i = 0; i < keyNumLimit; i++)
	{
		oldkeys_[i] = keys_[i];
	}
	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys_);
}

bool Input::isPush(int keyNum)
{
	if (keys_[keyNum])return true;

	return false;
}

bool Input::isNPush(int keyNum)
{
	if (!keys_[keyNum])return true;

	return false;
}

bool Input::isPress(int keyNum)
{
	if (keys_[keyNum] && oldkeys_[keyNum])return true;

	return false;
}

bool Input::isTriger(int keyNum)
{
	if (keys_[keyNum] && !oldkeys_[keyNum])return true;

	return false;
}

bool Input::isRelease(int keyNum)
{
	if (!keys_[keyNum] && oldkeys_[keyNum])return true;

	return false;
}