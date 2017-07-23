#include "stdafx.h"
#include "AppConfig.h"
#include "Engine/Utils/Utils.h"


AppConfig::AppConfig()
	: Config("conf")

	, m_windowTitle("")
	, m_windowTitleKey("WindowTitle")
    , m_numMaps(0)
    , m_numMapsKey("NumMaps")
{

}


AppConfig::~AppConfig()
{

}


void AppConfig::Parse(std::ifstream& strm)
{
	std::vector<std::string> parts;
	std::string s;
	char line[255];
	while (!strm.eof()) {
		strm.getline(line, 255);
		s = line;
		s = pys::strip(s);
		pys::split(s, parts, "=", 1);

		parts[0] = pys::strip(parts[0]);
		if (parts[0] == m_windowTitleKey) {
			parts[1] = pys::strip(parts[1]);

            m_windowTitle = ParseString(parts[1]);
		} 
        else if (parts[0] == m_numMapsKey)
        {
            parts[1] = pys::strip(parts[1]);

            m_numMaps = ParseInt(parts[1]);
        }
	}
}
