
#include "ResultScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"

enum
{
	STEP_INPUT,
	STEP_END
};
ResultScene::ResultScene()
{
	m_Step = STEP_INPUT;
}

ResultScene::~ResultScene()
{
}

void ResultScene::Exec()
{
	switch (m_Step)
	{
	case STEP_INPUT:   step_Input();  break;
	default:						  break;
	}

	// @@Dummy 遷移確認用の仮処理
	/*m_Step++;
	if (m_Step >= 120)
	{
		SceneManager::GetInstance()->SetNextScene(SceneID_Title);
	}*/
}

void ResultScene::Draw()
{
	DrawString(20, 20, "ResultScene", GetColor(0, 0, 0));
}

bool ResultScene::IsEnd() const
{
	// @@Dummy 遷移確認用の仮処理
	return (m_Step == STEP_END);
}

void ResultScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPushed(KeyType_Enter))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(SceneID_Title);
	}
}
