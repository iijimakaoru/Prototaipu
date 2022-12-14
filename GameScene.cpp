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
	player_->Init(*stage_);
	leftPoint->Init(stage_->GetLeftX());
	rightPoint->Init(stage_->GetRightX());
	feaverPoint->Init();
	pointManager->Init();
	input->Init();
	particleManager_->Init();
}

void GameScene::Update()
{
	input->KeyInit();

	// 敵を消す処理
	enemys_.remove_if([](std::unique_ptr<Enemy>& enemy) {return enemy->IsDead(); });

	if (scene == Scene::Title)
	{
		shake_->Init();
		stage_->Init();
		player_->Init(*stage_);
		/*feaverTime = 0;
		feaverChargeCount = 0;*/
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
		// 
		stage_->Update();
		shake_->Update();
		// 
		player_->Update(*stage_, *input, *particleManager_);
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
			// 
			gameTimer--;

			// 敵の動き
			for (std::unique_ptr<Enemy>& enemy : enemys_)
			{
				enemy->Update();
			}

			if (feaverCount >= 2)
			{
				feaverCount = 0;
				bom_->Init();
				for (std::unique_ptr<Enemy>& enemy : enemys_)
				{
					enemy->OnCollision();
					particleManager_->Clash(enemy->GetTransform().pos.x, enemy->GetTransform().pos.y);
				}
			}

			bom_->Update();

			// エネミースポーン
			if (enemyPopCount_ >= 3)
			{
				EnemySpawn();
				enemyPopCount_ = 0;
			}

			if (itemPopCount >= 6)
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
		//else if (mode == Mode::Feaver)
		//{
		//	feaverTime--;

		//	// エネミースポーン
		//	if (enemyPopCount_ >= 3)
		//	{
		//		EnemySpawn();
		//		enemyPopCount_ = 0;
		//	}

		//	if (feaverTime <= 0)
		//	{
		//		feaverCount = 0;
		//		feaverChargeCount = 0;
		//		mode = Mode::Normal;
		//	}
		//}
#pragma endregion

		feaverPoint->Update();

		if (gameTimer <= 0 || !stage_->IsAlive())
		{
			scene = Scene::Result;
		}
	}
	else if (scene == Scene::Result)
	{
		if (input->isTriger(KEY_INPUT_SPACE))
		{
			scene = Scene::Title;
			pointManager->Init();
		}
	}

	particleManager_->Update();
}

void GameScene::Draw()
{
	DrawBox(0, 0, WIN_WIDTH, WIN_HEIGHT, GetColor(0, 0, 0), true);
	if (scene == Scene::Title)
	{
		DrawString(100, 100, "タイトル", GetColor(255, 255, 255), true);
	}
	else if (scene == Scene::Game)
	{
		if (mode == Mode::Feaver)
		{
			DrawBox(0, 0, WIN_WIDTH, WIN_HEIGHT, GetColor(100, 100, 0), true);
		}

		stage_->Draw(shake_->GetRandX(),shake_->GetRandY());

		leftPoint->Draw(shake_->GetRandX());
		rightPoint->Draw(shake_->GetRandX());
		feaverPoint->Draw();

		player_->Draw(shake_->GetRandX(), shake_->GetisShaking());
		if (invisible)
		{
			DrawCircle(player_->GetTransform().pos.x, player_->GetTransform().pos.y, player_->GetTransform().width + 2,
				GetColor(255, 255, 255), false);
		}

		pointManager->Draw();
		// 敵の描画
		for (std::unique_ptr<Enemy>& enemy : enemys_)
		{
			enemy->Draw();
		}
		particleManager_->Draw();

		bom_->Draw();
	}
	else if (scene == Scene::Result)
	{
		DrawString(100, 100, "リザルト", GetColor(255, 255, 255), true);
	}
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲーム時間:%f", gameTimer);
	//DrawFormatString(0, 20, GetColor(255, 255, 255), "フィーバー時間:%f", feaverTime);
	//DrawFormatString(0, 40, GetColor(255, 255, 255), "フィーバーカウント:%d", feaverCount);
	////DrawFormatString(200, 140, GetColor(255, 255, 255), "コンボ:%d", pointManager->GetCombo());
	//DrawFormatString(0, 120, GetColor(255, 255, 255), "stageHP:%d", stage_->GetStageHP());
}

