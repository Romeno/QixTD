#pragma once
#include "Engine/Components/Physics/SimplePhysicsComponent.h"


class QixHeroPhysComponent : public SimplePhysicsComponent
{
public:
	typedef SimplePhysicsComponent super;

	QixHeroPhysComponent();
	virtual ~QixHeroPhysComponent();


	virtual void Tick( Uint32 diff ) override;

};

