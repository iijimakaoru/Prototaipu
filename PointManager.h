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
	void OnCollisionFailure();

private:

	std::unique_ptr<Point> point_ = std::make_unique<Point>();

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

	//総得点
	int totalScore_;
	//表示桁数
	int displayNum[7];
	
};

