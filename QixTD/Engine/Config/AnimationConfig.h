#pragma once
#include "Engine/Config/Config.h"


class AnimationConfig : public Config
{
public:
	typedef Config super;

	AnimationConfig(const std::string& configPath);
	virtual ~AnimationConfig();

};

