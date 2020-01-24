#include "stdafx.h"
#include "UnitTypeConfig.h"


std::string UnitTypeConfig::m_unitIdKey("unitId");
std::string UnitTypeConfig::m_unitNameKey("unitName");
std::string UnitTypeConfig::m_imageKey("unitImage");
std::string UnitTypeConfig::m_abilitiyIdsKey("unitAbilitiIds");
std::string UnitTypeConfig::m_hpMaxKey("unitHp");
std::string UnitTypeConfig::m_dmgMinKey("unitDmgMin");
std::string UnitTypeConfig::m_dmgMaxKey("unitDmgMax");
std::string UnitTypeConfig::m_attackKey("unitAttack");
std::string UnitTypeConfig::m_defenseKey("unitDefense");
std::string UnitTypeConfig::m_initiativeKey("unitInitiative");
std::string UnitTypeConfig::m_speedKey("unitSpeed");
std::string UnitTypeConfig::m_rangeKey("unitRange");
std::string UnitTypeConfig::m_shootsMaxKey("unitShootsMax");
std::string UnitTypeConfig::m_rangedKey("unitRanged");
std::string UnitTypeConfig::m_damageTypeKey("unitDmgType");
std::string UnitTypeConfig::m_movementTypeKey("unitMoveType");
std::string UnitTypeConfig::m_graphicalSpeedKey("unitGraphSpeed");
std::string UnitTypeConfig::m_attackTimeKey("unitAttackTime");
std::string UnitTypeConfig::m_moveStepTimeKey("unitMoveStepTime");
std::string UnitTypeConfig::m_deathTimeKey("unitDeathTime");
std::string UnitTypeConfig::m_hitTimeKey("unitHitTime");
std::string UnitTypeConfig::m_factionKey("unitFaction");


UnitTypeConfig::UnitTypeConfig( )
	: super()
{

}


UnitTypeConfig::~UnitTypeConfig()
{

}


void UnitTypeConfig::LoadFromCsv( csv::ifstream&, std::vector<UnitTypeInfo>* conf )
{

}


//void UnitConfig::Parse( std::ifstream& strm )
//{
//	std::vector<std::string> parts;
//	std::string s;
//	char line[255];
//	while ( !strm.eof() ) {
//		strm.getline( line, 255 );
//		s = line;
//		s = pys::strip( s );
//
//		if ( s.empty() )
//			continue;
//
//		pys::split( s, parts, "=", 1 );
//
//		parts[0] = pys::strip( parts[0] );
//		if ( parts[0] == m_hpMaxKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_hpMax = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_dmgMinKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_dmgMin = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_dmgMaxKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_dmgMax = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_attackKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_attack = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_defenseKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_defense = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_initiativeKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_initiative = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_speedKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_speed = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_rangeKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_range = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_shootsMaxKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_shootsMax = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_rangedKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_ranged = ParseBool( parts[1] );
//		}
//		else if ( parts[0] == m_damageTypeKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_damageType = (DamageType) ParseInt( parts[1] );
//		}
//		else if ( parts[0] == m_movementTypeKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_movementType = (MovementType) ParseInt( parts[1] );
//		}
//		else if ( parts[0] == m_graphicalSpeedKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_graphicalSpeed = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_attackTimeKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_attackTime = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_moveStepTimeKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_moveStepTime = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_deathTimeKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_deathTime = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_hitTimeKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_hitTime = ParseDouble( parts[1] );
//		}
//		else if ( parts[0] == m_factionKey ) 
//		{
//			parts[1] = pys::strip( parts[1] );
//
//			m_faction = (Faction) ParseInt( parts[1] );
//		}
//		else
//		{
//          // TODO: add error handling
//          ELOG( ERR_TYPE_VALUE_ERROR, "Parse error." );
//		}
//	}
//}

