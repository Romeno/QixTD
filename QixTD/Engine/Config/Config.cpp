#include "stdafx.h"
#include "Config.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Utils/StringUtils.h"


Config::Config(const std::string& filename)
	: m_filename(filename)
{

}


Config::~Config()
{

}


ConfigError Config::Read()
{
	std::string path = GetResourcePath() + m_filename;
	std::ifstream ifstrm;
	ifstrm.open(path);

	if (ifstrm.fail()) 
	{
		ERR(ERR_TYPE_ENGINE_ERROR, "Config %s could not be read", Str2Wstr(path).c_str());
		return CONFIG_ERROR_FAIL;
	}
	else 
	{
		Parse(ifstrm);

		ifstrm.close();

		return CONFIG_ERROR_OK;
	}

	return CONFIG_ERROR_OK;
}


void Config::Parse(std::ifstream& strm)
{

}


glm::dvec3 Config::ParseVector2(const std::string& str)
{
    glm::dvec3 vec;
    std::vector<std::string> parts;

    pys::split(str, parts, ",", 1);
    vec.x = stoi(parts[0]);
    vec.y = stoi(parts[1]);
    vec.z = 0;

    return vec;
}


std::string Config::ParseString(const std::string& str)
{
    std::string ret;

    ret = str.substr(1, str.length() - 2);

    return ret;
}


int Config::ParseInt(const std::string& str)
{
    int ret;

    ret = stoi(str);

    return ret;
}


double Config::ParseDouble( const std::string& str )
{
	double ret;

	ret = std::stod( str );

	return ret;
}








