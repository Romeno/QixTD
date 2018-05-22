#pragma once
#include "Engine/Components/Physics/SimplePhysicsComponent.h"


class QixMonsterPhysComponent : public SimplePhysicsComponent
{
public:
	typedef SimplePhysicsComponent super;

	QixMonsterPhysComponent();
	virtual ~QixMonsterPhysComponent();


	virtual void Tick( Uint32 diff ) override;

};

