
#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "SceneBase.h"

class ResultScene :public SceneBase
{
public:
	ResultScene();
	~ResultScene();

	void Exec();
	void Draw();

	virtual bool IsEnd() const;

private:
	void step_Input();
};

#endif // !RESULT_SCENE_H

