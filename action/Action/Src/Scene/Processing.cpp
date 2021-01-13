
#include "DxLib.h"
#include "../Difinition.h"
#include "../Manager/InputManager.h"
#include "../Function/Fade.h"
#include "Processing.h"
#include <stdio.h>
#include <time.h>

// ================================================================================
// �O���[�o���ϐ�
// ================================================================================
Fade fade;
FadeType fadeScene = Wait;
InputManager* pInputMng = InputManager::GetInstance();

// ================================================================================
// �Q�[������
// ================================================================================
void GameProcessing()
{
	if (fadeScene == Wait)
	{
		if (pInputMng->IsPushed(KeyType_Enter))
		{
			fade.Start(FadeType::FadeIn);
			fadeScene = FadeIn;
		}
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			fade.Start(FadeType::FadeOut);
			fadeScene = FadeOut;
		}
	}

	fade.Exec(2.0f);

	if (fadeScene == FadeIn || fadeScene == FadeOut)
	{
		if (fade.IsFading())
		{
			fadeScene = Wait;
		}
	}
}

// ================================================================================
// �`�揈��
// ================================================================================
void DrawProcessing()
{
	fade.Draw();
}
