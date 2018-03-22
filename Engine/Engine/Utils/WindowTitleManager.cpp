#include "stdafx.h"
#include "WindowTitleManager.h"
#include "Engine/GameManager.h"
#include "Engine/Utils/Utils.h"


WindowTitleManager::WindowTitleManager()
	: super()

	, m_defaultTitle("")
	, m_currentTickTitle("")
{

}


WindowTitleManager::~WindowTitleManager()
{

}


int WindowTitleManager::Init(std::string defaultTitle /*= ""*/)
{
	m_defaultTitle = defaultTitle;

	return 0;
}


void WindowTitleManager::Tick(Uint32 diff)
{
	m_currentTickTitle = m_defaultTitle;
}


void WindowTitleManager::SetWindowTitle(std::string& title)
{
	m_currentTickTitle = title;

	SDL_SetWindowTitle(WIN, m_currentTickTitle.c_str());
}


void WindowTitleManager::AddToWindowTitle(std::string& title)
{
	m_currentTickTitle += title;

	SDL_SetWindowTitle(WIN, m_currentTickTitle.c_str());
}


std::string WindowTitleManager::GetWindowTitle()
{
	return m_currentTickTitle;
}
