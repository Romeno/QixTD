#include "stdafx.h"
#include "Box2DPhysicsComponent.h"
#include "Engine/Entity.h"
#include "Engine/Utils/Utils.h"


b2World* Box2DPhysicsComponent::s_world = nullptr;


bool Box2DPhysicsComponent::IsAbsolutePosition()
{
	return false;
}


void Box2DPhysicsComponent::SetAbsolutePosition( bool absolute )
{

}

Box2DPhysicsComponent::Box2DPhysicsComponent()
	: super()

	, m_body(nullptr)
	, m_bodyDef(new b2BodyDef())

	, z(0.)
{
	m_bodyDef->type = b2_dynamicBody;
}


Box2DPhysicsComponent::~Box2DPhysicsComponent()
{
	if ( m_body ) s_world->DestroyBody( m_body );
	del( m_bodyDef );
}


int Box2DPhysicsComponent::Init()
{
	m_body = s_world->CreateBody( m_bodyDef );

	return super::Init();
}


void Box2DPhysicsComponent::Tick( Uint32 diff )
{

}


glm::dvec3 Box2DPhysicsComponent::GetPos()
{
	if ( m_body )
	{
		const b2Vec2& pos = m_body->GetPosition();
		return glm::dvec3( pos.x, pos.y, z);
	}
	else
	{
		return glm::dvec3( m_bodyDef->position.x, m_bodyDef->position.y, z );
	}
}


void Box2DPhysicsComponent::SetPos( glm::dvec3 wPos, Pivot pivot /*= PIVOT_CENTER */ )
{
	if ( m_body )
	{
		m_body->SetTransform( { (float32)wPos.x, (float32) wPos.y }, m_body->GetAngle() );
		z = wPos.z;
	}
	else
	{
		m_bodyDef->position.Set( (float32) wPos.x, (float32) wPos.y );
		z = wPos.z;
	}
}


glm::dvec3 Box2DPhysicsComponent::GetSize()
{
	if ( m_body )
	{
		b2Fixture* fs = m_body->GetFixtureList();
		b2Shape* sh = fs->GetShape();


// 		m_body->( { wPos.x, wPos.y }, m_body->GetAngle() );
	}
	else
	{
// 		m_bodyDef->position.Set( wPos.x, wPos.y );
	}
	return glm::dvec3();
}


void Box2DPhysicsComponent::SetSize( glm::dvec3 size )
{

}


glm::dvec3 Box2DPhysicsComponent::GetDir()
{
	return glm::dvec3();
}


Direction Box2DPhysicsComponent::GetDirEnum()
{
	return DIR_UNKNOWN;
}


void Box2DPhysicsComponent::SetDir( glm::dvec3 dir )
{

}


void Box2DPhysicsComponent::SetDir( Direction dir )
{

}


double Box2DPhysicsComponent::GetVelocity()
{
	return 0.;
}


void Box2DPhysicsComponent::SetVelocity( double ms )
{

}


template <>
void Entity::AddComponent( Box2DPhysicsComponent* component )
{
	m_real = component;
	component->m_object = this;
}





