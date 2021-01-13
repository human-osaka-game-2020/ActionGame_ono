
#include "InGameScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"

enum
{
	STEP_START_JINGLE,
	STEP_INPUT,		// ���͑҂�
	STEP_CREAR_JINGLE,
	STEP_END		// �V�[���I��
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
	// @@Dummy �J�ڊm�F�p�̉�����
	return ( m_Step == STEP_END );
}

// �J�n�W���O���҂�
void InGameScene::step_StartJingle()
{
	m_Step = STEP_INPUT;
}

// ���͑҂�
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


// �Q�[���̃N���A����
// true  = �N���A���Ă���
// false = ���N���A
bool InGameScene::IsClear() const
{

	return true; // @@Dummy
}

void InGameScene::Reset()
{
	// ���O���f�[�^��ǂ݂��񂾂�A�X�e�[�W�𑝂₷�ꍇ�͏������e���l����K�v������
	// �R���X�g���N�^�̓��e�����̂܂܃R�s�[���āA
	// �R���X�g���N�^�ł�Reset���Ăяo������

}
