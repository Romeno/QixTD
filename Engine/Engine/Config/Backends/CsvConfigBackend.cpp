#include "stdafx.h"
#include "CsvConfigBackend.h"
#include "Engine/Utils/Utils.h"


CsvConfigBackend::CsvConfigBackend( const std::string& filename )
	: super()

	, m_filename(filename)
{

}


CsvConfigBackend::~CsvConfigBackend()
{

}


ConfigError CsvConfigBackend::Read( csv::ifstream& istrm )
{
	std::string path = GetResourcePath() + m_filename;

	istrm.open( m_filename );
	istrm.set_delimiter( ',', "$$" );
	istrm.enable_trim_quote_on_str( true, '\"' );

	if ( istrm.istm.fail() )
	{
		ELOGB( ERR_TYPE_ENGINE_ERROR, "Config %s could not be read", Str2Wstr( path ).c_str() );
		return CONFIG_ERROR_FAIL;
	}
	if ( istrm.is_open() )
	{
		istrm.skip_line();

		return CONFIG_ERROR_OK;
	}

	return CONFIG_ERROR_OK;
}


ConfigError CsvConfigBackend::Save( csv::ifstream& istrm )
{
	return CONFIG_ERROR_OK;
}
