#pragma once
#include "Engine/Components/PhysicsComponent.h"


class b2Body;


class Box2DPhysicsComponent : public PhysicsComponent
{
public:
	typedef PhysicsComponent super;

	Box2DPhysicsComponent();
	virtual  ~Box2DPhysicsComponent();

	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;

	virtual glm::dvec3 GetPos() override;
	virtual void SetPos( glm::dvec3 wPos, Pivot pivot = PIVOT_CENTER ) override;
	
	virtual glm::dvec3 GetSize() override;
	virtual void SetSize( glm::dvec3 size ) override;

	virtual Direction GetDirEnum() override;
	virtual glm::dvec3 GetDir() override;

	virtual void SetDir( glm::dvec3 dir ) override;
	virtual void SetDir( Direction dir ) override;
	
	virtual double GetVelocity() override;
	virtual void SetVelocity( double ms ) override;

	virtual bool IsAbsolutePosition() override;
	virtual void SetAbsolutePosition( bool absolute ) override;

	b2Body*		m_body;
	b2BodyDef*	m_bodyDef;
	double		z;


	static b2World* s_world;




};

