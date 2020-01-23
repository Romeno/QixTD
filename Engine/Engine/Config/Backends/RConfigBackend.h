#pragma once
#include "Engine/Config/Backends/ConfigBackend.h"
#include "Engine/Config/Config.h"


class RConfigBackend : public ConfigBackend
{
public:
	typedef ConfigBackend super;

	RConfigBackend( const std::string& filename );
	virtual ~RConfigBackend();

	ConfigError Read( std::string& data );
	ConfigError Save( const std::string& data );

	std::string			m_filename;
};

