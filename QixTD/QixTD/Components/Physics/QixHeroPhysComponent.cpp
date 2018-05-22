#include "stdafx.h"
#include "QixHeroPhysComponent.h"
#include "Engine/Utils/Utils.h"
#include "QixTD/QixTD.h"


QixHeroPhysComponent::QixHeroPhysComponent()
{

}


QixHeroPhysComponent::~QixHeroPhysComponent()
{

}


void QixHeroPhysComponent::Tick( Uint32 diff )
{
	// calculate pos
	m_futurePos += m_dir * m_velocity;

	if ( m_velocity > std::numeric_limits<double>::epsilon() )
	{
		GAME->m_borderInProgress = true;
	}

	if ( !GAME->m_currentMap->m_mapRect.ContainsRect( { m_futurePos, m_size } ) )
	{
		m_futurePos = GAME->m_currentMap->m_mapRect.ClosestRectOfSameSizeInsideThisRect( { m_futurePos, m_size } ).m_topLeft;
	}
}


template <>
void Entity::AddComponent( QixHeroPhysComponent* component )
{
	//SafeDelete( m_real );

	m_real = component;
	component->m_object = this;
}
