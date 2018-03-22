#include "stdafx.h"
#include "UIRadioButton.h"


UIRadioButton::UIRadioButton(const std::string& name, glm::dvec3 size, UIARadioGroup* group)
	: UIButton(name, size)
	, m_radioGroup(group)

	, m_active(false)
{
	
}


UIRadioButton::~UIRadioButton()
{

}


//////////////////////////////////////////////////////////////////////////

UIARadioGroup::UIARadioGroup(const std::string& name, glm::dvec3 size)
	: UIPanel(name, size)
{

}

UIARadioGroup::~UIARadioGroup()
{

}


UIRadioButton* UIARadioGroup::AddButton(std::string text)
{
	UIRadioButton* button = new UIRadioButton("RadioButton", 0, this);
	m_buttons.push_back(button);
	return button;
}


int UIARadioGroup::GetValue()
{
	for (size_t i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i]->m_active)
		{
			return i;
		}
	}

	return -1;
}


//////////////////////////////////////////////////////////////////////////

RadioGroupManager::RadioGroupManager()
	: m_lastId(0)
{

}


RadioGroupManager::~RadioGroupManager()
{

}


int RadioGroupManager::CreateRadioGroup()
{
	m_radioGroups[m_lastId] = new UIARadioGroup("RadioGroup" + std::to_string(m_lastId), 0);
	return m_lastId++;
}
