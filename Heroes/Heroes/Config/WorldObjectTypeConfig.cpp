#include "stdafx.h"
#include "WorldObjectTypeConfig.h"


typedef WorldObjectTypeConfig thisT;


std::string WorldObjectTypeConfig::s_worldObjectIdKey( "objectId" );
std::string WorldObjectTypeConfig::s_worldObjectNameKey("objectName");
std::string WorldObjectTypeConfig::s_worldObjectPathingKey("objectPathing");
std::string WorldObjectTypeConfig::s_worldObjectImageKey("objectImage");
std::string WorldObjectTypeConfig::s_worldObjectSizeKey("objectSize");


WorldObjectTypeConfig::WorldObjectTypeConfig( )
	: super( )

	, m_worldObjectId()
	, m_worldObjectName()
	, m_worldObjectPathing()
	, m_worldObjectImage()
	, m_worldObjectSize()
{

}


WorldObjectTypeConfig::~WorldObjectTypeConfig()
{

}


void WorldObjectTypeConfig::LoadFromJson( json& data, thisT* conf )
{
	*conf = data;
}


void to_json( json& j, const WorldObjectTypeConfig& d )
{
	//j = json{
	//	{ thisT::s_unitIdKey, d.m_unitIds },
	//	{ thisT::, d.m_unitIds },
	//	{ thisT::s_unitIdKey, d.m_unitIds },
	//};
}


void from_json( const json& j, WorldObjectTypeConfig& d )
{
	//d.m_playerVelocity = j.at( thisT::s_playerVelocityKey ).get<double>();
}