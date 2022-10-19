#pragma once

class  Shake
{
public:
	void Init();
	void Update();
	void OnCollisionShake();
	int GetRandX() { return randX; }
	int GetRandY() { return randY; }
	int GetisShaking() { return isShaking; }

private:

	//乱数用の変数
	int randX;
	int randY;
	int randTimePlayer;
	int randTimeBackground;

	//シェイクされているかどうか
	//自機のシェイク
	int isShaking = 0;

};

 
