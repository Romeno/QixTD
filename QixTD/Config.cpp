#include "stdafx.h"
#include "Config.h"
#include "Utils.h"
#include "Logger.h"


Config::Config(std::string filename)
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

	ERR(ERR_TYPE_ENGINE_ERROR, "Config %s could not be read", "adasdasdasdasd");

	if (ifstrm.fail()) 
	{
		ERR(ERR_TYPE_ENGINE_ERROR, "Config %s could not be read", path.c_str());
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
