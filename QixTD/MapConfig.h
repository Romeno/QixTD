#pragma once
#include "Config.h"


class MapConfig : public Config
{
public:
	MapConfig(const std::string& id);
	~MapConfig();

	virtual void Parse(std::ifstream& strm) override;
};

