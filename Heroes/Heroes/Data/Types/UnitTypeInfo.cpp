#include "stdafx.h"
#include "UnitTypeInfo.h"


UnitTypeInfo::UnitTypeInfo()
	: m_id( 0 )
	, m_name( "" )
	, m_description( "" )
	, m_image( "" )
	, m_abilitiyIds()
	, m_hpMax( 0 )
	, m_dmgMin( 0 )
	, m_dmgMax( 0 )
	, m_attack( 0 )
	, m_defense( 0 )
	, m_initiative( 0 )
	, m_speed( 0 )
	, m_range( 0 )
	, m_ranged( 0 )
	, m_shootsMax( 0 )
	, m_dmgType( DAMAGE_TYPE_NORMAL )
	, m_moveType( MOVEMENT_TYPE_WALK )
	, m_graphicalSpeed( 0 )
	, m_attackTime( 0 )
	, m_moveStepTime( 0 )
	, m_deathTime( 0 )
	, m_hitTime( 0 )
	, m_faction( FACTION_UNDEAD )
{

}


UnitTypeInfo::~UnitTypeInfo()
{

}
