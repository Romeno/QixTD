#pragma once


class UnitConfigBase
{
public:
	UnitConfigBase();
	virtual ~UnitConfigBase();


	double		m_healthMax;
	double		m_attackOrig;
	double		m_defenceOrig;
	double		m_damageMinOrig;
	double		m_damageMaxOrig;
	double		m_speedOrig;

	double		m_health;
	double		m_attack;
	double		m_defence;
	double		m_damageMin;
	double		m_damageMax;
	double		m_speed;

};

