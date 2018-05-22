#include "stdafx.h"
#include "SimplePhysicsComponent.h"
#include "Engine/Entity.h"
#include "Math/Math.h"
#include "Engine/Utils/Utils.h"


SimplePhysicsComponent::SimplePhysicsComponent()
	: super()

	, m_previousPos( 0, 0, 0 )
	, m_pos(0, 0, 0)
	, m_futurePos(0, 0, 0)

	, m_previousDir( 0, 0, 0 )
	, m_dir( 0, 0, 0 )
	, m_futureDir(0, 0, 0)

	, m_size(0, 0, 0)
	, m_futureSize(0, 0, 0)

	, m_velocity(0.)
	, m_futureVelocity( 0. )

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
	m_previousPos = m_pos;
	m_previousDir = m_dir;

	// set direction and pos from prev tick as current 
	m_pos = m_futurePos;
	m_dir = m_futureDir;
	m_size = m_futureSize;
	m_velocity = m_futureVelocity;
}


void SimplePhysicsComponent::Tick( Uint32 diff )
{
	// calculate pos
	m_futurePos += m_dir * m_velocity;
}


void SimplePhysicsComponent::PostTick( Uint32 diff )
{

}


glm::dvec3 SimplePhysicsComponent::GetPrevPos()
{
	return m_previousPos;
}


glm::dvec3 SimplePhysicsComponent::GetFuturePos()
{
	return m_futurePos;
}


glm::dvec3 SimplePhysicsComponent::GetPos()
{
	return GetRectCenter( m_pos, m_size );
}


void SimplePhysicsComponent::SetPos( glm::dvec3 pos, Pivot pivot /*= PIVOT_CENTER */ )
{
	if ( pivot == PIVOT_CENTER ) {
		m_futurePos = GetRectTopLeft( pos, m_size );
	}
	else
	{
		throw "shit";
	}

	if ( !m_object || !m_object->m_firstTickHappened )
	{
		m_pos = m_futurePos;
		m_previousPos = m_pos;
	}
}


glm::dvec3 SimplePhysicsComponent::GetSize()
{
	return m_size;
}


void SimplePhysicsComponent::SetSize( glm::dvec3 size )
{
	m_futureSize = size;

	if ( !m_object || !m_object->m_firstTickHappened )
	{
		m_size = m_futureSize;
	}
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
	m_futureDir = glm::normalize( dir );

	if ( !m_object || !m_object->m_firstTickHappened )
	{
		m_dir = m_futureDir;
		m_previousDir = m_dir;
	}
}


void SimplePhysicsComponent::SetDir( Direction dir )
{
	m_futureDir = Dir2Vec( dir );

	if ( !m_object || !m_object->m_firstTickHappened )
	{
		m_dir = m_futureDir;
		m_previousDir = m_dir;
	}
}


double SimplePhysicsComponent::GetVelocity()
{
	return m_velocity;
}


void SimplePhysicsComponent::SetVelocity( double velocity )
{
	m_futureVelocity = velocity;

	if ( !m_object || !m_object->m_firstTickHappened )
	{
		m_velocity = m_futureVelocity;
	}
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
