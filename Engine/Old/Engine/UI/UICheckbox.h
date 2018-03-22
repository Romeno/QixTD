#pragma once
#include "Engine/UI/UIButton.h"


class UICheckbox : public UIButton
{
public:
	UICheckbox(const std::string& name, glm::dvec3 size);
	virtual ~UICheckbox();

};

