#pragma once
#include "Engine/Config/Config.h"


class UnitAbilityTypeConfig : Config
{
public:
	UnitAbilityTypeConfig();
	virtual ~UnitAbilityTypeConfig();

	static std::string			s_idKey;
	static std::string			s_nameKey;
	static std::string			s_cooldownKey;
	static std::string			s_descriptionKey;

	static std::string			s_passiveKey;
	static std::string			s_hasUIKey;
	static std::string			s_imageKey;
	static std::string			s_manaCostKey;
	static std::string			s_chargesKey;
	static std::string			s_replenishKey; // 1 charge replenish time (sec)
};

