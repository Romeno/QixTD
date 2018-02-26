#pragma once
#include "Engine/UI/UIElement.h"


class UIWindow : public UIElement
{
public:
	UIWindow(const std::string& name, glm::dvec3 size);
	virtual ~UIWindow();


};

