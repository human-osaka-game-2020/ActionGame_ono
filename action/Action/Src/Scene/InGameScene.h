
#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

#include "SceneBase.h"
#include "../Difinition.h"
#include "../SceneDifinition.h"

class InGameScene:public SceneBase
{
public:
	InGameScene();
	virtual ~InGameScene();

	virtual void Exec();
	virtual void Draw();

	virtual bool IsEnd() const;

private:
	// 開始ジングル
	void step_StartJingle();

	// 入力受付
	void step_Input();

	// クリアジングル
	void step_ClearJingle();

// 倉庫番に関係する関数群
private:
	// ゲームのクリア状態
	bool IsClear() const;
	// 初期状態にリセット
	void Reset();
};

#endif // !INGAME_SCENE_H
