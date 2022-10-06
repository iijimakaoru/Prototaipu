#include "Player.h"

void Player::Init(Stage& stage)
{
	transform.x = stage.GetLeftX() + transform.width / 2;
	transform.y = 0;
	transform.width = transform.height = 20;
	isChange = false;
}

void Player::Update(Stage& stage)
{
	if (!isChange)
	{
		if (vec == Vec::LEFT)
		{
			transform.y += 5;
			if (transform.y - transform.height / 2 >= WIN_HEIGHT)
			{
				transform.y = -transform.height / 2;
			}
		}
		if (vec == Vec::RIGHT)
		{
			transform.y -= 5;
			if (transform.y + transform.height / 2 <= 0)
			{
				transform.y = WIN_HEIGHT + transform.height / 2;
			}
		}
	}
	else
	{
		if (vec == Vec::LEFT)
		{
			transform.x += 40;
		}
		if (vec == Vec::RIGHT)
		{
			transform.x -= 40;
		}
	}

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		isChange = true;
	}

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
}

void Player::Draw()
{
	DrawBox(transform.x - transform.width / 2, transform.y - transform.height / 2,
		transform.x + transform.width / 2, transform.y + transform.height / 2,
		GetColor(200, 200, 200), true);
}
