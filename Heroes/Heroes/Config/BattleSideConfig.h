#pragma once
#include "Engine/Config/Config.h"


class BattleSideConfig : public Config
{
public:
	typedef BattleSideConfig thisT;
	typedef Config super;

	BattleSideConfig( );
	virtual ~BattleSideConfig();

	static void LoadFromJson( json& data, thisT* conf );
	//static AppConfig LoadFromDB(  );
	//static void LoadFromRConfig( const std::string& data, thisT* conf );

	static std::string		s_unitIdKey;
	static std::string		s_unitCountKey;
	static std::string		s_unitPosKey;
	static std::string		s_unitDirKey;
	static std::string		s_sideIdKey;

};

void to_json( json& j, const BattleSideConfig& d );
void from_json( const json& j, BattleSideConfig& d );