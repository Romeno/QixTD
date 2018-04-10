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
	
	/*
	 * if m_absolutePosition is set then position returned is rPos 
	 * else it is wPos
	 */
	virtual glm::dvec3 GetPos() override;				

	/* if m_absolutePosition is set then pos is rPos 
	 * else pos is wPos
	 */
	virtual void SetPos( glm::dvec3 pos, Pivot pivot = PIVOT_CENTER ) override;

	virtual glm::dvec3 GetSize() override;
	virtual void SetSize( glm::dvec3 size ) override;

	virtual glm::dvec3 GetDir() override;
	virtual Direction GetDirEnum() override;

	virtual void SetDir( glm::dvec3 dir ) override;
	virtual void SetDir( Direction dir ) override;

	virtual double GetVelocity() override;
	virtual void SetVelocity( double ms ) override;

	virtual bool IsAbsolutePosition() override;
	virtual void SetAbsolutePosition( bool absolute ) override;

	/* position of top left corner in World coordinates if m_absolutePosition is set
	 * else rPos
	 */
	glm::dvec3			m_pos;							

	glm::dvec3			m_size;
	glm::dvec3			m_direction;
	double				m_velocity;

	bool				m_absolutePosition;




};

