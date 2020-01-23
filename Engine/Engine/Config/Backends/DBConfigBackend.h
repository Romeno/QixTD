#pragma once
#include "Engine/Config/Backends/ConfigBackend.h"
#include "Engine/Config/Config.h"


class DBConfigBackend : public ConfigBackend
{
public:
	typedef ConfigBackend super;

	DBConfigBackend();
	virtual ~DBConfigBackend();
};

