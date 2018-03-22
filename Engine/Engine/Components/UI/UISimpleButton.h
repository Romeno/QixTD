#pragma once
#include "Engine/UI/UIButton.h"


class UISimpleButton : public UIButton
{
public:
	UISimpleButton(const std::string& name, glm::dvec3 size, glm::ivec4& color);
	virtual ~UISimpleButton();

	virtual void Render() override;

	glm::ivec4	m_color;
	glm::ivec4	m_pressedColor;
};

