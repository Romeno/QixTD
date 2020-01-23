#pragma once
#include "Engine/Config/MapConfig.h"
#include "Math/Math.h"


class MapConfigStub : public MapConfig
{
public:
	typedef MapConfigStub thisT;
	typedef MapConfig super;

    MapConfigStub();
    virtual ~MapConfigStub();

	static void LoadFromJson( json& data, MapConfigStub* conf );
	//static AppConfig LoadFromDB(  );
	static void LoadFromRConfig( const std::string& data, MapConfigStub* conf );

    //virtual void Parse(std::ifstream& strm) override;

    glm::dvec3      m_mapDimensions;
	glm::drect      m_mapRect;
	double			m_worldScale;
    glm::dvec3      m_playerStartPos;

	static std::string		s_mapDimensionsKey;
	static std::string		s_worldScaleKey;
	static std::string		s_playerStartPosKey;
};

void to_json( json& j, const MapConfigStub& d );
void from_json( const json& j, MapConfigStub& d );