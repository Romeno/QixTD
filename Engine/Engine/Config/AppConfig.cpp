#include "stdafx.h"
#include "AppConfig.h"
#include "Engine/Utils/Utils.h"


std::string AppConfig::s_windowTitleKey( "WindowTitle" );
std::string AppConfig::s_numMapsKey( "NumMaps" );


typedef AppConfig thisT;


AppConfig::AppConfig()
	: super()

	, m_windowTitle("")
    , m_numMaps(0)
{

}


void AppConfig::LoadFromJson( nlohmann::json& data, AppConfig* conf )
{
	*conf = data;
}


void AppConfig::LoadFromRConfig( const std::string& data, AppConfig* conf )
{
	std::vector<std::string> lines;
	std::vector<std::string> parts;

	pys::split( data, lines, "\n" );
	for (auto s : lines )
	{
		s = pys::strip( s );

		if ( s.empty() )
			continue;

		pys::split( s, parts, "=", 1 );

		parts[0] = pys::strip( parts[0] );
		if ( parts[0] == s_windowTitleKey ) {
			parts[1] = pys::strip( parts[1] );

			conf->m_windowTitle = ParseString( parts[1] );
		}
		else if ( parts[0] == s_numMapsKey )
		{
			parts[1] = pys::strip( parts[1] );

			conf->m_numMaps = ParseInt( parts[1] );
		}
		else
		{
			throw "shit";
		}
	}
}


void to_json( json& j, const AppConfig& d ) 
{
	j = json { 
		{ thisT::s_windowTitleKey, d.m_windowTitle },
		{ thisT::s_numMapsKey, d.m_numMaps }
	};
}


void from_json( const json& j, AppConfig& d ) 
{
	d.m_numMaps = j.at( thisT::s_numMapsKey ).get<int>();
	d.m_windowTitle = j.at( thisT::s_windowTitleKey	).get<std::string>();
}

