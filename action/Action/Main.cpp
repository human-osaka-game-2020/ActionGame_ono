#include "Main.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "Processing.h"
#include <stdio.h>
#include <time.h>

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // �c�w���C�u��������������
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WINDOW_W, WINDOW_H, 32);
	SetBackgroundColor(255, 255, 255);
	SetMainWindowText("");
	if (DxLib_Init() == -1)		
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);

	// �e�평��������
	// ----------------------------------------------------
	InputInit();			// ���͏����������֐��̌Ăяo��
	DrawInit();				// �`�揈���������֐��̌Ăяo��

	// �ȉ��A���t���[���X�V���鏈��
	// ----------------------------------------------------
	InputUpdate();	// ���͏����X�V�֐��̌Ăяo��


	// ���C�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �c�w���C�u�������g����ŁA�P�t���[�����̏������n�߂邽�߂̂���
		// ----------------------------------------------------
		ClearDrawScreen();
		clsDx();

		// �ȉ��A�`�揈��
		// ----------------------------------------------------
		DrawInformation();

		// �c�w���C�u�������g����ŁA���j�^�[�փQ�[����ʂ�\�����邽�߂̂���
		// �K�����[�v�̍Ō�ŌĂяo��
		// ----------------------------------------------------
		ScreenFlip();
	}
	
	WaitKey();				// �L�[���͑҂�

	DxLib_End();			// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}
