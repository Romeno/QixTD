#pragma once
#include "Engine/Component.h"
#include "Engine/CoordinateSystem.h"


class PhysicsComponent : public Component
{
public:
	PhysicsComponent();
	virtual ~PhysicsComponent();

	virtual glm::dvec3 GetWPos() = 0;
	virtual void SetWPos( glm::dvec3 wPos, Pivot pivot = PIVOT_CENTER ) = 0;

	virtual glm::dvec3 GetSize() = 0;
	virtual void SetSize( glm::dvec3 size ) = 0;

	virtual glm::dvec3 GetDir() = 0;
	virtual void SetDirection( glm::dvec3 dir ) = 0;
	virtual void SetDirection( Direction dir ) = 0;
	
	virtual double GetVelocity() = 0;
	virtual void SetVelocity( double ms ) = 0;


};

