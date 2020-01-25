#include "stdafx.h"
#include "Config.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Utils/StringUtils.h"


Config::Config()
{

}


Config::~Config()
{

}


//ConfigError Config::Read()
//{
//	std::string path = GetResourcePath() + m_filename;
//	std::ifstream ifstrm;
//	ifstrm.open(path);
//
//	if (ifstrm.fail()) 
//	{
//		ELOG(ERR_TYPE_ENGINE_ERROR, "Config %s could not be read", Str2Wstr(path).c_str());
//		return CONFIG_ERROR_FAIL;
//	}
//	else 
//	{
//		Parse(ifstrm);
//
//		ifstrm.close();
//
//		return CONFIG_ERROR_OK;
//	}
//
//	return CONFIG_ERROR_OK;
//}
//
//
//void Config::Parse(std::ifstream& strm)
//{
//
//}


glm::dvec3 Config::ParseVector2( const std::string& str )
{
	glm::dvec3 vec;
	std::vector<std::string> parts;

	pys::split( str, parts, ",", 1 );
	vec.x = stoi( parts[0] );
	vec.y = stoi( parts[1] );
	vec.z = 0;

	return vec;
}


std::string Config::ParseString( const std::string& str )
{
	std::string ret;

	ret = str.substr( 1, str.length() - 2 );

	return ret;
}


int Config::ParseInt( const std::string& str )
{
	int ret;

	ret = stoi( str );

	return ret;
}


double Config::ParseDouble( const std::string& str )
{
	double ret;

	ret = std::stod( str );

	return ret;
}


bool Config::ParseBool( const std::string& str )
{
	std::string lower = pys::lower( str );
	if ( lower == "true" )
	{
		return true;
	}
	else if ( lower == "false" )
	{
		return false;
	}
	else
	{
		ELOG( ERR_TYPE_VALUE_ERROR, "Cannot convert %s to boolean", Str2Wstr( str.c_str() ) );
		return false;
	}
}


std::vector<double> GlmVec2StdVec(glm::dvec3 v)
{
	std::vector<double> ret;

	ret[0] = v.x;
	ret[1] = v.y;
	ret[2] = v.z;

	return ret;
}


glm::dvec3 StdVec2GlmVec( std::vector<double> v)
{
	glm::dvec3 ret;

	ret.x = v[0];
	ret.y = v[1];
	ret.z = v[2];

	return ret;
}




