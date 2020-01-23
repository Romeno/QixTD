#pragma once
#include "Engine/Component.h"
#include "Engine/CoordinateSystem.h"


class PhysicsComponent : public Component
{
public:
	PhysicsComponent();
	virtual ~PhysicsComponent();

	virtual glm::dvec3 GetPrevPos() = 0;

	virtual glm::dvec3 GetPos() = 0;
	virtual void SetPos( glm::dvec3 wPos, Pivot pivot = PIVOT_CENTER ) = 0;

	virtual glm::dvec3 GetSize() = 0;
	virtual void SetSize( glm::dvec3 size ) = 0;

	virtual glm::dvec3 GetPrevDir() = 0;
	virtual Direction GetPrevDirEnum() = 0;

	virtual glm::dvec3 GetDir() = 0;
	virtual Direction GetDirEnum() = 0;

	virtual void SetDir( glm::dvec3 dir ) = 0;
	virtual void SetDir( Direction dir ) = 0;
	
	virtual double GetVelocity() = 0;
	virtual void SetVelocity( double ms ) = 0;

	virtual bool IsAbsolutePosition() = 0;
	virtual void SetAbsolutePosition(bool absolute) = 0;
};

