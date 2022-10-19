#pragma once

class  Shake
{
public:
	 Shake();
	~ Shake();

	void Init();
	void Update();

private:

	//乱数用の変数
	int randX;
	int randY;
	int randTimePlayer;
	int randTimeBackground;

	//シェイクされているかどうか
	//自機のシェイク
	int isPlayerShaking = 0;
	//背景のシェイク
	int isBackgroundShaking = 0;

};

 Shake:: Shake()
{
}

 Shake::~ Shake()
{
}

 
