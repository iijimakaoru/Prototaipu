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
	// �ŐV�̃L�[�{�[�h���p
	char* keys;
	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char* oldkeys;
};