void GameScene::AllCollision()
{
	Transform posA, posB, posC, posD, posE;

	posA = player_->GetTransform();
	posB = leftPoint->GetTransform();
	posC = rightPoint->GetTransform();
	posD = feaverPoint->GetTransform();

	int feverCombo = feaverPoint->GetFeverCombo_();
	if (player_->IsInpact())
	{
		// 左壁ポイント
		if (BoxCollision(posA, posB))
		{
			if (!enemysDead)
			{
				player_->AddLevelupCount();
				leftPoint->Pop();
				itemPopCount++;

				if (mode != Mode::Feaver)
				{
					pointManager->OnCollisionLeft(*leftPoint);
				}
				if (mode == Mode::Feaver)
				{
					pointManager->OnCollisionFever(*feaverPoint);
				}
				enemyPopCount_++;

				particleManager_->Clash(posA.pos.x - posA.width / 2, posA.pos.y);

				// 無敵ON
				invisible = true;
			}
			else
			{
				leftPoint->Pop();
				itemPopCount++;

				enemyPopCount_++;

				particleManager_->RargeEfect(posA.pos.x, posA.pos.y);

				// 無敵ON
				invisible = true;
			}
		}
		// 右壁ポイント
		if (BoxCollision(posA, posC))
		{
			if (!enemysDead)
			{
				player_->AddLevelupCount();
				rightPoint->Pop();
				itemPopCount++;

				if (mode != Mode::Feaver)
				{
					pointManager->OnCollisionRight(*rightPoint);
				}
				if (mode == Mode::Feaver)
				{
					pointManager->OnCollisionFever(*feaverPoint);
					feverCombo++;
				}
				enemyPopCount_++;

				particleManager_->Clash(posA.pos.x + posA.width / 2, posA.pos.y);

				// 無敵ON
				invisible = true;
			}
			else
			{
				rightPoint->Pop();
				itemPopCount++;

				enemyPopCount_++;

				particleManager_->RargeEfect(posA.pos.x, posA.pos.y);

				// 無敵ON
				invisible = true;
			}
		}
		// フィーバーポイント
		if (BoxCollision(posA, posD))
		{
			feaverCount++;
			feaverPoint->Dead();
			if (player_->Right())
			{
				particleManager_->FeaverClash(posA.pos.x + posA.width / 2, posA.pos.y);
			}

			if (player_->Left())
			{
				particleManager_->FeaverClash(posA.pos.x - posA.width / 2, posA.pos.y);
			}
		}
		// 無色床での処理
		// バリア無し
		if (!BoxCollision(posA, posB) && !BoxCollision(posA, posC) && !BoxCollision(posA, posD) && !invisible)
		{
			shake_->OnCollisionShake();
			stage_->Damage();
		}
		// 敵撃破
		else if (!BoxCollision(posA, posB) && !BoxCollision(posA, posC) && !BoxCollision(posA, posD) &&
			enemysDead)
		{
			invisible = false;
			particleManager_->EnemysAndWall(posA.pos.x, posA.pos.y);
		}
		// バリア有り
		else if (!BoxCollision(posA, posB) && !BoxCollision(posA, posC) && !BoxCollision(posA, posD) &&
			invisible)
		{
			invisible = false;
		}

		enemysDead = false;
	}

	// 敵の当たり判定
	for (std::unique_ptr<Enemy>& enemy : enemys_)
	{
		posE = enemy->GetTransform();
		if (BoxCollision(posA, posE))
		{
			if (mode == Mode::Normal)
			{

			}
			else if (mode == Mode::Feaver)
			{

			}
			enemy->OnCollision();
			particleManager_->Clash(posE.pos.x, posE.pos.y);
			enemysDead = true;
		}
	}
}

bool GameScene::BoxCollision(Transform& posA, Transform& posB)
{
	int a_Left = (int)posA.pos.x - (posA.width / 2);
	int a_Right = (int)posA.pos.x + (posA.width / 2);
	int a_Top = (int)posA.pos.y - (posA.height / 2);
	int a_Bottom = (int)posA.pos.y + (posA.height / 2);

	int b_Left = (int)posB.pos.x - (posB.width / 2);
	int b_Right = (int)posB.pos.x + (posB.width / 2);
	int b_Top = (int)posB.pos.y - (posB.height / 2);
	int b_Bottom = (int)posB.pos.y + (posB.height / 2);

	if (a_Left < b_Right && b_Left < a_Right && a_Top < b_Bottom && b_Top < a_Bottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameScene::EnemySpawn()
{
	std::unique_ptr<Enemy> newEnemy = std::make_unique<Enemy>();
	newEnemy->Init();

	enemys_.push_back(std::move(newEnemy));
}