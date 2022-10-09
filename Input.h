#pragma once
#include "DxLib.h"

const int keyNumLimit = 256;

class Input
{
public:
	Input();
	void Init();
	void KeyInit();
	bool isPush(int keyNum);
	bool isNPush(int keyNum);
	bool isPress(int keyNum);
	bool isTriger(int keyNum);
	bool isRelease(int keyNum);

private:
	// 最新のキーボード情報用
	char* keys;
	// 1ループ(フレーム)前のキーボード情報
	char* oldkeys;
};

