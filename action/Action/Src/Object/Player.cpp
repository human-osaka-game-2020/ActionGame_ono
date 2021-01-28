
#include "Player.h"
#include "DxLib.h"
#include "../Manager/InputManager.h"
#include "../Difinition.h"

static const int InitJumpSpeed = 16;

Player::Player()
{
	InitTexture();

	m_PosX = 0;
	m_PosY = 447;

	m_MoveSpeed = 4;
	m_JumpVelosity = 0;
}

Player::~Player()
{
	ReleaseTexture();
}

void Player::Update(Stage stage)
{
	int NewPosX = m_PosX;
	int NewPosY = m_PosY;
	int Horizontal = 0;
	int Vertical = 0;

	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsHold(KeyType_Left) && m_PosX > 0.0f)
	{
		Horizontal -= m_MoveSpeed;

		if (pInputMng->IsPushed(KeyType_Up) && m_IsFloatingAir == false)
		{
			m_IsFloatingAir = true;
			m_JumpVelosity = InitJumpSpeed;
		}
	}
	else if (pInputMng->IsHold(KeyType_Right) && m_PosX + 32 < FieldWidth)
	{
		Horizontal += m_MoveSpeed;

		if (pInputMng->IsPushed(KeyType_Up) && m_IsFloatingAir == false)
		{
			m_IsFloatingAir = true;
			m_JumpVelosity = InitJumpSpeed;
		}
	}
	else if (pInputMng->IsPushed(KeyType_Up) && m_IsFloatingAir == false)
	{
		m_IsFloatingAir = true;
		m_JumpVelosity = InitJumpSpeed;
	}

	if (m_IsFloatingAir == true)
	{
		Vertical = (m_PosY - m_PrevPosY) - m_JumpVelosity;
		m_JumpVelosity -= 1;
	}
	else
	{
		Vertical = 0;
		m_JumpVelosity = 0;
	}

	Vertical += g_Gravity;

	int RectX = m_PosX;
	int RectY = m_PosY;
	int RectWidth = m_PosX + 32;
	int RectHeight = m_PosY + 32;

	EdgeType ContactEdge = EdgeType::Invalid;
	int ContactPosX = m_PrevPosX;
	int ContactPosY = m_PrevPosY;

	// XŽ²‚Ì”»’è
	if (stage.CheckHit(RectX, RectY, RectWidth, RectHeight, Horizontal, 0, ContactEdge, ContactPosX) == false)
	{
		m_PosX += Horizontal;
	}
	else
	{
		AdjustToMapChipEdgePosition(ContactEdge, ContactPosX);
	}

	// YŽ²‚Ì”»’è
	if (stage.CheckHit(RectX, RectY, RectWidth, RectHeight, 0, Vertical, ContactEdge, ContactPosY) == false)
	{
		m_PosY += Vertical;
		m_IsFloatingAir = true;
	}
	else
	{
		AdjustToMapChipEdgePosition(ContactEdge, ContactPosY);
	}

	m_PrevPosX = m_PosX;
	m_PrevPosY = m_PosY;

}

void Player::Draw(Camera camera)
{
	int DrawPosX = camera.ConvertPosXWorldToScreen(m_PosX);
	int DrawPosY = camera.ConvertPosYWorldToScreen(m_PosY);

	DrawGraph(DrawPosX, DrawPosY, m_Tex, TRUE);
}

void Player::SetPos(float x_, float y_)
{
	m_PosX = x_;
	m_PosY = y_;
}

void Player::SetMoveSpeed(float speed_)
{
	m_MoveSpeed = speed_;
}

void Player::SetJumpVelocity(float velocity_)
{
	m_JumpVelosity = velocity_;
}

void Player::InitTexture()
{
	m_Tex = LoadGraph("Res/Player.png");
}

void Player::ReleaseTexture()
{
	DeleteGraph(m_Tex);
}

void Player::AdjustToMapChipEdgePosition(EdgeType contact_edge_, int contact_pos_)
{
	switch (contact_edge_)
	{
	case EdgeType::Top:
		m_PosY = contact_pos_;
		m_IsFloatingAir = false;
		break;
	case EdgeType::Left:
		m_PosX = contact_pos_;
		break;
	case EdgeType::Right:
		m_PosX = contact_pos_;
		break;
	case EdgeType::Bottom:
		m_PosY = contact_pos_;
		break;
	}
}
