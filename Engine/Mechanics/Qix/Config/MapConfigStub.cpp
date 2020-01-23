#include "stdafx.h"
#include "MapConfigStub.h"


std::string MapConfigStub::s_mapDimensionsKey( "MapDimensions" );
std::string MapConfigStub::s_worldScaleKey( "WorldScale" );
std::string MapConfigStub::s_playerStartPosKey( "PlayerStartPos" );


typedef MapConfigStub thisT;


MapConfigStub::MapConfigStub()
    : super()

    , m_mapDimensions(0, 0, 0)
	, m_mapRect()
    , m_worldScale(1)
	, m_playerStartPos( 0, 0, 0 )
{

}


MapConfigStub::~MapConfigStub()
{

}


void MapConfigStub::LoadFromJson( json& data, MapConfigStub* conf )
{
	*conf = data;
}


void MapConfigStub::LoadFromRConfig( const std::string& data, MapConfigStub* conf )
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
		if ( parts[0] == s_mapDimensionsKey ) {
			parts[1] = pys::strip( parts[1] );

			conf->m_mapDimensions = ParseVector2( parts[1] );
			conf->m_mapRect = { GetRectTopLeft( { 0, 0, 0 }, conf->m_mapDimensions ), conf->m_mapDimensions };
		}
		else if ( parts[0] == s_playerStartPosKey ) {
			parts[1] = pys::strip( parts[1] );

			conf->m_playerStartPos = ParseVector2( parts[1] );
		}
		else if ( parts[0] == s_worldScaleKey ) {
			parts[1] = pys::strip( parts[1] );

			conf->m_worldScale = ParseDouble( parts[1] );
		}
		else
		{
			throw "shit";
		}
	}
}


void to_json( json& j, const MapConfigStub& d )
{
	j = json {
		{ thisT::s_mapDimensionsKey, GlmVec2StdVec( d.m_mapDimensions ) },
		{ thisT::s_worldScaleKey, d.m_worldScale },
		{ thisT::s_playerStartPosKey, GlmVec2StdVec( d.m_playerStartPos ) }
	};
}


void from_json( const json& j, MapConfigStub& d )
{
	d.m_mapDimensions = StdVec2GlmVec( j.at( thisT::s_mapDimensionsKey ).get< std::vector<double> >() );
	d.m_worldScale = j.at( thisT::s_worldScaleKey ).get<double>();
	d.m_playerStartPos = StdVec2GlmVec( j.at( thisT::s_playerStartPosKey ).get< std::vector<double> >() );
}
