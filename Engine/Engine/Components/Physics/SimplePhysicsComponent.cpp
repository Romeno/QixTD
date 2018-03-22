#include "stdafx.h"
#include "SimplePhysicsComponent.h"
#include "Engine/Entity.h"
#include "Math/Math.h"


SimplePhysicsComponent::SimplePhysicsComponent()
	: super()

	, m_wPos(0, 0, 0)
	, m_size(0, 0, 0)
	, m_direction(0, 0, 0)
	, m_velocity(0.)
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
	m_wPos += m_direction * m_velocity;
}


glm::dvec3 SimplePhysicsComponent::GetWPos()
{
	return GetRectCenter( m_wPos, m_size );
}


void SimplePhysicsComponent::SetWPos( glm::dvec3 wPos, Pivot pivot /*= PIVOT_CENTER */ )
{
	if ( pivot == PIVOT_CENTER ) {
		m_wPos = GetRectTopLeft( wPos, m_size );
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


void SimplePhysicsComponent::SetDirection( glm::dvec3 dir )
{
	m_direction = glm::normalize( dir );
}


void SimplePhysicsComponent::SetDirection( Direction dir )
{
	m_direction = DirToVec( dir );
}


void SimplePhysicsComponent::SetVelocity( double ms )
{
	m_velocity = ms;
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
