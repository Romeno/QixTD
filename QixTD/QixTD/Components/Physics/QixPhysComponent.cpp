#include "stdafx.h"
#include "QixPhysComponent.h"
#include "Engine/Utils/Utils.h"
#include "QixTD/QixTD.h"


QixPhysComponent::QixPhysComponent()
{

}


QixPhysComponent::~QixPhysComponent()
{

}


void QixPhysComponent::Tick( Uint32 diff )
{
	glm::dvec3 futurePos = m_pos + m_direction * m_velocity;

	if ( m_velocity > std::numeric_limits<double>::epsilon() )
	{
		GAME->m_borderInProgress = true;
	}

	if ( GAME->m_currentMap->m_mapRect.ContainsRect( { futurePos, m_size } ) )
	{
		m_pos = futurePos;
	}
	else
	{
		m_pos = GAME->m_currentMap->m_mapRect.ClosestRectOfSameSizeInsideThisRect( { futurePos, m_size } ).m_topLeft;
	}
}


template <>
void Entity::AddComponent( QixPhysComponent* component )
{
	//SafeDelete( m_real );

	m_real = component;
	component->m_object = this;
}
