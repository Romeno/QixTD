#include "stdafx.h"
#include "PlayerConfig.h"
#include "Engine/Utils/Utils.h"


typedef PlayerConfig thisT;


std::string PlayerConfig::s_playerVelocityKey( "velocity" );


PlayerConfig::PlayerConfig()
	: super()

	, m_playerVelocity(0.)
{

}


PlayerConfig::~PlayerConfig()
{

}


void PlayerConfig::LoadFromJson( json& data, PlayerConfig* conf )
{
	*conf = data;
}


void PlayerConfig::LoadFromRConfig( const std::string& data, PlayerConfig* conf )
{
	std::vector<std::string> lines;
	std::vector<std::string> parts;

	pys::split( data, lines, "\n" );
	for ( auto s : lines )
	{
		s = pys::strip( s );

		if ( s.empty() )
			continue;

		pys::split( s, parts, "=", 1 );

		parts[0] = pys::strip( parts[0] );
		if ( parts[0] == s_playerVelocityKey ) {
			parts[1] = pys::strip( parts[1] );

			conf->m_playerVelocity = ParseDouble( parts[1] );
		}
		else
		{
			throw "shit";
		}
	}
}


//void PlayerConfig::Parse(std::ifstream& strm)
//{
//	std::vector<std::string> parts;
//	std::string s;
//	char line[255];
//	while (!strm.eof()) {
//		strm.getline(line, 255);
//		s = line;
//		s = pys::strip(s);
//
//		if ( s.empty() )
//			continue;
//
//		pys::split(s, parts, "=", 1);
//
//		parts[0] = pys::strip(parts[0]);
//		if (parts[0] == m_playerVelocityKey) {
//			parts[1] = pys::strip(parts[1]);
//
//            m_playerVelocity = ParseDouble(parts[1]);
//		} 
//		else
//		{
//			throw "shit";
//		}
//	}
//}


void to_json( json& j, const PlayerConfig& d )
{
	j = json {
		{ thisT::s_playerVelocityKey, d.m_playerVelocity },
	};
}


void from_json( const json& j, PlayerConfig& d )
{
	d.m_playerVelocity = j.at( thisT::s_playerVelocityKey ).get<double>();
}

