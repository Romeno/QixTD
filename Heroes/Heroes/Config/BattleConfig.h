#pragma once
#include "Engine/Config/Config.h"


class BattleConfig : public Config
{
public:
	typedef BattleConfig thisT;
	typedef Config super;

	BattleConfig();
	virtual ~BattleConfig();

	//virtual void Parse( std::ifstream& strm ) override;


	static std::string		m_sideCountKey;
	static std::string		m_arenaIdKey;
};

