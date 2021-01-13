
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
	// �J�n�W���O��
	void step_StartJingle();

	// ���͎�t
	void step_Input();

	// �N���A�W���O��
	void step_ClearJingle();

// �q�ɔԂɊ֌W����֐��Q
private:
	// �Q�[���̃N���A���
	bool IsClear() const;
	// ������ԂɃ��Z�b�g
	void Reset();
};

#endif // !INGAME_SCENE_H
