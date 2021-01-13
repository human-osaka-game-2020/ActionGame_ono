
#include "../Difinition.h"
#include "DxLib.h"
#include "Fade.h"

// ================================================================================
// フェードイン、フェードアウト
// ===============================================================================
Fade::Fade()
{
	m_Alpha = 0.0f;
	m_IsFading = false;
	m_FadeType = Wait;
}

Fade::~Fade()
{
}

void Fade::Start(FadeType fadeType_)
{
	m_Alpha = (fadeType_ == FadeIn) ? 255.0f : 0.0f;
	m_IsFading = true;
	m_FadeType = fadeType_;
}

void Fade::Draw()
{
	if (m_FadeType == FadeIn ||m_FadeType == FadeOut)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_Alpha);
		DrawBox(0, 0, WindowWidth, WindowHeight, GetColor(0, 0, 0), TRUE);
	}
}

void Fade::Exec(float fadeSpeed_)
{
	if (m_FadeType == FadeIn)
	{
		m_Alpha -= fadeSpeed_;
		if (m_Alpha <= 0.0f)
		{
			m_IsFading = false;
		}
	}
	else if (m_FadeType == FadeOut)
	{
		m_Alpha += fadeSpeed_;
		if (m_Alpha >= 255.0f)
		{
			m_IsFading = false;
		}
	}
}

bool Fade::IsFading()
{
	return m_IsFading;
}
