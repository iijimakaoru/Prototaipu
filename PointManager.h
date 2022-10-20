#pragma once
#include "Point.h"
#include "FeaverPoint.h"
#include <memory>

class PointManager
{
public:
	void Init();
	void Update(Point& leftPoint, Point& RightPoint);
	void Draw();
	void Reset();
	void SumScore(int scoreA, int scoreB);
	void SetCombo(int combo);
	void SetTotalScore(int totalScore);
	int GetCombo() { return combo_; }
	int GetTotalScore() { return totalScore_; }

	void OnCollisionLeft(Point& leftPoint);
	void OnCollisionRight(Point& rightPoint);
	void OnCollisionFever(FeaverPoint& feverPoint);
	void OnCollisionFailure();

private:

	//std::unique_ptr<Point> point_ = std::make_unique<Point>();
	//std::unique_ptr<FeaverPoint> feverPoint_ = std::make_unique<FeaverPoint>();
	//弾
	//std::list<std::unique_ptr<PlayerBullet>> bullets_;

	//得点の位置
	float numPosX;
	float numPosY;

	//スコア画像
	int scoreGraph;
	int numGraph[10];

	int leftScore;
	int rightScore;

	//コンボ数
	int combo_;
	//フィーバーコンボ
	int feverCombo_;

	//左スコア
	int leftScore_;
	//右スコア
	int rightScore_;

	//通常スコア
	int normalScore_;
	//フィーバー得点
	int feverScore_;
	//総得点
	int totalScore_;
	//表示桁数
	int displayNum[7];
	
};

