
#include "TitleScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"
#include "../Function/Fade.h"

enum
{
	STEP_LOGO_IN,	// ƒƒS“ü—Í‘Ò‚¿
	STEP_INPUT,		// “ü—Í‘Ò‚¿
	STEP_END		// ƒV[ƒ“I—¹
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
	DrawString(20, 20, "TitleScene", GetColor(0, 0, 0));
}

bool TitleScene::IsEnd() const
{
	return ( m_Step == STEP_END );
}

// ƒƒS“üê
void TitleScene::step_LogoIn()
{
	m_Step = STEP_INPUT;
}

// “ü—ÍŽó•t
void TitleScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPushed(KeyType_Enter))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(SceneID_InGame);
	}
}
