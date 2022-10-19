#include"Shake.h"
#include "DxLib.h"

void Shake::Init()
{
	randX = 0;
	randY = 0;
	randTimePlayer = 30;
	randTimeBackground = 30;
	isShaking = 0;
}

void Shake::Update()
{
	if (isShaking == 0)
	{
		randX = 0;
		randY = 0;
	}

	//�e�V�F�C�N�t���O��ON�ɂȂ����痐�����擾����B(�����V�F�C�N�t���O���g���ƕЕ����~�܂��Ă��܂��Ɨ����~�܂邽�߁j
	if (isShaking == 1)
	{
		//�����^�C�}�[���g���A�^�C�}�[�̕ϐ������邲�Ƃɗ������擾
		randTimePlayer--;

		if (randTimePlayer <= 30)
		{
			randX = GetRand(10) - 5;
			randY = GetRand(10) - 5;

			//�^�C�}�[��0�ɂȂ�����V�F�C�N�t���O�Ɨ����^�C�}�[�����Z�b�g����B
			if (randTimePlayer < 0)
			{
				randTimePlayer = 30;
				isShaking = 0;
			}
		}
	}
}

//�e�L�[�������ꂽ��A���ꂼ��̃V�F�C�N�t���O��ON�ɂ���B�i����̓L�[���Ƃɏꍇ��������̂ŁA�t���O���Q�p�Ӂj
void Shake::OnCollisionShake()
{
	isShaking = 1;
}
