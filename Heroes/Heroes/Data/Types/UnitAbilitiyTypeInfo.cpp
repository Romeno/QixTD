#include "stdafx.h"
#include "UnitAbilitiyTypeInfo.h"


UnitAbilitiyTypeInfo::UnitAbilitiyTypeInfo()
	: m_id(0)
	, m_name("")
	, m_cooldown(0)
	, m_description("")
	, m_passive(false)
	, m_hasUI(true)
	, m_image("")
	, m_manaCost(0)
	, m_charges()
	, m_replenish()
{

}


UnitAbilitiyTypeInfo::~UnitAbilitiyTypeInfo()
{

}
