#include "stdafx.h"
#include "RConfigBackend.h"
#include "Engine/Utils/Utils.h"


RConfigBackend::RConfigBackend( const std::string& filename )
	: super()

	, m_filename( filename )
{

}


RConfigBackend::~RConfigBackend()
{

}


ConfigError RConfigBackend::Read( std::string& data )
{
	std::string path = GetResourcePath() + m_filename;
	std::ifstream ifstrm;
	ifstrm.open(path);
	
	if (ifstrm.fail()) 
	{
		ELOGB(ERR_TYPE_ENGINE_ERROR, "Config %s could not be read", Str2Wstr(path).c_str());
		return CONFIG_ERROR_FAIL;
	}
	else 
	{
		std::stringstream buffer;
		buffer << ifstrm.rdbuf();
		data = buffer.str();

		ifstrm.close();

		return CONFIG_ERROR_OK;
	}
	
	return CONFIG_ERROR_OK;
}


ConfigError RConfigBackend::Save( const std::string& data )
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

