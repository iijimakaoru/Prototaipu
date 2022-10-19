#include"Shake.h"
#include "DxLib.h"

void Shake::Init()
{
	randX = 0;
	randY = 0;
	randTimePlayer = 30;
	randTimeBackground = 30;
	isShaking = 0;
}

void Shake::Update()
{
	if (isShaking == 0)
	{
		randX = 0;
		randY = 0;
	}

	//各シェイクフラグがONになったら乱数を取得する。(同じシェイクフラグを使うと片方が止まってしまうと両方止まるため）
	if (isShaking == 1)
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
				isShaking = 0;
			}
		}
	}
}

//各キーが押されたら、それぞれのシェイクフラグをONにする。（今回はキーごとに場合分けするので、フラグを２つ用意）
void Shake::OnCollisionShake()
{
	isShaking = 1;
}
