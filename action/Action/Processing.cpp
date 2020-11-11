#include "DxLib.h"
#include "Main.h"
#include "InputManager.h"
#include "Fade.h"
#include "Processing.h"
#include <stdio.h>
#include <time.h>

// ================================================================================
// グローバル変数
// ================================================================================
Fade fade;

// ================================================================================
// ゲーム処理
// ================================================================================
void GameProcessing()
{
	if (fadeScene == Wait)
	{
		if (CheckHitKey(KEY_INPUT_RETURN))
		{
			fade.Start(fadeIn);
			fadeScene = FadeIn;
		}
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			fade.Start(fadeOut);
			fadeScene = FadeOut;
		}
	}

	fade.Exec(2.0f);

	if (fadeScene == FadeIn)
	{
		fade.IsFading();
		if (fade.m_isFading == false)
		{
			fadeScene = Wait;
		}
	}
	if (fadeScene == FadeOut)
	{
		fade.IsFading();
		if (fade.m_isFading == false)
		{
			fadeScene = Wait;
		}
	}
}

// ================================================================================
// 描画処理
// ================================================================================
void DrawProcessing()
{
	fade.Draw();
}
