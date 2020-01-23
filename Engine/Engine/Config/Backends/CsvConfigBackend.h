#pragma once
#include "Engine/Config/Backends/ConfigBackend.h"
#include "Engine/Config/Config.h"


class CsvConfigBackend : public ConfigBackend
{
public:
	typedef CsvConfigBackend thisT;
	typedef ConfigBackend super;

	CsvConfigBackend( const std::string& filename );
	virtual ~CsvConfigBackend();
	
	ConfigError Read( csv::ifstream& istrm );
	ConfigError Save( csv::ifstream& istrm );

	std::string			m_filename;
};

