#include "Player.h"

void Player::Init(Stage& stage)
{
	transform_.pos.x = stage.GetLeftX() + transform_.width / 2;
	transform_.pos.y = transform_.height / 2 + 1;
	transform_.width = transform_.height = 20;
	isChange_ = false;
	speed_ = 5;
	speedLevel_ = 1;
	levelupCount_ = 0;
	moveVec_ = 1;
	levelDownCount_ = 0;
	vec_ = Vec::LEFT;
	ranpuTimer = 30;
	isFlash = 0;
	ranpuTimer = 10;
}

void Player::Update(Stage& stage, Input& input, ParticleManager& partManager)
{
	isInpact_ = false;
	// �X�s�[�h�A�b�v����
	if (levelupCount_ >= 3 && speedLevel_ <= 3)
	{
		speedLevel_++;
		levelupCount_ = 0;
		levelDownCount_ = 0;
	}
	// �X�s�[�h�_�E������
	if (levelDownCount_ >= 3 && speedLevel_ > 1)
	{
		speedLevel_--;
		levelDownCount_ = 0;
		levelupCount_ = 0;
	}
#pragma region ���x���ɂ���Ă̑��x�ݒ�
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
	// �ǂ𒵂�łȂ��Ƃ�
	if (!isChange_)
	{
		if (transform_.pos.y - transform_.height / 2 <= 0 ||
			transform_.pos.y + transform_.height / 2 >= WIN_HEIGHT)
		{
			moveVec_ *= -1;
		}

		// �ǒ��шڂ�
		if (input.isTriger(KEY_INPUT_SPACE))
		{
			isChange_ = true;
			// ���ԉ��o
			if (vec_ == Vec::LEFT)
			{
				partManager.LeftDash(transform_.pos.x - transform_.width / 2, transform_.pos.y);
			}
			else if (vec_ == Vec::RIGHT)
			{
				partManager.RightDash(transform_.pos.x + transform_.width / 2, transform_.pos.y);
			}
		}

		transform_.pos.y += speed_ * moveVec_;
	}
	// �ǂ𒵂�ł�Ƃ�
	else
	{
		if (vec_ == Vec::LEFT)
		{
			transform_.pos.x += 80;
		}
		if (vec_ == Vec::RIGHT)
		{
			transform_.pos.x -= 80;
		}
	}
#pragma region �ǂ̉����߂�����
	if (transform_.pos.x - transform_.width / 2 < stage.GetLeftX())
	{
		transform_.pos.x = (stage.GetLeftX() + transform_.width / 2);
		if (vec_ == Vec::RIGHT)
		{
			vec_ = Vec::LEFT;
		}
		isChange_ = false;
		// �ǏՓ˃t���O
		isInpact_ = true;
	}

	if (transform_.pos.x + transform_.width / 2 > stage.GetRightX())
	{
		transform_.pos.x = (stage.GetRightX() - transform_.width / 2);
		if (vec_ == Vec::LEFT)
		{
			vec_ = Vec::RIGHT;
		}
		isChange_ = false;
		// �ǏՓ˃t���O
		isInpact_ = true;
	}

	if (transform_.pos.y - transform_.height / 2 <= 0)
	{
		transform_.pos.y = transform_.height / 2;
	}
	else if (transform_.pos.y + transform_.height / 2 >= WIN_HEIGHT)
	{
		transform_.pos.y = WIN_HEIGHT - transform_.height / 2;
	}
#pragma endregion

	if (isInpact_)
	{
		//partManager.Clash(transform_.pos.x - transform_.width / 2, transform_.pos.y);
	}
}

void Player::Draw(int randX,int isShaking)
{
	
	if (isShaking == 1)
	{
		if (--ranpuTimer < 0)
		{
			if (isFlash == 0)
			{
				isFlash = 1;
				ranpuTimer = 15;
			}
			else if(isFlash == 1)
			{
				isFlash = 0;
				ranpuTimer = 20;
			}
			
			
		}

		if (isFlash == 1)
		{
			color = GetColor(200, 200, 200);
		}
		else
		{
			color = GetColor(200, 0, 0);
		}
	}
	else if(isShaking == 0 && isFlash == 0)
	{
		color = GetColor(200, 200, 200);
	}

	DrawBox(transform_.pos.x - transform_.width / 2 + randX, transform_.pos.y - transform_.height / 2,
		transform_.pos.x + transform_.width / 2 + randX, transform_.pos.y + transform_.height / 2 ,
		color, true);
	
	DrawFormatString(0, 60, GetColor(255, 255, 255), "%d", levelupCount_);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%d", levelDownCount_);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", speedLevel_);
}
