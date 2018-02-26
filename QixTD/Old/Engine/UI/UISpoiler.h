#pragma once
#include "Engine/UI/UIPanel.h"


class UICheckbox;


class UISpoiler : public UIPanel
{
public:
	UISpoiler(const std::string& name, glm::dvec3 size);
	virtual ~UISpoiler();

	void Close();
	void Open();
	void OpenOrClose();

	UICheckbox*			m_button;

	bool				m_open;
};

