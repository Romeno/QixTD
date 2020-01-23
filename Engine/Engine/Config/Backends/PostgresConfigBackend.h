#pragma once
#include "DBConfigBackend.h"
class PostgresConfigBackend :
	public DBConfigBackend
{
public:
	PostgresConfigBackend();
	virtual ~PostgresConfigBackend();
};

