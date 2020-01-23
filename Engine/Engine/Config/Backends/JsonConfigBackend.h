#pragma once
#include "Engine/Config/Backends/ConfigBackend.h"
#include "Engine/Config/Config.h"


class JsonConfigBackend : public ConfigBackend
{
public:
	typedef ConfigBackend super;

	JsonConfigBackend( const std::string& filename );
	virtual ~JsonConfigBackend();

	ConfigError Read( json& data );
	ConfigError Save( json& data );

	std::string			m_filename;
};

