#pragma once
#include "Engine/Config/Config.h"


class MapConfig : public Config
{
public:
	typedef Config super;

	MapConfig(const std::string& id);
	virtual ~MapConfig();

	virtual void Parse(std::ifstream& strm) override;
};

