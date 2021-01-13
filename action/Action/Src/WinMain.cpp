
#include "Difinition.h"
#include "../Src/Manager/InputManager.h"
#include "../Src/Scene/Processing.h"
#include <stdio.h>

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

	// 各種初期化処理
	// ----------------------------------------------------

	// 以下、毎フレーム更新する処理
	// ----------------------------------------------------

	// メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ＤＸライブラリを使う上で、１フレーム分の処理を始めるためのお約束
		// ----------------------------------------------------
		ClearDrawScreen();
		clsDx();

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		LoadGraphScreen(50, 100, "data/Unitychan_Blink_1.png", TRUE); // 画像を描画する

		GameProcessing();

		DrawProcessing();

		// 以下、描画処理
		// ----------------------------------------------------
		

		// ＤＸライブラリを使う上で、モニターへゲーム画面を表示するためのお約束
		// 必ずループの最後で呼び出す
		// ----------------------------------------------------
		ScreenFlip();
	}
	
	WaitKey();				// キー入力待ち

	DxLib_End();			// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}
