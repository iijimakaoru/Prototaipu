#pragma once
#include "Struct.h"
#include "main.h"
#include "DxLib.h"

class Enemy
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Init();
	/// <summary>
	/// �X�V
	/// </summary>
	void Update();
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
	// ���S�t���O����
	bool IsDead() const { return isDead_; }
	// ���������Ƃ�
	void OnCollision() { isDead_ = true; }
	Transform GetTransform() { return transform_; }

private:
	// �`
	Transform transform_;
	// ���S�t���O
	bool isDead_;
	// �X�s�[�h
	float speed_;
	// ��������
	int moveVec_;
};