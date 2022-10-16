#pragma once
#include "main.h"
#include "Stage.h"
#include "Struct.h"
#include "Input.h"
#include "ParticleManager.h"

class Player
{
public:
	// ��
	enum class Vec
	{
		LEFT,
		RIGHT
	};
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="stage"></param>
	void Init(Stage& stage);
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="stage"></param>
	/// <param name="input"></param>
	void Update(Stage& stage, Input& input, ParticleManager& partManager);
	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
	/// <summary>
	/// transform�̃Q�b�^�[
	/// </summary>
	/// <returns></returns>
	Transform GetTransform() { return transform_; }
	/// <summary>
	/// ����ł�t���O
	/// </summary>
	/// <returns></returns>
	bool GetIsChange() { return isChange_; }
	/// <summary>
	/// �ǂ����̕ǂɂ��邩�̔���
	/// </summary>
	/// <returns></returns>
	bool Left() { return vec_ == Vec::LEFT; }
	bool Right() { return vec_ == Vec::RIGHT; }
	/// <summary>
	/// �X�s�[�h�A�b�v
	/// </summary>
	void AddLevelupCount() 
	{
		if (speedLevel_ < 3)
		{
			levelupCount_++;
		}
	}
	/// <summary>
	/// �X�s�[�h�_�E��
	/// </summary>
	void AddLevelDownCount()
	{
		if (speedLevel_ > 1)
		{
			levelDownCount_++;
		}
	}

	bool IsInpact() { return isInpact_; }

private:
	// �`
	Transform transform_;
	// ����ł�t���O
	bool isChange_ = false;
	// ���݂̕�
	Vec vec_ = Vec::LEFT;
	// �X�s�[�h
	int speed_;
	// �X�s�[�h���x��
	int speedLevel_;
	// ��������
	int moveVec_;
	// ���x���A�b�v�ɕK�v�ȉ�
	int levelupCount_;
	// ���x���_�E���܂ł̉�
	int levelDownCount_;
	// �ǏՓ˃t���O
	bool isInpact_;
};

