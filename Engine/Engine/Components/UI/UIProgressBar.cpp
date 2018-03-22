#include "stdafx.h"
#include "UIProgressBar.h"


UIProgressBar::UIProgressBar(const std::string& name, glm::dvec3 size)
	: UIElement(name, size)
{

}


UIProgressBar::~UIProgressBar()
{

}


void UIProgressBar::Fill(double percent)
{
	m_filled = percent;
}
