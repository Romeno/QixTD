#include "stdafx.h"
#include "QixMonsterPhysComponent.h"
#include "Engine/Utils/Utils.h"
#include "QixTD/QixTD.h"


QixMonsterPhysComponent::QixMonsterPhysComponent()
{

}


QixMonsterPhysComponent::~QixMonsterPhysComponent()
{

}


void QixMonsterPhysComponent::Tick( Uint32 diff )
{
	m_prevPos = m_pos;
	m_prevDir = m_dir;

	// calculate pos
	m_pos += m_dir * m_velocity;

	if ( !GAME->m_currentMap->m_mapRect.ContainsRect( { m_pos, m_size } ) )
	{
		m_pos = GAME->m_currentMap->m_mapRect.ClosestRectOfSameSizeInsideThisRect( { m_pos, m_size } ).m_topLeft;
	}
}


template <>
void Entity::AddComponent( QixMonsterPhysComponent* component )
{
	//SafeDelete( m_real );

	m_real = component;
	component->m_object = this;
}
