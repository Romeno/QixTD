#pragma once


class UnitAbilitiyTypeInfo
{
public:
	UnitAbilitiyTypeInfo();
	virtual ~UnitAbilitiyTypeInfo();

	int							m_id;
	std::string					m_name;
	double						m_cooldown;
	std::string					m_description;

	bool						m_passive;
	bool						m_hasUI;
	std::string					m_image;
	int							m_manaCost;
	int							m_charges;
	double						m_replenish; // 1 charge replenish time (sec)

};

