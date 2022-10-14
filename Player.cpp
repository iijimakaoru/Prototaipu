#include "Player.h"

void Player::Init(Stage& stage)
{
	transform_.x = stage.GetLeftX() + transform_.width / 2;
	transform_.y = transform_.height / 2 + 1;
	transform_.width = transform_.height = 20;
	isChange_ = false;
	speed_ = 5;
	speedLevel_ = 1;
	levelupCount_ = 0;
	moveVec_ = 1;
	levelDownCount_ = 0;
}

void Player::Update(Stage& stage, Input& input)
{
	// スピードアップ処理
	if (levelupCount_ >= 3 && speedLevel_ <= 3)
	{
		speedLevel_++;
		levelupCount_ = 0;
		levelDownCount_ = 0;
	}
	// スピードダウン処理
	if (levelDownCount_ >= 3 && speedLevel_ > 1)
	{
		speedLevel_--;
		levelDownCount_ = 0;
		levelupCount_ = 0;
	}
#pragma region レベルによっての速度設定
	if (speedLevel_ == 1)
	{
		speed_ = 5;
	}
	else if (speedLevel_ == 2)
	{
		speed_ = 7;
	}
	else if (speedLevel_ == 3)
	{
		speed_ = 9;
	}
#pragma endregion
	// 壁を跳んでないとき
	if (!isChange_)
	{
		if (transform_.y - transform_.height / 2 <= 0 ||
			transform_.y + transform_.height / 2 >= WIN_HEIGHT)
		{
			moveVec_ *= -1;
		}

		transform_.y += speed_ * moveVec_;

		isAddCount_ = false;
	}
	// 壁を跳んでるとき
	else
	{
		if (vec_ == Vec::LEFT)
		{
			transform_.x += 80;
		}
		if (vec_ == Vec::RIGHT)
		{
			transform_.x -= 80;
		}
	}
	// 壁跳び移り
	if (input.isTriger(KEY_INPUT_SPACE) && !isChange_)
	{
		isChange_ = true;
		isAddCount_ = true;
	}
#pragma region 壁の押し戻し処理
	if (transform_.x - transform_.width / 2 <= stage.GetLeftX())
	{
		transform_.x = (stage.GetLeftX() + transform_.width / 2) + 1;
		if (vec_ == Vec::RIGHT)
		{
			vec_ = Vec::LEFT;
		}
		isChange_ = false;
	}

	if (transform_.x + transform_.width / 2 >= stage.GetRightX())
	{
		transform_.x = (stage.GetRightX() - transform_.width / 2) - 1;
		if (vec_ == Vec::LEFT)
		{
			vec_ = Vec::RIGHT;
		}
		isChange_ = false;
	}

	if (transform_.y - transform_.height / 2 <= 0)
	{
		transform_.y = transform_.height / 2;
	}
	else if (transform_.y + transform_.height / 2 >= WIN_HEIGHT)
	{
		transform_.y = WIN_HEIGHT - transform_.height / 2;
	}
#pragma endregion
}

void Player::Draw()
{
	DrawBox(transform_.x - transform_.width / 2, transform_.y - transform_.height / 2,
		transform_.x + transform_.width / 2, transform_.y + transform_.height / 2,
		GetColor(200, 200, 200), true);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "%d", levelupCount_);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%d", levelDownCount_);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", speedLevel_);
}
