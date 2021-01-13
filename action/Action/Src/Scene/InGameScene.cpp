
#include "InGameScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"

enum
{
	STEP_START_JINGLE,
	STEP_INPUT,		// 入力待ち
	STEP_CREAR_JINGLE,
	STEP_END		// シーン終了
};

InGameScene::InGameScene()
{
	Reset();

	m_Step = STEP_START_JINGLE;
}

InGameScene::~InGameScene()
{
}

void InGameScene::Exec()
{
	switch (m_Step)
	{
	case STEP_START_JINGLE:   step_StartJingle(); break;
	case STEP_INPUT		  :   step_Input();		  break;
	case STEP_CREAR_JINGLE:   step_ClearJingle(); break;
	default:									  break;
	}
}

void InGameScene::Draw()
{
	DrawString(20, 20, "InGameScene", GetColor(0, 0, 0));

	if (IsClear())
	{
		DrawString(100, 100, "Game Clear", GetColor(0, 0, 0));
	}
}

bool InGameScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return ( m_Step == STEP_END );
}

// 開始ジングル待ち
void InGameScene::step_StartJingle()
{
	m_Step = STEP_INPUT;
}

// 入力待ち
void InGameScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if ( pInputMng->IsPushed(KeyType_Reset) )
	{
		Reset();
	}
	else if ( pInputMng->IsPushed(KeyType_Up) )
	{

	}
	else if ( pInputMng->IsPushed(KeyType_Down) )
	{

	}
	else if ( pInputMng->IsPushed(KeyType_Left) )
	{

	}
	else if ( pInputMng->IsPushed(KeyType_Right) )
	{

	}

	if ( IsClear() )
	{
		m_Step = STEP_CREAR_JINGLE;
	}
}

// 
void InGameScene::step_ClearJingle()
{
	m_Step = STEP_END;
	SceneManager::GetInstance()->SetNextScene(SceneID_Result);
}


// ゲームのクリア判定
// true  = クリアしている
// false = 未クリア
bool InGameScene::IsClear() const
{

	return true; // @@Dummy
}

void InGameScene::Reset()
{
	// ※外部データを読みこんだり、ステージを増やす場合は処理内容を考える必要がある
	// コンストラクタの内容をそのままコピーして、
	// コンストラクタではResetを呼び出しする

}
