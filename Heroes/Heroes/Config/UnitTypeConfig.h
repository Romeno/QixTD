#pragma once
#include "Engine/Config/Config.h"
#include "Heroes/Data/Types/UnitTypeInfo.h"
#include "Math/Math.h"


class UnitTypeConfig :	public Config
{
public:
	typedef UnitTypeConfig thisT;
	typedef Config super;

	UnitTypeConfig( );
	virtual ~UnitTypeConfig();

	//static void LoadFromJson( json& data, thisT* conf );
	//static AppConfig LoadFromDB(  );
	//static void LoadFromRConfig( const std::string& data, thisT* conf );
	static void LoadFromCsv( csv::ifstream&, std::vector<UnitTypeInfo>* conf );

	//virtual void Parse( std::ifstream& strm ) override;

	static std::string		m_unitIdKey;
	static std::string		m_unitNameKey;
	static std::string		m_imageKey;
	static std::string		m_abilitiyIdsKey;
	static std::string		m_hpMaxKey;
	static std::string		m_dmgMinKey;
	static std::string		m_dmgMaxKey;
	static std::string		m_attackKey;
	static std::string		m_defenseKey;
	static std::string		m_initiativeKey;
	static std::string		m_speedKey;
	static std::string		m_rangeKey;
	static std::string		m_shootsMaxKey;
	static std::string		m_rangedKey;
	static std::string		m_damageTypeKey;
	static std::string		m_movementTypeKey;
	static std::string		m_graphicalSpeedKey;
	static std::string		m_attackTimeKey;
	static std::string		m_moveStepTimeKey;
	static std::string		m_deathTimeKey;
	static std::string		m_hitTimeKey;
	static std::string		m_factionKey;

};

