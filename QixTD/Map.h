#pragma once
#include "Config.h"


class Map : public Config
{
public:
	Map();
	~Map();

	virtual void Parse(std::ifstream& strm) override;
};

