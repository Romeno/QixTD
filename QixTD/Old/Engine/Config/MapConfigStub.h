#pragma once
#include "Engine/Config/MapConfig.h"


class MapConfigStub : public MapConfig
{
public:
    MapConfigStub(const std::string& id);
    ~MapConfigStub();

    virtual void Parse(std::ifstream& strm) override;

    std::string     m_mapDimensionsKey;
    glm::dvec3      m_mapDimensions;

    std::string     m_playerStartPosKey;
    glm::dvec3      m_playerStartPos;
};

