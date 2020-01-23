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
	m_prevPos = m_pos;
	m_prevDir = m_dir;

	// calculate pos
	m_pos += m_dir * m_velocity;

	//if ( m_velocity > std::numeric_limits<double>::epsilon() )
	//{
	//	GAME->m_borderInProgress = true;
	//}

	if ( !GAME->m_currentMap->m_mapRect.ContainsRect( { m_pos, m_size } ) )
	{
		m_pos = GAME->m_currentMap->m_mapRect.ClosestRectOfSameSizeInsideThisRect( { m_pos, m_size } ).m_topLeft;
	}
}


template <>
void Entity::AddComponent( QixHeroPhysComponent* component )
{
	//SafeDelete( m_real );

	m_real = component;
	component->m_object = this;
}
