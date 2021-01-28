#include "TextureManager.h"
#include "DxLib.h"

TextureManager::TextureManager()
	:m_Bg(0),
	m_Ground(0)
{
	for (int i = 0; i < m_PlayerTexMax; i++)
	{
		m_Player[i] = 0;
	}
}

TextureManager::~TextureManager()
{
}

void TextureManager::InitTextureID(SceneID id_)
{
	InitGraph();

	switch (id_)
	{
	case SceneID_Title:

		break;
	case SceneID_InGame:
		m_Bg = LoadGraph("Res/Bg.png");
		for (int i = 0; i < m_PlayerTexMax; i++)
		{
			m_Player[0] = LoadGraph("Res/Unitychan_Idle_1");
			m_Player[1] = LoadGraph("Res/Unitychan_Idle_2");
			m_Player[2] = LoadGraph("Res/Unitychan_Idle_3");
			m_Player[3] = LoadGraph("Res/Unitychan_Idle_4");
			m_Player[4] = LoadGraph("Res/Unitychan_Run_1");
			m_Player[5] = LoadGraph("Res/Unitychan_Run_2");
			m_Player[6] = LoadGraph("Res/Unitychan_Run_3");
			m_Player[7] = LoadGraph("Res/Unitychan_Run_4");
			m_Player[8] = LoadGraph("Res/Unitychan_Run_5");
			m_Player[9] = LoadGraph("Res/Unitychan_Run_6");
			m_Player[10] = LoadGraph("Res/Unitychan_Run_7");
			m_Player[11] = LoadGraph("Res/Unitychan_Run_8");
			m_Player[12] = LoadGraph("Res/Unitychan_Run_9");
			m_Player[13] = LoadGraph("Res/Unitychan_Run_10");
			m_Player[14] = LoadGraph("Res/Unitychan_Run_11");
			m_Player[15] = LoadGraph("Res/Unitychan_Run_12");
			m_Player[16] = LoadGraph("Res/Unitychan_Run_13");
			m_Player[17] = LoadGraph("Res/Unitychan_Run_14");
			m_Player[18] = LoadGraph("Res/Unitychan_Run_15");
			m_Player[19] = LoadGraph("Res/Unitychan_Run_16");
			m_Player[20] = LoadGraph("Res/Unitychan_Run_17");
			m_Player[21] = LoadGraph("Res/Unitychan_Run_18");
		}				   				   
		break;			   
	case SceneID_Result:   
		break;
	default:
		break;
	}	 
}		 
