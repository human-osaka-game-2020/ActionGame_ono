
#include "InGameScene.h"
#include "DxLib.h"
#include "../Manager/SceneManager.h"
#include "../Manager/InputManager.h"
#include "../Object/Player.h"
#include "../Stage/Stage.h"
#include "../Function/Camera.h"

static Player player;
static Stage stage;
static Camera camera;

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

	player.InitTexture();
	stage.InitTex();
	m_Step = STEP_START_JINGLE;
}

InGameScene::~InGameScene()
{
	player.ReleaseTexture();
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

	camera.Update(player.GetPosX(), player.GetMoveSpeed());
	player.Update(stage);
}

void InGameScene::Draw()
{
	stage.Draw(camera);
	player.Draw(camera);

	if (IsClear() == true)
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
	if(player.GetPosX() + MapChipSize >= FieldWidth - MapChipSize)
	{
		return true; // @@Dummy
	}
	return false;
}

void InGameScene::Reset()
{
	player.SetPos(0, 447);
	camera.SetPos(WindowHalfWidth, WindowHalfHeight);
}
