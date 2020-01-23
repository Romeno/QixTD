#pragma once
#include "Engine/Config/Config.h"


class WorldObjectTypeConfig : public Config
{
public:
	typedef WorldObjectTypeConfig thisT;
	typedef Config super;

	WorldObjectTypeConfig( );
	virtual ~WorldObjectTypeConfig();

	//virtual void Parse( std::ifstream& strm ) override;
	void LoadFromJson( json& data, thisT* conf );

	int						m_worldObjectId;
	std::string				m_worldObjectName;
	std::string				m_worldObjectPathing;
	std::string				m_worldObjectImage;
	glm::dvec3				m_worldObjectSize;

	static std::string		s_worldObjectIdKey;
	static std::string		s_worldObjectNameKey;
	static std::string		s_worldObjectPathingKey;
	static std::string		s_worldObjectImageKey;
	static std::string		s_worldObjectSizeKey;

};

void to_json( json& j, const WorldObjectTypeConfig& d );
void from_json( const json& j, WorldObjectTypeConfig& d );