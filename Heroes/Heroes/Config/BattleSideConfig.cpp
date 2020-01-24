#include "stdafx.h"
#include "BattleSideConfig.h"


typedef BattleSideConfig thisT;


std::string BattleSideConfig::s_unitIdKey( "UnitId" );
std::string BattleSideConfig::s_unitCountKey( "UnitCount" );
std::string BattleSideConfig::s_unitPosKey( "UnitPos" );
std::string BattleSideConfig::s_unitDirKey( "UnitDir" );


BattleSideConfig::BattleSideConfig()
	: super()
{

}


BattleSideConfig::~BattleSideConfig()
{

}


void BattleSideConfig::LoadFromJson( json& data, thisT* conf )
{
	*conf = data;
}


void to_json( json& j, const BattleSideConfig& d )
{
	//j = json {
	//	{ thisT::s_unitIdKey, d.m_unitIds },
	//	{ thisT::, d.m_unitIds },
	//	{ thisT::s_unitIdKey, d.m_unitIds },
	//};
}


void from_json( const json& j, BattleSideConfig& d )
{
	//d.m_playerVelocity = j.at( thisT::s_playerVelocityKey ).get<double>();
}




//void BattleSideConfig::Parse( std::ifstream& strm )
//{
//	std::vector<std::string> parts;
//	std::vector<std::string> arrayTokens;
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
//		if ( parts[0] == s_unitIdsKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			pys::split( parts[1], arrayTokens, ",");
//
//			for ( auto token : arrayTokens )
//			{
//				m_unitIds.push_back( ParseInt( token ) );
//			}
//		}
//		else if ( parts[0] == s_unitCountsKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			pys::split( parts[1], arrayTokens, "," );
//
//			for ( auto token : arrayTokens )
//			{
//				m_unitCounts.push_back( ParseInt( token ) );
//			}
//		}
//		else if ( parts[0] == s_unitPosKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			pys::split( parts[1], arrayTokens, "," );
//
//			for ( auto token : arrayTokens )
//			{
//				m_unitPos.push_back( ParseVector2( token ) );
//			}
//		}
//		else if ( parts[0] == s_unitDirsKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			pys::split( parts[1], arrayTokens, "," );
//
//			for ( auto token : arrayTokens )
//			{
//				m_unitDirs.push_back( ParseVector2( token ) );
//			}
//		}
//		else
//		{
//          // TODO: add error handling
//          ELOG( ERR_TYPE_VALUE_ERROR, "Parse error." );
//		}
//	}
//}