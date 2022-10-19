#include "PointManager.h"

void PointManager::Init()
{
	//コンボ数
	combo_ = 0;
	//フィーバーコンボ
	feverCombo_ = 0;

	//左スコア
	leftScore_ = 0;
	//右スコア
	rightScore_ = 0;

	//通常スコア
	normalScore_ = 0;
	//フィーバー得点
	feverScore_ = 0;
	//総得点
	totalScore_ = 0;

	scoreGraph = LoadGraph("resouce\\score.png");
}

void PointManager::Update(Point &leftPoint,Point &rightPoint)
{
	////--7桁目(10万の位を表示)
	//displayNum[0] = (score_ % 10000000) / 1000000;
	//displayNum[0] = (point_->GetScore() % 10000000) / 1000000;
	////--6桁目(万の位を表示)
	//displayNum[1] = (score_ % 1000000) / 100000;
	////--5桁目(千の位を表示)
	//displayNum[2] = (score_ % 100000) / 10000;
	////--4桁目(百の位を表示)
	//displayNum[3] = (score_ % 10000) / 1000;
	////--3桁目(十の位を表示)
	//displayNum[4] = (score_ % 1000) / 100;
	////--2桁目(1の位を表示)
	//displayNum[5] = (score_ % 100) / 10;
	////--1桁目(1の位を表示)
	//displayNum[6] = (score_ % 10) / 1;
}

void PointManager::Draw()
{
	/*DrawFormatString(200, 220, GetColor(255, 255, 255), "合計:%d", totalScore_);
	DrawFormatString(200, 180, GetColor(255, 255, 255), "通常スコア:%d", normalScore_);
	DrawFormatString(200, 160, GetColor(255, 255, 255), "フィーバースコア:%d", feverScore_);
	DrawFormatString(200, 120, GetColor(255, 255, 255), "フィーバーコンボ:%d", feverCombo_);*/

	//DrawGraph(150, 150, scoreGraph, true);
	/*for (int i = 0; i < 7; i++) {
		DrawGraph(numPos.x + (40 * i), numPos.y, numGraph[displayNum[i]], true);
	}*/
}

void PointManager::SumScore(int scoreA,int scoreB)
{
	totalScore_ = scoreA + scoreB;
}

void PointManager::SetCombo(int combo)
{
	combo_ = combo;
}

void PointManager::SetTotalScore(int totalScore)
{
	totalScore_ = totalScore;
}

void PointManager::OnCollisionLeft(Point& leftPoint)
{
	leftPoint.OnCollisionScore(combo_);
	/*normalScore_ = leftPoint.GetScore();
	totalScore_ += normalScore_;
	*/
	leftScore_ = leftPoint.GetScore();
	normalScore_ = leftScore_;
	totalScore_ += normalScore_;
	combo_++;
}

void PointManager::OnCollisionRight(Point& rightPoint)
{
	rightPoint.OnCollisionScore(combo_);
	rightScore_ = rightPoint.GetScore();
	normalScore_ = rightScore_;
	totalScore_ += normalScore_;
	combo_++;
}

void PointManager::OnCollisionFever(FeaverPoint& feverPoint)
{
	feverPoint.OnCollisionScore(feverCombo_);
	feverScore_ = feverPoint.GetScore();
	totalScore_ += feverScore_;
	feverCombo_++;
}

void PointManager::OnCollisionFailure()
{
	if (combo_ <= 0)
	{
		combo_ = 0;
	}
	else
	{
		combo_ = 0;
	}
	
}
