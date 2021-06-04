
#include "DxLib.h"
#include "Difinition.h"
#include "../Src/Manager/InputManager.h"
#include "../Src/Manager/SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WindowWidth, WindowHeight, 32);
	SetBackgroundColor(100, 100, 120);
	SetMainWindowText("アクションゲーム");
	if (DxLib_Init() == -1)		
	{
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);

	InputManager::CreateInstansce();
	SceneManager::CreateInstansce();

	while (true)
	{
		if (ProcessMessage() != 0) { break; }

		ClearDrawScreen();
		clsDx();

		InputManager::GetInstance()->Update();
		SceneManager::GetInstance()->Exec();
		SceneManager::GetInstance()->Draw();

		ScreenFlip();
	}

	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	
	WaitKey();

	DxLib_End();
	return 0;
}
