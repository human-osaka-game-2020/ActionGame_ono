
#include "Difinition.h"
#include "../Src/Manager/InputManager.h"
#include "../Src/Scene/Processing.h"
#include <stdio.h>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �c�w���C�u��������������
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WindowWidth, WindowHeight, 32);
	SetBackgroundColor(0, 0, 120);
	SetMainWindowText("�A�N�V�����Q�[��");
	if (DxLib_Init() == -1)		
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);

	// �e�평��������
	// ----------------------------------------------------

	// �ȉ��A���t���[���X�V���鏈��
	// ----------------------------------------------------

	// ���C�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �c�w���C�u�������g����ŁA�P�t���[�����̏������n�߂邽�߂̂���
		// ----------------------------------------------------
		ClearDrawScreen();
		clsDx();

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		LoadGraphScreen(50, 100, "data/Unitychan_Blink_1.png", TRUE); // �摜��`�悷��

		GameProcessing();

		DrawProcessing();

		// �ȉ��A�`�揈��
		// ----------------------------------------------------
		

		// �c�w���C�u�������g����ŁA���j�^�[�փQ�[����ʂ�\�����邽�߂̂���
		// �K�����[�v�̍Ō�ŌĂяo��
		// ----------------------------------------------------
		ScreenFlip();
	}
	
	WaitKey();				// �L�[���͑҂�

	DxLib_End();			// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}
