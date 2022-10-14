#include "GameScene.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	stage_->Init();
	player->Init(*stage_);
	leftPoint->Init(stage_->GetLeftX());
	rightPoint->Init(stage_->GetRightX());
	feaverPoint->Init();
	pointManager->Init();
	input->Init();
}

void GameScene::Update()
{
	input->KeyInit();

	// 敵を消す処理
	enemys.remove_if([](std::unique_ptr<Enemy>& enemy) {return enemy->IsDead(); });

	if (scene == Scene::Title)
	{
		player->Init(*stage_);
		feaverTime = 0;
		feaverChargeCount = 0;
		feaverPoint->Init();
		gameTimer = 60 * 30;
		mode = Mode::Normal;
		leftPoint->Pop();
		rightPoint->Pop();
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
		player->Update(*stage_, *input);
#pragma region ポイントアップデート
		leftPoint->Update();
		rightPoint->Update();
		pointManager->Update(*leftPoint, *rightPoint);
#pragma endregion
		// 当たり判定呼び出し
		AllCollision();
#pragma region ノーマル
		if (mode == Mode::Normal)
		{
			// 敵の動き
			for (std::unique_ptr<Enemy>& enemy : enemys)
			{
				enemy->Update();
			}

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
				switch (popVec)
				{
				case 0:
					feaverPoint->Pop(stage_->GetLeftX());
					break;
				case 1:
					feaverPoint->Pop(stage_->GetRightX());
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
		stage_->Draw();
		leftPoint->Draw();
		rightPoint->Draw();
		feaverPoint->Draw();
		player->Draw();
		pointManager->Draw();
		// 敵の描画
		for (std::unique_ptr<Enemy>& enemy : enemys)
		{
			enemy->Draw();
		}
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

void GameScene::AllCollision()
{
	Transform posA, posB, posC, posD, posE;

	posA = player->GetTransform();
	posB = leftPoint->GetTransform();
	posC = rightPoint->GetTransform();
	posD = feaverPoint->GetTransform();

	int feverCombo = feaverPoint->GetFeverCombo_();
	if (player->GetIsChange())
	{
		if (BoxCollision(posA, posB) && player->IsAddCount())
		{
			feaverChargeCount++;
			player->AddLevelupCount();
			leftPoint->Pop();
			itemPopCount++;

			player->ChangeIsAddCount();
			if (mode != Mode::Feaver)
			{
				pointManager->OnCollisionLeft(*leftPoint);
			}
			if (mode == Mode::Feaver)
			{
				pointManager->OnCollisionFever(*feaverPoint);
			}
			// エネミースポーン
			EnemySpawn();
		}

		if (BoxCollision(posA, posC) && player->IsAddCount())
		{
			feaverChargeCount++;
			player->AddLevelupCount();
			rightPoint->Pop();
			itemPopCount++;

			player->ChangeIsAddCount();
			if (mode != Mode::Feaver)
			{
				pointManager->OnCollisionRight(*rightPoint);
			}
			if (mode == Mode::Feaver)
			{
				pointManager->OnCollisionFever(*feaverPoint);
				feverCombo++;
			}
			// エネミースポーン
			EnemySpawn();
		}

		if (BoxCollision(posA, posD))
		{
			feaverPoint->Dead();
		}

		if (!BoxCollision(posA, posB) && !BoxCollision(posA, posC) && !BoxCollision(posA, posD)
			&& player->IsAddCount())
		{
			player->AddLevelDownCount();
			player->ChangeIsAddCount();
			pointManager->OnCollisionFailure();
		}
		// 敵の当たり判定
		for (std::unique_ptr<Enemy>& enemy : enemys)
		{
			posE = enemy->GetTrans();
			if (mode == Mode::Normal)
			{

			}
			else if (mode == Mode::Feaver)
			{
				if (BoxCollision(posA, posE))
				{
					enemy->OnCollision();
				}
			}
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

void GameScene::EnemySpawn()
{
	std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>();
	newEnemy->Init();

	enemys.push_back(std::move(newEnemy));
}