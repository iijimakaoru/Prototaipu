#pragma once
#include "Stage.h"
#include "Player.h"
#include "Point.h"
#include "FeaverPoint.h"
#include "Struct.h"
#include "Input.h"
#include "PointManager.h"
#include <list>
#include "Enemy.h"
#include "ParticleManager.h"
#include "Shake.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

	void Initialize();
	void Update();
	void Draw();
	void AllCollision();
	bool BoxCollision(Transform& posA, Transform& posB);
	void EnemySpawn();

private:

	enum class Mode
	{
		Normal,
		Feaver
	};

	enum class Scene
	{
		Title,
		Game,
		Result
	};

	// ゲームループで使う変数の宣言
	// ステージ
	std::unique_ptr<Stage> stage_ = std::make_unique<Stage>();
	// プレイヤー
	std::unique_ptr<Player> player_ = std::make_unique<Player>();
	// 左壁のポイント
	std::unique_ptr<Point> leftPoint = std::make_unique<Point>();
	// 右壁のポイント
	std::unique_ptr<Point> rightPoint = std::make_unique<Point>();
	// フィーバー移行ポイント
	std::unique_ptr<FeaverPoint> feaverPoint = std::make_unique<FeaverPoint>();
	// ポイントマネージャー
	std::unique_ptr<PointManager> pointManager = std::make_unique<PointManager>();
	// キーボード入力
	std::unique_ptr<Input> input = std::make_unique<Input>();
	//シェイク
	std::unique_ptr<Shake> shake_ = std::make_unique<Shake>();
	// モード
	Mode mode = Mode::Normal;
	// シーン
	Scene scene = Scene::Title;
	// 
	int feaverChargeCount = 0;
	// 
	int feaverCount = 0;
	// フィーバーの時間
	float feaverTime = 0;
	//// ゲームの時間
	float gameTimer = 0;
	//// 
	int itemPopCount = 0;
	// 敵
	std::list<std::unique_ptr<Enemy>> enemys_;
	// 
	int enemyPopCount_ = 0;
	// 
	std::unique_ptr<ParticleManager> particleManager_ = std::make_unique<ParticleManager>();
	// 無敵
	bool invisible;
};

