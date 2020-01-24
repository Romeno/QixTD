#include "stdafx.h"
#include "BattleObjectConfig.h"


std::string BattleObjectConfig::m_objectIdKey( "ObjectId" );
std::string BattleObjectConfig::m_objectNameKey( "ObjectName" );
std::string BattleObjectConfig::m_objectPathingKey( "ObjectPathing" );


BattleObjectConfig::BattleObjectConfig()
	: super( )
{

}


BattleObjectConfig::~BattleObjectConfig()
{

}


//void BattleObjectsConfig::Parse( std::ifstream& strm )
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
//		if ( parts[0] == m_objectIdKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_objectId = ParseInt( parts[1] );
//		}
//		else if ( parts[0] == m_objectNameKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_objectName = ParseString( parts[1] );
//		}
//		else if ( parts[0] == m_objectPathingKey )
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_objectPathing = ParseString( parts[1] );
//		}
//		else
//		{
//          // TODO: add error handling
//          ELOG( ERR_TYPE_VALUE_ERROR, "Parse error." );
//		}
//	}
//}
