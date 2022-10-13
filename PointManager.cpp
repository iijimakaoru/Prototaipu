#include "PointManager.h"

void PointManager::Init()
{
	totalScore_ = 0;
	scoreGraph = LoadGraph("resouce\\score.png");
}

void PointManager::Update(Point &leftPoint,Point &rightPoint)
{
	////--7����(10���̈ʂ�\��)
	//displayNum[0] = (score_ % 10000000) / 1000000;
	//displayNum[0] = (point_->GetScore() % 10000000) / 1000000;
	////--6����(���̈ʂ�\��)
	//displayNum[1] = (score_ % 1000000) / 100000;
	////--5����(��̈ʂ�\��)
	//displayNum[2] = (score_ % 100000) / 10000;
	////--4����(�S�̈ʂ�\��)
	//displayNum[3] = (score_ % 10000) / 1000;
	////--3����(�\�̈ʂ�\��)
	//displayNum[4] = (score_ % 1000) / 100;
	////--2����(1�̈ʂ�\��)
	//displayNum[5] = (score_ % 100) / 10;
	////--1����(1�̈ʂ�\��)
	//displayNum[6] = (score_ % 10) / 1;
}

void PointManager::Draw()
{
	DrawFormatString(200, 200, GetColor(255, 255, 255), "���v:%d", totalScore_);
	//DrawGraph(150, 150, scoreGraph, true);
	/*for (int i = 0; i < 7; i++) {
		DrawGraph(numPos.x + (40 * i), numPos.y, numGraph[displayNum[i]], true);
	}*/
}

void PointManager::Reset()
{
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
	combo_++;
	int leftScore;
	leftPoint.OnCollisionScore(combo_);
	leftScore = leftPoint.GetScore();
	totalScore_ += leftScore;
}

void PointManager::OnCollisionRight(Point& rightPoint)
{
	combo_++;
	int rightScore;
	rightPoint.OnCollisionScore(combo_);
	rightScore = rightPoint.GetScore();
	totalScore_ += rightScore;
}