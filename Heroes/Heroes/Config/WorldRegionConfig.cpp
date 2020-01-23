#include "stdafx.h"
#include "WorldRegionConfig.h"


static std::string				m_regionDimensionsKey("RegionDimensions");
static std::string				m_regionNameKey("RegionName");
static std::string				m_regionObjectIdsKey("Objects");
static std::string				m_regionObjectPosKey("ObjectPos");
static std::string				m_regionObjectDirsKey("ObjectDirs");


WorldRegionConfig::WorldRegionConfig( )
	: super( )
{

}


WorldRegionConfig::~WorldRegionConfig()
{

}


//void WorldRegionConfig::Parse( std::ifstream& strm )
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
//			throw "shit";
//		}
//	}
//}


