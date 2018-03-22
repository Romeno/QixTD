#pragma once
#include "HeroesBase/HeroesBase.h"


class Heroes : public HeroesBase
{
public:
	Heroes();
	virtual ~Heroes();


	virtual InputHandler* Input() override;
	virtual Camera* Camera_() override;
	virtual int LoadLevel( int num ) override;

};

