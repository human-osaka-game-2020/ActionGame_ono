
#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

// キー入力更新
void InputManager::Update()
{
	for (int i = 0; i < KeyType_Max; i++)
	{
		const bool current = (CheckHitKey(KEY_ASSIGN[i]) == 1);

	    m_State[i].pushed = current && !m_State[i].previous;;
		m_State[i].hold = current;
	    m_State[i].released = !current && m_State[i].previous;

		m_State[i].previous = current;
	}
}

// キーが押されたか
bool InputManager::IsPushed(KeyType key) const
{
	if ( key == KeyType_Max ) { return false; }
	return m_State[key].pushed;
}

// キーが押下されているか
bool InputManager::IsHold(KeyType key) const
{
	if ( key == KeyType_Max ) { return false; }
	return m_State[key].hold;
}

// キーが離されたか
bool InputManager::IsReleased(KeyType key) const
{
	if ( key == KeyType_Max ) { return false; }
	return m_State[key].released;
}
