#pragma once
#include "Heroes/Data/Objects/ResourceInfo.h"


class PlayerInfo
{
public:
	PlayerInfo();
	virtual ~PlayerInfo();

	int							m_id;
	std::string					m_name;

	std::vector<ResourceInfo>	m_resources;
	bool						m_aiControlled;



};

