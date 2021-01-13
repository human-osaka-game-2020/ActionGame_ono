
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../SceneDifinition.h"
#include "../Singleton.h"

// �V�[���Ǘ��N���X
class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	void Exec();	// �V�[���̎��s
	void Draw();	// �V�[���̕`��

	void SetNextScene(SceneID next_); // ���̃V�[���ݒ�


private:
	class SceneBase* create_NextScene();

private:
	class SceneBase* m_pScene;		// ���s���̃V�[��
	static SceneID   m_NextSceneID;	// ���ɍ��V�[����ID
};

#endif // !SCENE_MANAGER_H