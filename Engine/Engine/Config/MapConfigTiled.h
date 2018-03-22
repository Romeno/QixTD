#pragma once
#include "Engine/Config/MapConfig.h"


class MapConfigTiled : public MapConfig
{
public:
	typedef MapConfig super;

    MapConfigTiled(const std::string& id);
    virtual ~MapConfigTiled();


};

