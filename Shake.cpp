#include"Shake.h"

void Shake::Init()
{
	randX = 0;
	randY = 0;
	randTimePlayer = 30;
	randTimeBackground = 30;
}

void Shake::Update()
{
	//�e�L�[�������ꂽ��A���ꂼ��̃V�F�C�N�t���O��ON�ɂ���B�i����̓L�[���Ƃɏꍇ��������̂ŁA�t���O���Q�p�Ӂj
	if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
	{
		isPlayerShaking = 1;
	}
	if (keys[KEY_INPUT_RETURN] == 1 && oldkeys[KEY_INPUT_RETURN] == 0)
	{
		isBackgroundShaking = 1;
	}

	//�e�V�F�C�N�t���O��ON�ɂȂ����痐�����擾����B(�����V�F�C�N�t���O���g���ƕЕ����~�܂��Ă��܂��Ɨ����~�܂邽�߁j
	if (isPlayerShaking == 1)
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
				isPlayerShaking = 0;
			}
		}
	}
	if (isBackgroundShaking == 1)
	{
		//�^�C�}�[���g���A�^�C�}�[�̕ϐ������邲�Ƃɗ������擾
		randTimeBackground--;

		if (randTimeBackground <= 30)
		{
			randX = GetRand(10) - 5;
			randY = GetRand(10) - 5;

			//�^�C�}�[��0�ɂȂ�����V�F�C�N�t���O�Ɨ����^�C�}�[�����Z�b�g����B
			if (randTimeBackground < 0)
			{
				randTimeBackground = 30;
				isBackgroundShaking = 0;
			}
		}
	}

}