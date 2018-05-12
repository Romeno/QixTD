#pragma once
#include "Engine/Components/Physics/SimplePhysicsComponent.h"


class QixPhysComponent : public SimplePhysicsComponent
{
public:
	typedef SimplePhysicsComponent super;

	QixPhysComponent();
	virtual ~QixPhysComponent();


	virtual void Tick( Uint32 diff ) override;

};

