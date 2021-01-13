
#include "DxLib.h"
#include "Difinition.h"
#include "../Src/Manager/InputManager.h"
#include "../Src/Manager/SceneManager.h"

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

	// �Ǘ��N���X�̍쐬
	InputManager::CreateInstansce();
	SceneManager::CreateInstansce();

	// ���C�����[�v
	while (true)
	{
		if (ProcessMessage() != 0) { break; }

		// ��ʃN���A
		ClearDrawScreen();
		clsDx();

		// ����
		InputManager::GetInstance()->Update();
		SceneManager::GetInstance()->Exec();

		// �`��
		SceneManager::GetInstance()->Draw();

		// ��ʍX�V
		ScreenFlip();
	}


	// �Ǘ��N���X�̌�n��
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	
	WaitKey();				// �L�[���͑҂�

	DxLib_End();			// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}
