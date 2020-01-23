#include "stdafx.h"
#include "BattleConfig.h"


std::string BattleConfig::m_sideCountKey( "SideCount" );
std::string BattleConfig::m_arenaIdKey( "ArenaId" );


BattleConfig::BattleConfig()
	: super()
{

}


BattleConfig::~BattleConfig()
{

}


//void BattleConfig::Parse( std::ifstream& strm )
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
//		if ( parts[0] == m_sideCountKey ) {
//			parts[1] = pys::strip( parts[1] );
//
//			m_sideCount = ParseInt( parts[1] );
//		}
//		else if ( parts[0] == m_arenaIdKey ) {
//			parts[1] = pys::strip( parts[1] );
//
//			m_arenaId = ParseInt( parts[1] );
//		}
//		else
//		{
//			throw "shit";
//		}
//	}
//}
//
