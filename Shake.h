#pragma once

class  Shake
{
public:
	void Init();
	void Update();
	void OnCollisionShake();
	int GetRandX() { return randX; }
	int GetRandY() { return randY; }
	int GetisShaking() { return isShaking; }

private:

	//�����p�̕ϐ�
	int randX;
	int randY;
	int randTimePlayer;
	int randTimeBackground;

	//�V�F�C�N����Ă��邩�ǂ���
	//���@�̃V�F�C�N
	int isShaking = 0;

};

 
