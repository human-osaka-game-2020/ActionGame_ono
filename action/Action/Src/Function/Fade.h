
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
	void Start(FadeType fadeType_);	// フェードの種類を決める
	void Draw();					// 矩形を描画する関数
	void Exec(float fadeSpeed_);	// フェード処理を実行
	bool IsFading();				// フェードが終わったかどうか
};

#endif // !FADE_H
