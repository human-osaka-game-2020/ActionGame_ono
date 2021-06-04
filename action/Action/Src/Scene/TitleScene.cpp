
#include "TitleScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"
#include "../Function/Fade.h"

enum
{
	STEP_LOGO_IN,
	STEP_INPUT,
	STEP_END
};

TitleScene::TitleScene()
{
	m_Step = STEP_LOGO_IN;
}

TitleScene::~TitleScene()
{
}

void TitleScene::Exec()
{
	switch ( m_Step )
	{
	case STEP_LOGO_IN: step_LogoIn(); break;
	case STEP_INPUT:   step_Input();  break;
	default:						  break;
	}
}

void TitleScene::Draw()
{
	SetFontSize(64);
	DrawString(216, 216, "アクションゲーム", GetColor(0, 0, 0));
	SetFontSize(24);
	DrawString(512, 324, "Enterキーで遊べるよ!", GetColor(255, 200, 200));
}

bool TitleScene::IsEnd() const
{
	return ( m_Step == STEP_END );
}

void TitleScene::step_LogoIn()
{
	m_Step = STEP_INPUT;
}

void TitleScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPushed(KeyType_Enter))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(SceneID_InGame);
	}
}
