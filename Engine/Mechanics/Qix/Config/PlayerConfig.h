#pragma once
#include "Engine/Config/Config.h"


class PlayerConfig : public Config
{
public:
	typedef Config super;

	PlayerConfig();
	virtual ~PlayerConfig();

	virtual void Parse(std::ifstream& strm) override;

	double m_playerVelocity;
	std::string m_playerVelocityKey;
};

