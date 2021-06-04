
#include "Camera.h"
#include "../Manager/InputManager.h"
#include "DxLib.h"
#include "../Difinition.h"
#include "../Object/Player.h"

static Player player;

Camera::Camera()
{
	m_PosX = WindowHalfWidth;
	m_PosY = WindowHalfHeight;
}

Camera::~Camera()
{
}

void Camera::SetPos(float x_, float y_)
{
	m_PosX = x_;
	m_PosY = y_;
}

void Camera::Update(int x_, int speed_)
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (x_ < m_PosX)
	{
		m_PosX -= speed_;
	}
	else if (x_ > m_PosX)
	{
		m_PosX += speed_;
	}

	if (m_PosX <= WindowHalfWidth)
	{
		m_PosX = WindowHalfWidth;
	}
	else if (m_PosX >= FieldWidth - WindowHalfWidth)
	{
		m_PosX = FieldWidth - WindowHalfWidth;
	}

	if (m_PosY <= WindowHalfHeight)
	{
		m_PosY = WindowHalfHeight;
	}
	else if (m_PosY >= FieldHeight - WindowHalfHeight)
	{
		m_PosY = FieldHeight - WindowHalfHeight;
	}
}

int Camera::ConvertPosXWorldToScreen(int x_)
{
	int OriginScreenPosX = m_PosX - WindowWidth / 2;

	int ScreenPosX = x_ - OriginScreenPosX;

	return ScreenPosX;
}

int Camera::ConvertPosYWorldToScreen(int y_)
{
	int OriginScreenPosY = m_PosY - WindowHeight / 2;

	int ScreenPosY = y_ - OriginScreenPosY;

	return ScreenPosY;
}
