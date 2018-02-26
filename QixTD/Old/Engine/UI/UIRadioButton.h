#pragma once
#include "Engine/UI/UIButton.h"
#include "Engine/UI/UIPanel.h"
#include "Engine/Utils/Singleton.h"


class UIARadioGroup;


class UIRadioButton : public UIButton
{
public:
	UIRadioButton(const std::string& name, glm::dvec3 size, UIARadioGroup* group);
	virtual ~UIRadioButton();

	UIARadioGroup*		m_radioGroup;

	bool				m_active;
};


//////////////////////////////////////////////////////////////////////////

class UIARadioGroup : public UIPanel
{
	UIARadioGroup(const std::string& name, glm::dvec3 size);
	virtual ~UIARadioGroup();

	UIRadioButton* AddButton(std::string text);
	int GetValue();

	std::vector<UIRadioButton*> m_buttons;
};


//////////////////////////////////////////////////////////////////////////

class RadioGroupManager : public Singleton<RadioGroupManager>
{
	RadioGroupManager();
	virtual ~RadioGroupManager();

	int CreateRadioGroup();

	std::map<int, UIARadioGroup*>	m_radioGroups;
	int								m_lastId;
};
