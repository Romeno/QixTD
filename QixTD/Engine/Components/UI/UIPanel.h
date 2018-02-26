#pragma once
#include "Engine/UI/UIElement.h"


class UIPanel : public UIElement
{
public:
	UIPanel(const std::string& name, glm::dvec3 size);
	virtual ~UIPanel();


};

