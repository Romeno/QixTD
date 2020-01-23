#pragma once
#include "Engine/Config/Config.h"


class BattleObjectConfig : public Config
{
public:
	typedef Config super;

	BattleObjectConfig();
	virtual ~BattleObjectConfig();

	//virtual void Parse( std::ifstream& strm ) override;


	static std::string		m_objectIdKey;
	static std::string		m_objectNameKey;
	static std::string		m_objectPathingKey;

};

