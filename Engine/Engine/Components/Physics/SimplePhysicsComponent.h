#pragma once
#include "Engine/Components/PhysicsComponent.h"


class SimplePhysicsComponent : public PhysicsComponent
{
public:
	typedef PhysicsComponent super;

	SimplePhysicsComponent();
	virtual ~SimplePhysicsComponent();

	virtual int Init() override;

	virtual void PreTick( Uint32 diff ) override;
	virtual void Tick( Uint32 diff ) override;
	virtual void PostTick( Uint32 diff ) override;


	virtual glm::dvec3 GetPrevPos() override;
	virtual glm::dvec3 GetFuturePos() override;

	/*
	 * if m_absolutePosition is set then position returned is rPos 
	 * else it is wPos
	 * Returns position of center of the object
	 */
	virtual glm::dvec3 GetPos() override;				

	/* if m_absolutePosition is set then pos is rPos 
	 * else pos is wPos
	 * Returns position of center of the object
	 */
	virtual void SetPos( glm::dvec3 pos, Pivot pivot = PIVOT_CENTER ) override;
	
	virtual glm::dvec3 GetSize() override;
	virtual void SetSize( glm::dvec3 size ) override;

	virtual glm::dvec3 GetDir() override;
	virtual Direction GetDirEnum() override;
	virtual void SetDir( glm::dvec3 dir ) override;
	virtual void SetDir( Direction dir ) override;

	virtual double GetVelocity() override;
	virtual void SetVelocity( double velocity ) override;

	virtual bool IsAbsolutePosition() override;
	virtual void SetAbsolutePosition( bool absolute ) override;

	
	/* Next are fundamental characteristics of object physics component.
	 * 
	 * The first and main data item is Position.
	 *
	 * When ticking the world it is necessary to make computations for the CURRENT tick.
	 * If one object is affecting another 
	 * then position and/or other physical data can change during the Tick.
	 * This can lead to uncontrollable change in these data items 
	 * as order of calling Tick across all objects is unspecified.
	 * 
	 * For this reason it is necessary to introduce 'future' versions of these data items.
	 * Before Tick happens future data items are set as current. 
	 * This happens in PreTick (called for all objects before Tick).
	 *
	 * All actions that change these paired (future, current) data items should change future versions.
	 * But accessing should preferably use current data items
	 * 
	 * Not all data items need to be duplicated like pos and dir as not all data items of physics component change
	 * and other object depend on them that much. 
	 * 
	 * Will extend this as needed.
	 * 
	 */

	/* Position comprises coordinates of top left corner in World coordinates
	 * if m_absolutePosition is set position is in Romeno coordinates
	 */
	glm::dvec3			m_previousPos;
	glm::dvec3			m_pos;
	glm::dvec3			m_futurePos;

	glm::dvec3			m_previousDir;
	glm::dvec3			m_dir;
	glm::dvec3			m_futureDir;

	glm::dvec3			m_size;
	glm::dvec3			m_futureSize;

	double				m_velocity;
	double				m_futureVelocity;

	bool				m_absolutePosition;






};

