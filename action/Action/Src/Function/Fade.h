
#ifndef FADE_H
#define FADE_H

enum class FadeType
{
	Wait,
	FadeIn,
	FadeOut,
};

class Fade
{
private:
	float m_Alpha;
	FadeType m_FadeType;

public:
	bool m_IsFading;

public:
	Fade();
	virtual~Fade();
	void Start(FadeType fadeType_);	// �t�F�[�h�̎�ނ����߂�
	void Draw();					// ��`��`�悷��֐�
	void Exec(float fadeSpeed_);	// �t�F�[�h���������s
	bool IsFading();				// �t�F�[�h���I��������ǂ���
};

#endif // !FADE_H
