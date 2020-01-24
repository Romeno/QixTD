#include "stdafx.h"
#include "ArenaConfig.h"


std::string ArenaConfig::m_arenaDimensionsKey( "ArenaDimensions" );
std::string ArenaConfig::m_bgImageKey( "BgImage" );
std::string ArenaConfig::m_objectIdsKey("ObjectIds");
std::string ArenaConfig::m_objectPosKey("ObjectPos");
std::string ArenaConfig::m_objectDirsKey("ObjectDirs");


ArenaConfig::ArenaConfig()
	: super()
{

}


ArenaConfig::~ArenaConfig()
{

}


//void ArenaConfig::Parse( std::ifstream& strm )
//{
//	std::vector<std::string> parts;
//	std::string s;
//	char line[255];
//	while ( !strm.eof() ) {
//		strm.getline( line, 255 );
//		s = line;
//		s = pys::strip( s );
//
//		if ( s.empty() )
//			continue;
//
//		pys::split( s, parts, "=", 1 );
//
//		parts[0] = pys::strip( parts[0] );
//		if ( parts[0] == m_arenaDimensionsKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_arenaDimensions = ParseVector2( parts[1] );
//			m_arenaRect = { GetRectTopLeft( { 0, 0, 0 }, m_arenaDimensions ), m_arenaDimensions };
//		}
//		else if ( parts[0] == m_bgImageKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_bgImage = ParseString( parts[1] );
//		}
//		else
//		{
//          // TODO: add error handling
//          ELOG( ERR_TYPE_VALUE_ERROR, "Parse error." );
//		}
//	}
//}