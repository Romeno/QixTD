#include "stdafx.h"
#include "SimplePhysicsComponent.h"
#include "Engine/Entity.h"
#include "Math/Math.h"
#include "Engine/Utils/Utils.h"


SimplePhysicsComponent::SimplePhysicsComponent()
	: super()

	, m_prevPos( 0, 0, 0 )
	, m_pos(0, 0, 0)

	, m_prevDir( 0, 0, 0 )
	, m_dir( 0, 0, 0 )

	, m_size(0, 0, 0)

	, m_velocity(0.)

	, m_absolutePosition(false)
{

}


SimplePhysicsComponent::~SimplePhysicsComponent()
{

}


int SimplePhysicsComponent::Init()
{
	return super::Init();
}


void SimplePhysicsComponent::PreTick( Uint32 diff )
{
	//// set direction and pos from prev tick as current 
	//m_pos = m_futurePos;
	//m_dir = m_futureDir;
	//m_size = m_futureSize;
	//m_velocity = m_futureVelocity;
}


void SimplePhysicsComponent::Tick( Uint32 diff )
{
	m_prevPos = m_pos;
	m_prevDir = m_dir;

	// calculate pos
	m_pos += m_dir * m_velocity;
}


void SimplePhysicsComponent::PostTick( Uint32 diff )
{

}


glm::dvec3 SimplePhysicsComponent::GetPrevPos()
{
	return GetRectCenter( m_prevPos, m_size );
}


glm::dvec3 SimplePhysicsComponent::GetPos()
{
	return GetRectCenter( m_pos, m_size );
}


void SimplePhysicsComponent::SetPos( glm::dvec3 pos, Pivot pivot /*= PIVOT_CENTER */ )
{
	if ( pivot == PIVOT_CENTER ) {
		m_pos = GetRectTopLeft( pos, m_size );
	}
	else
	{
		// TODO: add error handling
		ELOG( ERR_TYPE_PROGRAMMING_ERROR, "Pivot != PIVOT_CENTER. Unsupported." );
	}

	if ( !m_object || !m_object->m_firstTickHappened )
	{
		m_prevPos = m_pos;
	}
}


glm::dvec3 SimplePhysicsComponent::GetSize()
{
	return m_size;
}


void SimplePhysicsComponent::SetSize( glm::dvec3 size )
{
	m_size = size;
}


glm::dvec3 SimplePhysicsComponent::GetPrevDir()
{
	return m_prevDir;
}


Direction SimplePhysicsComponent::GetPrevDirEnum()
{
	return Vec2Dir( m_prevDir );
}


glm::dvec3 SimplePhysicsComponent::GetDir()
{
	return m_dir;
}


Direction SimplePhysicsComponent::GetDirEnum()
{
	return Vec2Dir( m_dir );
}


void SimplePhysicsComponent::SetDir( glm::dvec3 dir )
{
	m_dir = glm::normalize( dir );

	if ( !m_object || !m_object->m_firstTickHappened )
	{
		m_prevDir = m_dir;
	}
}


void SimplePhysicsComponent::SetDir( Direction dir )
{
	m_dir = Dir2Vec( dir );

	if ( !m_object || !m_object->m_firstTickHappened )
	{
		m_prevDir = m_dir;
	}
}


double SimplePhysicsComponent::GetVelocity()
{
	return m_velocity;
}


void SimplePhysicsComponent::SetVelocity( double velocity )
{
	m_velocity = velocity;
}


bool SimplePhysicsComponent::IsAbsolutePosition()
{
	return m_absolutePosition;
}


void SimplePhysicsComponent::SetAbsolutePosition( bool absolute )
{
	m_absolutePosition = absolute;
}


template <>
void Entity::AddComponent( SimplePhysicsComponent* component )
{
	//SafeDelete( m_real );

	m_real = component;
	component->m_object = this;
}
