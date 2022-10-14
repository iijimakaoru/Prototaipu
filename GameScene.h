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

	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	// �X�e�[�W
	std::unique_ptr<Stage> stage_ = std::make_unique<Stage>();
	// �v���C���[
	std::unique_ptr<Player> player_ = std::make_unique<Player>();
	// ���ǂ̃|�C���g
	std::unique_ptr<Point> leftPoint = std::make_unique<Point>();
	// �E�ǂ̃|�C���g
	std::unique_ptr<Point> rightPoint = std::make_unique<Point>();
	// �t�B�[�o�[�ڍs�|�C���g
	std::unique_ptr<FeaverPoint> feaverPoint = std::make_unique<FeaverPoint>();
	// �|�C���g�}�l�[�W���[
	std::unique_ptr<PointManager> pointManager = std::make_unique<PointManager>();
	// �L�[�{�[�h����
	std::unique_ptr<Input> input = std::make_unique<Input>();
	// ���[�h
	Mode mode = Mode::Normal;
	// �V�[��
	Scene scene = Scene::Title;
	// 
	int feaverChargeCount = 0;
	// 
	int feaverCount = 0;
	// �t�B�[�o�[�̎���
	float feaverTime = 0;
	// �Q�[���̎���
	float gameTimer = 0;
	// 
	int itemPopCount = 0;
	// �G
	std::list<std::unique_ptr<Enemy>> enemys_;
};

