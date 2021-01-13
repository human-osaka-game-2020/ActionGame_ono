
#include "DxLib.h"
#include "Difinition.h"
#include "../Src/Manager/InputManager.h"
#include "../Src/Manager/SceneManager.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ＤＸライブラリ初期化処理
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WindowWidth, WindowHeight, 32);
	SetBackgroundColor(0, 0, 120);
	SetMainWindowText("アクションゲーム");
	if (DxLib_Init() == -1)		
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);

	// 管理クラスの作成
	InputManager::CreateInstansce();
	SceneManager::CreateInstansce();

	// メインループ
	while (true)
	{
		if (ProcessMessage() != 0) { break; }

		// 画面クリア
		ClearDrawScreen();
		clsDx();

		// 処理
		InputManager::GetInstance()->Update();
		SceneManager::GetInstance()->Exec();

		// 描画
		SceneManager::GetInstance()->Draw();

		// 画面更新
		ScreenFlip();
	}


	// 管理クラスの後始末
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	
	WaitKey();				// キー入力待ち

	DxLib_End();			// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}
