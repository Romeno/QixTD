#pragma once
#include "Engine/Utils/Singleton.h"


class WindowTitleManager : public Singleton<WindowTitleManager>
{
public:
	WindowTitleManager();
	~WindowTitleManager();

	int Init(std::string defaultTitle = "");
	void Tick(Uint32 diff);

	void SetWindowTitle(std::string& title);
	void AddToWindowTitle(std::string& title);
	std::string GetWindowTitle();

	std::string		m_defaultTitle;
	std::string		m_currentTickTitle;
};

