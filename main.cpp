#include "main.h"
#include "Stage.h"
#include "Player.h"
#include "Point.h"
#include "FeaverPoint.h"
#include "Struct.h"
#include "Input.h"
#include "PointManager.h"

bool BoxCollision(Transform& posA, Transform& posB)
{
	return posA.x - posA.width / 2 <= posB.x + posB.width / 2 &&
		posA.x + posA.width / 2 >= posB.x - posB.width / 2 &&
		posA.y + posA.height / 2 >= posB.y - posB.height / 2 &&
		posA.y - posA.height / 2 <= posB.y + posB.height / 2;
}

void AllCollision(Player& player, Point& leftPoint, Point& rightPoint, int& feaverPopCount,
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
			pointManager.OnCollisionRight(rightPoint);
		}

		if (BoxCollision(posA, posC) && player.IsAddCount())
		{
			feaverPopCount++;
			player.AddLevelupCount();
			rightPoint.Pop();
			player.ChangeIsAddCount();
		}

		if (!BoxCollision(posA, posB) && !BoxCollision(posA, posC) && player.IsAddCount())
		{
			player.AddLevelDownCount();
			player.ChangeIsAddCount();
			pointManager.OnCollisionLeft(leftPoint);
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

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み

	// ゲームループで使う変数の宣言
	std::unique_ptr<Stage> stage;
	stage = std::make_unique<Stage>();
	stage->Init();

	std::unique_ptr<Player> player;
	player = std::make_unique<Player>();
	player->Init(*stage);

	std::unique_ptr<Point> leftPoint;
	leftPoint = std::make_unique<Point>();
	leftPoint->Init(stage->GetLeftX());

	std::unique_ptr<Point> rightPoint;
	rightPoint = std::make_unique<Point>();
	rightPoint->Init(stage->GetRightX());

	std::unique_ptr<FeaverPoint> feaverPoint;
	feaverPoint = std::make_unique<FeaverPoint>();
	feaverPoint->Init();

	std::unique_ptr<PointManager> pointManager;
	pointManager = std::make_unique<PointManager>();
	pointManager->Init();


	int feaverPopCount = 0;
	int feaverCount = 0;

	enum class Mode
	{
		Normal,
		Feaver
	};

	float feaverTime = 0;

	Mode mode = Mode::Normal;

	enum class Scene
	{
		Title,
		Game,
		Result
	};

	Scene scene = Scene::Title;

	std::unique_ptr<Input> input;
	input = std::make_unique<Input>();
	input->Init();

	// ゲームループ
	while (1)
	{
		input->KeyInit();

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
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
			pointManager->Update(*leftPoint,*rightPoint);

			AllCollision(*player, *leftPoint, *rightPoint, feaverPopCount, *feaverPoint, feaverCount,*pointManager);
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
		else
		{
			break;
		}

		// 描画処理
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


		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}