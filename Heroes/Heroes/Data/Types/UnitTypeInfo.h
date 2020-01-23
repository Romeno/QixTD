#pragma once


enum DamageType
{
	DAMAGE_TYPE_NORMAL,
	DAMAGE_TYPE_SIZE
};


enum MovementType
{
	MOVEMENT_TYPE_WALK,
	MOVEMENT_TYPE_SIZE
};


enum Faction
{
	FACTION_UNDEAD,
	FACTION_SIZE
};


class UnitTypeInfo
{
public:
	UnitTypeInfo();
	virtual ~UnitTypeInfo();

	int						m_id;
	std::string				m_name;
	std::string				m_description;
	std::string				m_image;
	std::vector<int>		m_abilitiyIds;
	double					m_hpMax;
	double					m_dmgMin;
	double					m_dmgMax;
	double					m_attack;
	double					m_defense;
	double					m_initiative;
	double					m_speed;
	double					m_range;
	bool					m_ranged;
	int						m_shootsMax;
	DamageType				m_dmgType;
	MovementType			m_moveType;

	// speed at which image moves on the screen
	double					m_graphicalSpeed;

	// times of animations
	double					m_attackTime;
	double					m_moveStepTime;
	double					m_deathTime;
	double					m_hitTime;

	Faction					m_faction;
};

