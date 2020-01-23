#pragma once
#include "Engine/Config/Config.h"


class PlayerConfig : public Config
{
public:
	typedef PlayerConfig thisT;
	typedef Config super;

	PlayerConfig();
	virtual ~PlayerConfig();

	static void LoadFromJson( json& data, PlayerConfig* conf );
	//static AppConfig LoadFromDB(  );
	static void LoadFromRConfig( const std::string& data, PlayerConfig* conf );

	//virtual void Parse(std::ifstream& strm) override;

	double				m_playerVelocity;

	static std::string	s_playerVelocityKey;
};

void to_json( json& j, const PlayerConfig& d );
void from_json( const json& j, PlayerConfig& d );
