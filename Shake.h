#pragma once

class  Shake
{
public:
	 Shake();
	~ Shake();

	void Init();
	void Update();

private:

	//�����p�̕ϐ�
	int randX;
	int randY;
	int randTimePlayer;
	int randTimeBackground;

	//�V�F�C�N����Ă��邩�ǂ���
	//���@�̃V�F�C�N
	int isPlayerShaking = 0;
	//�w�i�̃V�F�C�N
	int isBackgroundShaking = 0;

};

 Shake:: Shake()
{
}

 Shake::~ Shake()
{
}

 
