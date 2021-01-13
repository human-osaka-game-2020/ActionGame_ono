
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../SceneDifinition.h"
#include "../Singleton.h"

// シーン管理クラス
class SceneManager : public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	void Exec();	// シーンの実行
	void Draw();	// シーンの描画

	void SetNextScene(SceneID next_); // 次のシーン設定


private:
	class SceneBase* create_NextScene();

private:
	class SceneBase* m_pScene;		// 実行中のシーン
	static SceneID   m_NextSceneID;	// 次に作るシーンのID
};

#endif // !SCENE_MANAGER_H