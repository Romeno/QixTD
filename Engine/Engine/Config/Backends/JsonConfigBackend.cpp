#include "stdafx.h"
#include "JsonConfigBackend.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Config/Config.h"


using json = nlohmann::json;


JsonConfigBackend::JsonConfigBackend( const std::string& filename )
	: super()

	, m_filename(filename)
{

}


JsonConfigBackend::~JsonConfigBackend()
{

}


ConfigError JsonConfigBackend::Read( json& data)
{
	std::string path = GetResourcePath() + m_filename;
	std::ifstream ifstrm;
	ifstrm.open( path );

	if ( ifstrm.fail() )
	{
		ELOGB( ERR_TYPE_ENGINE_ERROR, "Config %s could not be read", Str2Wstr( path ).c_str() );
		return CONFIG_ERROR_FAIL;
	}
	else
	{
		ifstrm >> data;

		ifstrm.close();

		return CONFIG_ERROR_OK;
	}

	return CONFIG_ERROR_OK;
}


ConfigError JsonConfigBackend::Save( json& data )
{
	std::string path = GetResourcePath() + m_filename;
	std::ofstream ofstrm;
	ofstrm.open( path );

	if ( ofstrm.fail() )
	{
		ELOGB( ERR_TYPE_ENGINE_ERROR, "Config %s could not be written", Str2Wstr( path ).c_str() );
		return CONFIG_ERROR_FAIL;
	}
	else
	{
		ofstrm << data;

		ofstrm.close();

		return CONFIG_ERROR_OK;
	}

	return CONFIG_ERROR_OK;
}

