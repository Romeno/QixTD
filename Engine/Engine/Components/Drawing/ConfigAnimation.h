#pragma once
#include "Engine/Components/Drawing/AnimatedSprite.h"


class AnimationConfig;


class ConfigAnimation : public AnimatedSprite
{
public:
	typedef AnimatedSprite super;

	ConfigAnimation();
	virtual ~ConfigAnimation();



	AnimationConfig*	m_config;
};

