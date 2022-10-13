#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	stage->Init();
	player->Init(*stage);
	leftPoint->Init(stage->GetLeftX());
	rightPoint->Init(stage->GetRightX());
	feaverPoint->Init();
	pointManager->Init();
	input->Init();
}

void GameScene::Update()
{
	input->KeyInit();

	if (scene == Scene::Title)
	{
		player->Init(*stage);
		feaverTime = 0;
		feaverChargeCount = 0;
		feaverPoint->Init();
		gameTimer = 60 * 30;
		mode = Mode::Normal;
		if (input->isTriger(KEY_INPUT_SPACE))
		{
			scene = Scene::Game;
		}
	}
	else if (scene == Scene::Game)
	{
		if (--gameTimer <= 0)
		{
			scene = Scene::Result;
		}
		player->Update(*stage, *input);
#pragma region ポイントアップデート
		leftPoint->Update();
		rightPoint->Update();
		pointManager->Update(*leftPoint, *rightPoint);
#pragma endregion
		// 当たり判定呼び出し
		AllCollision(*player, *leftPoint, *rightPoint, feaverChargeCount,
			*feaverPoint, *pointManager, itemPopCount);
#pragma region ノーマル
		if (mode == Mode::Normal)
		{
			if (feaverChargeCount >= 3)
			{
				feaverCount++;
				feaverChargeCount = 0;
			}

			if (feaverCount >= 3)
			{
				feaverCount = 0;
				feaverTime = 60 * 6;
				mode = Mode::Feaver;
			}

			if (itemPopCount >= 3)
			{
				int popVec = GetRand(1);
				//feaverPoint->IsDeadTrue();
				switch (popVec)
				{
				case 0:
					feaverPoint->Pop(stage->GetLeftX());
					break;
				case 1:
					feaverPoint->Pop(stage->GetRightX());
					break;
				default:
					break;
				}
				itemPopCount = 0;
			}
		}
#pragma endregion
#pragma region フィーバー
		else if (mode == Mode::Feaver)
		{
			feaverTime--;
			leftPoint->FeaverUpdate();
			rightPoint->FeaverUpdate();
			if (feaverTime <= 0)
			{
				leftPoint->Pop();
				rightPoint->Pop();
				feaverCount = 0;
				feaverChargeCount = 0;
				mode = Mode::Normal;
			}
		}
#pragma endregion

		feaverPoint->Update();
	}
	else if (scene == Scene::Result)
	{
		if (input->isTriger(KEY_INPUT_SPACE))
		{
			scene = Scene::Title;
			pointManager->Reset();
		}
	}
}

void GameScene::Draw()
{
	if (scene == Scene::Title)
	{
		DrawString(100, 100, "タイトル", GetColor(255, 255, 255), true);
	}
	else if (scene == Scene::Game)
	{
		stage->Draw();
		leftPoint->Draw();
		rightPoint->Draw();
		feaverPoint->Draw();
		player->Draw();
		pointManager->Draw();
	}
	else if (scene == Scene::Result)
	{
		DrawString(100, 100, "リザルト", GetColor(255, 255, 255), true);
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲーム時間:%f", gameTimer);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "フィーバー時間:%f", feaverTime);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "フィーバーカウント:%d", feaverCount);
	DrawFormatString(200, 140, GetColor(255, 255, 255), "コンボ:%d", pointManager->GetCombo());
	DrawFormatString(0, 120, GetColor(255, 255, 255), "isDead:%d", feaverPoint->IsDead());
	DrawFormatString(0, 140, GetColor(255, 255, 255), "itemPop:%d", itemPopCount);
	//DrawFormatString(200, 200, GetColor(255, 255, 255), "合計:%d", pointManager->GetTotalScore());

	//DrawFormatString(0, 100, GetColor(255, 255, 255), "点数:%d", leftPoint->GetScore());
	//DrawFormatString(0, 120, GetColor(255, 255, 255), "点数:%d", rightPoint->GetScore());

}

void GameScene::AllCollision(Player& player, Point& leftPoint, Point& rightPoint, int& feaverChargeCount,
	FeaverPoint& item, PointManager& pointManager, int& itemPopCount)
{
	Transform posA, posB, posC, posD;

	posA = player.GetTransform();
	posB = leftPoint.GetTransform();
	posC = rightPoint.GetTransform();
	posD = item.GetTransform();

	int feverCombo = item.GetFeverCombo_();
	if (player.GetIsChange())
	{
		if (BoxCollision(posA, posB) && player.IsAddCount())
		{
			feaverChargeCount++;
			player.AddLevelupCount();
			leftPoint.Pop();
			itemPopCount++;

			player.ChangeIsAddCount();
			if (mode != Mode::Feaver)
			{
				pointManager.OnCollisionLeft(leftPoint);
			}
			if (mode == Mode::Feaver)
			{
				pointManager.OnCollisionFever(item);
			}
		}

		if (BoxCollision(posA, posC) && player.IsAddCount())
		{
			feaverChargeCount++;
			player.AddLevelupCount();
			rightPoint.Pop();
			itemPopCount++;

			player.ChangeIsAddCount();
			if (mode != Mode::Feaver)
			{
				pointManager.OnCollisionRight(rightPoint);
			}
			if (mode == Mode::Feaver)
			{
				pointManager.OnCollisionFever(item);
				feverCombo++;
			}
		}

		if (BoxCollision(posA, posD))
		{
			item.Dead();
		}

		if (!BoxCollision(posA, posB) && !BoxCollision(posA, posC) && !BoxCollision(posA, posD)
			&& player.IsAddCount())
		{
			player.AddLevelDownCount();
			player.ChangeIsAddCount();
			pointManager.OnCollisionFailure();
		}
	}


}

bool GameScene::BoxCollision(Transform& posA, Transform& posB)
{
	return posA.x - posA.width / 2 <= posB.x + posB.width / 2 &&
		posA.x + posA.width / 2 >= posB.x - posB.width / 2 &&
		posA.y + posA.height / 2 >= posB.y - posB.height / 2 &&
		posA.y - posA.height / 2 <= posB.y + posB.height / 2;
}