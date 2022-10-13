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
		feaverPopCount = 0;
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
		leftPoint->Update();
		rightPoint->Update();
		pointManager->Update(*leftPoint, *rightPoint);

		AllCollision(*player, *leftPoint, *rightPoint, feaverPopCount, *feaverPoint, feaverCount, *pointManager);
		if (mode == Mode::Normal)
		{
			if (feaverPopCount >= 3)
			{
				feaverCount++;
				feaverPopCount = 0;
			}

			if (feaverCount >= 3)
			{
				feaverCount = 0;
				feaverTime = 60 * 6;
				mode = Mode::Feaver;
			}
		}
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
				feaverPopCount = 0;
				mode = Mode::Normal;
			}
		}

		feaverPoint->Update();
	}
	else if (scene == Scene::Result)
	{
		if (input->isTriger(KEY_INPUT_SPACE))
		{
			scene = Scene::Title;
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
	DrawFormatString(0, 60, GetColor(255, 255, 255), "コンボ:%d", pointManager->GetCombo());
	//DrawFormatString(0, 100, GetColor(255, 255, 255), "点数:%d", leftPoint->GetScore());
	//DrawFormatString(0, 120, GetColor(255, 255, 255), "点数:%d", rightPoint->GetScore());

}

void GameScene::AllCollision(Player& player, Point& leftPoint, Point& rightPoint, int& feaverPopCount,
	FeaverPoint& feaverPoint, int& feaverCount, PointManager& pointManager)
{
	Transform posA, posB, posC;

	posA = player.GetTransform();
	posB = leftPoint.GetTransform();
	posC = rightPoint.GetTransform();
	if (player.GetIsChange())
	{
		if (BoxCollision(posA, posB) && player.IsAddCount())
		{
			feaverPopCount++;
			player.AddLevelupCount();
			leftPoint.Pop();

			player.ChangeIsAddCount();
			pointManager.OnCollisionLeft(leftPoint);
		}

		if (BoxCollision(posA, posC) && player.IsAddCount())
		{
			feaverPopCount++;
			player.AddLevelupCount();
			rightPoint.Pop();

			player.ChangeIsAddCount();
			pointManager.OnCollisionRight(rightPoint);
		}

		if (!BoxCollision(posA, posB) && !BoxCollision(posA, posC) && player.IsAddCount())
		{
			player.AddLevelDownCount();
			player.ChangeIsAddCount();
			pointManager.OnCollisionFailure();
		}
	}

	/*posB = feaverPoint.GetTransform();

	if (posA.x - posA.width / 2 <= posB.x + posB.width / 2 &&
		posA.x + posA.width / 2 >= posB.x - posB.width / 2 &&
		posA.y + posA.height / 2 >= posB.y - posB.height / 2 &&
		posA.y - posA.height / 2 <= posB.y + posB.height / 2)
	{
		if (player.GetIsChange())
		{
			feaverCount++;
			feaverPoint.Dead();
		}
	}*/
}

bool GameScene::BoxCollision(Transform& posA, Transform& posB)
{
	return posA.x - posA.width / 2 <= posB.x + posB.width / 2 &&
		posA.x + posA.width / 2 >= posB.x - posB.width / 2 &&
		posA.y + posA.height / 2 >= posB.y - posB.height / 2 &&
		posA.y - posA.height / 2 <= posB.y + posB.height / 2;
}