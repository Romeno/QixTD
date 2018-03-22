#pragma once
#include "Engine/Config/AnimationConfig.h"


class RomenoAnimConfig : public AnimationConfig
{
public:
	typedef AnimationConfig super;

	RomenoAnimConfig(const std::string path);
	virtual ~RomenoAnimConfig();

	virtual void Parse( std::ifstream& strm ) override;

};

