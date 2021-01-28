
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "../Singleton.h"
#include "../SceneDifinition.h"

class TextureManager : public Singleton<TextureManager>
{
private:
	static const int m_PlayerTexMax = 22;
	int m_Bg;
	int m_Player[m_PlayerTexMax];
	int m_Ground;

public:
	TextureManager();
	~TextureManager();

	void InitTextureID(SceneID id_);

	int GetBgHandle()	  const { return m_Bg; }
	int GetPlayerHandle() const { for (int i = 0; i < m_PlayerTexMax; i++) { return m_Player[i]; } }
	int GetGroundHandle() const { return m_Ground; }
};


#endif // !TEXTURE_MANAGER_H
