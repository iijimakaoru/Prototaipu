#include "main.h"
#include "Stage.h"
#include "Player.h"
#include "Point.h"
#include "FeaverPoint.h"
#include "Struct.h"
#include "Input.h"

void AllCollision(Player& player, Point& leftPoint, Point& rightPoint, int& feaverPopCount,
	FeaverPoint& feaverPoint, int& feaverCount)
{
	Transform posA, posB;

	posA = player.GetTransform();
	posB = leftPoint.GetTransform();

	if (posA.x - posA.width / 2 <= posB.x + posB.width / 2 &&
		posA.x + posA.width / 2 >= posB.x - posB.width / 2 &&
		posA.y + posA.height / 2 >= posB.y - posB.height / 2 &&
		posA.y - posA.height / 2 <= posB.y + posB.height / 2)
	{
		if (player.GetIsChange())
		{
			feaverPopCount++;
			leftPoint.Pop();
		}
	}

	posB = rightPoint.GetTransform();

	if (posA.x - posA.width / 2 <= posB.x + posB.width / 2 &&
		posA.x + posA.width / 2 >= posB.x - posB.width / 2 &&
		posA.y + posA.height / 2 >= posB.y - posB.height / 2 &&
		posA.y - posA.height / 2 <= posB.y + posB.height / 2)
	{
		if (player.GetIsChange())
		{
			feaverPopCount++;
			rightPoint.Pop();
		}
	}

	posB = feaverPoint.GetTransform();

	if (posA.x - posA.width / 2 <= posB.x + posB.width / 2 &&
		posA.x + posA.width / 2 >= posB.x - posB.width / 2 &&
		posA.y + posA.height / 2 >= posB.y - posB.height / 2 &&
		posA.y - posA.height / 2 <= posB.y + posB.height / 2)
	{
		if (player.GetIsChange())
		{
			feaverCount++;
			feaverPoint.Dead();
		}
	}
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���

	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	std::unique_ptr<Stage> stage;
	stage = std::make_unique<Stage>();
	stage->Init();

	std::unique_ptr<Player> player;
	player = std::make_unique<Player>();
	player->Init(*stage);

	std::unique_ptr<Point> leftPoint;
	leftPoint = std::make_unique<Point>();
	leftPoint->Init(stage->GetLeftX());

	std::unique_ptr<Point> rightPoint;
	rightPoint = std::make_unique<Point>();
	rightPoint->Init(stage->GetRightX());

	std::unique_ptr<FeaverPoint> feaverPoint;
	feaverPoint = std::make_unique<FeaverPoint>();
	feaverPoint->Init();

	int feaverPopCount = 0;
	int feaverCount = 0;

	enum class Mode
	{
		Normal,
		Feaver
	};

	float feaverTime = 0;

	Mode mode = Mode::Normal;

	enum class Scene
	{
		Title,
		Game,
		Result
	};

	Scene scene = Scene::Title;

	float gameTimer = 0;

	std::unique_ptr<Input> input;
	input = std::make_unique<Input>();
	input->Init();

	//// �ŐV�̃L�[�{�[�h���p
	//char keys[256] = { 0 };

	//// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	//char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (1)
	{
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		input->KeyInit();
		// �ŐV�̃L�[�{�[�h�����擾
		//GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		if (scene == Scene::Title)
		{
			player->Init(*stage);
			feaverTime = 0;
			feaverPopCount = 0;
			feaverPoint->Init();
			gameTimer = 60 * 30;
			mode = Mode::Normal;
			if (input->isTriger(KEY_INPUT_SPACE))
			{
				scene = Scene::Game;
			}
		}
		else if (scene == Scene::Game)
		{
			if (--gameTimer <= 0)
			{
				scene = Scene::Result;
			}
			player->Update(*stage, *input);
			AllCollision(*player, *leftPoint, *rightPoint, feaverPopCount, *feaverPoint, feaverCount);
			if (mode == Mode::Normal)
			{
				if (feaverPopCount >= 3)
				{
					if (player->Right())
					{
						feaverPoint->Pop(stage->GetLeftX());
					}
					if (player->Left())
					{
						feaverPoint->Pop(stage->GetRightX());
					}
					feaverPopCount = 0;
				}

				if (feaverCount >= 3)
				{
					feaverCount = 0;
					feaverTime = 60 * 6;
					mode = Mode::Feaver;
				}
			}
			else if (mode == Mode::Feaver)
			{
				feaverTime--;
				leftPoint->FeaverUpdate();
				rightPoint->FeaverUpdate();
				if (feaverTime <= 0)
				{
					leftPoint->Pop();
					rightPoint->Pop();
					mode = Mode::Normal;
				}
			}

			feaverPoint->Update();
		}
		else if (scene == Scene::Result)
		{
			if (input->isTriger(KEY_INPUT_SPACE))
			{
				scene = Scene::Title;
			}
		}
		else
		{
			break;
		}

		// �`�揈��
		if (scene == Scene::Title)
		{
			DrawString(100, 100, "�^�C�g��", GetColor(255, 255, 255), true);
		}
		else if (scene == Scene::Game)
		{
			stage->Draw();
			leftPoint->Draw();
			rightPoint->Draw();
			feaverPoint->Draw();
			player->Draw();
		}
		else if (scene == Scene::Result)
		{
			DrawString(100, 100, "���U���g", GetColor(255, 255, 255), true);
		}
		DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[������:%f", gameTimer);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "�t�B�[�o�[����:%f", feaverTime);

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}