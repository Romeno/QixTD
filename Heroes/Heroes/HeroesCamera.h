#pragma once
#include "Engine/Camera.h"


class HeroesCamera : public Camera
{
public:
	typedef Camera super;

	HeroesCamera();
	virtual ~HeroesCamera();


	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;
};

