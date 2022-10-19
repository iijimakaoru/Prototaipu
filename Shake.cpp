#include"Shake.h"

void Shake::Init()
{
	randX = 0;
	randY = 0;
	randTimePlayer = 30;
	randTimeBackground = 30;
}

void Shake::Update()
{
	//各キーが押されたら、それぞれのシェイクフラグをONにする。（今回はキーごとに場合分けするので、フラグを２つ用意）
	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
	{
		isPlayerShaking = 1;
	}
	if (keys[KEY_INPUT_RETURN] == 1 && oldkeys[KEY_INPUT_RETURN] == 0)
	{
		isBackgroundShaking = 1;
	}

	//各シェイクフラグがONになったら乱数を取得する。(同じシェイクフラグを使うと片方が止まってしまうと両方止まるため）
	if (isPlayerShaking == 1)
	{
		//乱数タイマーを使い、タイマーの変数が減るごとに乱数を取得
		randTimePlayer--;

		if (randTimePlayer <= 30)
		{
			randX = GetRand(10) - 5;
			randY = GetRand(10) - 5;

			//タイマーが0になったらシェイクフラグと乱数タイマーをリセットする。
			if (randTimePlayer < 0)
			{
				randTimePlayer = 30;
				isPlayerShaking = 0;
			}
		}
	}
	if (isBackgroundShaking == 1)
	{
		//タイマーを使い、タイマーの変数が減るごとに乱数を取得
		randTimeBackground--;

		if (randTimeBackground <= 30)
		{
			randX = GetRand(10) - 5;
			randY = GetRand(10) - 5;

			//タイマーが0になったらシェイクフラグと乱数タイマーをリセットする。
			if (randTimeBackground < 0)
			{
				randTimeBackground = 30;
				isBackgroundShaking = 0;
			}
		}
	}

}