#pragma once
#include "Stage.h"
#include "Player.h"
#include "Point.h"
#include "FeaverPoint.h"
#include "Struct.h"
#include "Input.h"
#include "PointManager.h"

class GameScene
{
public:
	GameScene();
	~GameScene();

	void Initialize();
	void Update();
	void Draw();
	void AllCollision(Player& player, Point& leftPoint, Point& rightPoint, int& feaverChargeCount,
		FeaverPoint& feaverPoint, PointManager& pointManager, int& itemPopCount);
	bool BoxCollision(Transform& posA, Transform& posB);

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
	std::unique_ptr<Stage> stage = std::make_unique<Stage>();
	std::unique_ptr<Player> player = std::make_unique<Player>();
	std::unique_ptr<Point> leftPoint = std::make_unique<Point>();
	std::unique_ptr<Point> rightPoint = std::make_unique<Point>();
	std::unique_ptr<FeaverPoint> feaverPoint = std::make_unique<FeaverPoint>();
	std::unique_ptr<PointManager> pointManager = std::make_unique<PointManager>();
	std::unique_ptr<Input> input = std::make_unique<Input>();

	Mode mode = Mode::Normal;
	Scene scene = Scene::Title;

	int feaverChargeCount = 0;
	int feaverCount = 0;
	float feaverTime = 0;
	float gameTimer = 0;

	int itemPopCount = 0;
};

