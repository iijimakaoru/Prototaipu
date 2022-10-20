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
	//�e
	//std::list<std::unique_ptr<PlayerBullet>> bullets_;

	//���_�̈ʒu
	float numPosX;
	float numPosY;

	//�X�R�A�摜
	int scoreGraph;
	int numGraph[10];

	int leftScore;
	int rightScore;

	//�R���{��
	int combo_;
	//�t�B�[�o�[�R���{
	int feverCombo_;

	//���X�R�A
	int leftScore_;
	//�E�X�R�A
	int rightScore_;

	//�ʏ�X�R�A
	int normalScore_;
	//�t�B�[�o�[���_
	int feverScore_;
	//�����_
	int totalScore_;
	//�\������
	int displayNum[7];
	
};

