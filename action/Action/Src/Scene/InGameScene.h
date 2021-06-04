
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
	void step_StartJingle();
	void step_Input();
	void step_ClearJingle();

private:
	bool IsClear() const;
	void Reset();
};

#endif // !INGAME_SCENE_H
