#pragma once
#include "Engine/UI/UIElement.h"


class UIProgressBar : public UIElement
{
public:
	UIProgressBar(const std::string& name, glm::dvec3 size);
	virtual ~UIProgressBar();

	void Fill(double percent);

	double		m_filled;
};

