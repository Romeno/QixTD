#include "stdafx.h"
#include "SimplePhysicsComponent.h"
#include "Engine/Entity.h"
#include "Math/Math.h"


SimplePhysicsComponent::SimplePhysicsComponent()
	: super()

	, m_pos(0, 0, 0)
	, m_size(0, 0, 0)
	, m_direction(0, 0, 0)
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


void SimplePhysicsComponent::Tick( Uint32 diff )
{
	m_pos += m_direction * m_velocity;
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
		throw "shit";
	}
}


void SimplePhysicsComponent::SetSize( glm::dvec3 size )
{
	m_size = size;
}


glm::dvec3 SimplePhysicsComponent::GetDir()
{
	return m_direction;
}


Direction SimplePhysicsComponent::GetDirEnum()
{
	return VecToDir( m_direction );
}


void SimplePhysicsComponent::SetDir( glm::dvec3 dir )
{
	m_direction = glm::normalize( dir );
}


void SimplePhysicsComponent::SetDir( Direction dir )
{
	m_direction = DirToVec( dir );
}


void SimplePhysicsComponent::SetVelocity( double ms )
{
	m_velocity = ms;
}


bool SimplePhysicsComponent::IsAbsolutePosition()
{
	return m_absolutePosition;
}


void SimplePhysicsComponent::SetAbsolutePosition( bool absolute )
{
	m_absolutePosition = absolute;
}


glm::dvec3 SimplePhysicsComponent::GetSize()
{
	return m_size;
}


double SimplePhysicsComponent::GetVelocity()
{
	return m_velocity;
}


template <>
void Entity::AddComponent( SimplePhysicsComponent* component )
{
	m_real = component;
	component->m_object = this;
}
