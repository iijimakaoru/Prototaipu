#include "Player.h"

void Player::Init(Stage& stage)
{
	transform.x = stage.GetLeftX() + transform.width / 2;
	transform.y = transform.height / 2 + 1;
	transform.width = transform.height = 20;
	isChange = false;
	speed = 5;
	speedLevel = 1;
	levelupCount = 0;
	isSpeedUP = false;
	moveVec = 1;
	levelDownCount = 0;
}

void Player::Update(Stage& stage, Input& input)
{
	// スピードアップ処理
	if (levelupCount >= 3 && speedLevel <= 3)
	{
		speedLevel++;
		levelupCount = 0;
		levelDownCount = 0;
	}
	// スピードダウン処理
	if (levelDownCount >= 3 && speedLevel > 1)
	{
		speedLevel--;
		levelDownCount = 0;
		levelupCount = 0;
	}
#pragma region レベルによっての速度設定
	if (speedLevel == 1)
	{
		speed = 5;
	}
	else if (speedLevel == 2)
	{
		speed = 7;
	}
	else if (speedLevel == 3)
	{
		speed = 9;
	}
#pragma endregion
	// 壁を跳んでないとき
	if (!isChange)
	{
		if (transform.y - transform.height / 2 <= 0 ||
			transform.y + transform.height / 2 >= WIN_HEIGHT)
		{
			moveVec *= -1;
		}

		transform.y += speed * moveVec;

		isAddCount = false;
	}
	// 壁を跳んでるとき
	else
	{
		if (vec == Vec::LEFT)
		{
			transform.x += 80;
		}
		if (vec == Vec::RIGHT)
		{
			transform.x -= 80;
		}
	}
	// 壁跳び移り
	if (input.isTriger(KEY_INPUT_SPACE) && !isChange)
	{
		isChange = true;
		isAddCount = true;
	}
#pragma region 壁の押し戻し処理
	if (transform.x - transform.width / 2 <= stage.GetLeftX())
	{
		transform.x = (stage.GetLeftX() + transform.width / 2) + 1;
		if (vec == Vec::RIGHT)
		{
			vec = Vec::LEFT;
		}
		isChange = false;
	}

	if (transform.x + transform.width / 2 >= stage.GetRightX())
	{
		transform.x = (stage.GetRightX() - transform.width / 2) - 1;
		if (vec == Vec::LEFT)
		{
			vec = Vec::RIGHT;
		}
		isChange = false;
	}

	if (transform.y - transform.height / 2 <= 0)
	{
		transform.y = transform.height / 2;
	}
	else if (transform.y + transform.height / 2 >= WIN_HEIGHT)
	{
		transform.y = WIN_HEIGHT - transform.height / 2;
	}
#pragma endregion
}

void Player::Draw()
{
	DrawBox(transform.x - transform.width / 2, transform.y - transform.height / 2,
		transform.x + transform.width / 2, transform.y + transform.height / 2,
		GetColor(200, 200, 200), true);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "%d", levelupCount);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%d", levelDownCount);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", speedLevel);
}
