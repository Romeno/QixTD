#include "stdafx.h"
#include "UISpoiler.h"
#include "Engine/UI/UICheckbox.h"


void OpenCloseSpoiler(void* data);


UISpoiler::UISpoiler(const std::string& name, glm::dvec3 size)
	: UIPanel(name, size)

	, m_button(new UICheckbox("SpoilerButton", glm::dvec3(0, 0, 0)))

	, m_open(true)
{
	m_button->SetUserData(this);
	m_button->SetOnClick(OpenCloseSpoiler);
}


UISpoiler::~UISpoiler()
{
	delete m_button;
}


void UISpoiler::Close()
{
	m_open = false;
}


void UISpoiler::Open()
{
	m_open = true;
}


void UISpoiler::OpenOrClose()
{
	m_open = !m_open;
}


void OpenCloseSpoiler(void* data)
{
	UISpoiler* spoiler = (UISpoiler*)data;
	spoiler->OpenOrClose();
}