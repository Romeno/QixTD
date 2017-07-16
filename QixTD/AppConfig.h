#pragma once
#include "Config.h"


class AppConfig : public Config
{
public:
	AppConfig();
	~AppConfig();

	virtual void Parse(std::ifstream& strm) override;

	std::string m_windowTitle;
	std::string m_windowTitleKey;
    int m_numMaps;
    std::string m_numMapsKey;
};

