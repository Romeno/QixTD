#pragma once
#include "Engine/Config/Config.h"


class AppConfig : public Config
{
public:
	typedef AppConfig thisT;
	typedef Config super;

	AppConfig();

	static void LoadFromJson( json& data, AppConfig* conf );
	//static AppConfig LoadFromDB(  );
	static void LoadFromRConfig( const std::string& data, AppConfig* conf );

	//virtual void Parse(std::ifstream& strm) override;

	std::string				m_windowTitle;
	int						m_numMaps;

	static std::string		s_windowTitleKey;
	static std::string		s_numMapsKey;
};


void to_json( json& j, const AppConfig& d );
void from_json( const json& j, AppConfig& d );