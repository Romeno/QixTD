#pragma once
#include "Engine/Config/MapConfig.h"


class MapConfigStub : public MapConfig
{
public:
	typedef MapConfig super;

    MapConfigStub(const std::string& id);
    virtual ~MapConfigStub();

    virtual void Parse(std::ifstream& strm) override;

    std::string     m_mapDimensionsKey;
    glm::dvec3      m_mapDimensions;

    std::string     m_playerStartPosKey;
    glm::dvec3      m_playerStartPos;
};

