#pragma once
#include "Engine/Components/PhysicsComponent.h"


class SimplePhysicsComponent : public PhysicsComponent
{
public:
	typedef PhysicsComponent super;

	SimplePhysicsComponent();
	virtual ~SimplePhysicsComponent();

	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;
	
	virtual glm::dvec3 GetWPos() override;
	virtual void SetWPos( glm::dvec3 wPos, Pivot pivot = PIVOT_CENTER ) override;

	virtual glm::dvec3 GetSize() override;
	virtual void SetSize( glm::dvec3 size ) override;

	virtual glm::dvec3 GetDir() override;
	virtual void SetDirection( glm::dvec3 dir ) override;
	virtual void SetDirection( Direction dir ) override;

	virtual double GetVelocity() override;
	virtual void SetVelocity( double ms ) override;

	glm::dvec3			m_wPos;						// position of top left corner in World coordinates
	glm::dvec3			m_size;
	glm::dvec3			m_direction;
	double				m_velocity;

};

