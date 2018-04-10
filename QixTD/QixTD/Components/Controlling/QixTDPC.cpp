#include "stdafx.h"
#include "QixTDPC.h"
#include "Engine/Entity.h"
#include "QixTD/QixTD.h"
#include "Engine/Utils/Utils.h"


QixTDPC::QixTDPC()
{

}


QixTDPC::~QixTDPC()
{

}


int QixTDPC::Init()
{
	return super::Init();
}


void QixTDPC::Tick( Uint32 diff )
{
	if ( m_object->m_real->GetVelocity() > std::numeric_limits<double>::epsilon() )
	{
		GAME->m_borders.back().second = m_object->m_real->GetPos();
	}
}


void QixTDPC::Clear()
{

}


int QixTDPC::RequestStartMoveLeft()
{
	if ( m_object->m_real->GetDirEnum() == DIR_LEFT )
	{
		StartNewBorder();
	}

	if ( m_object->m_real->GetVelocity() < std::numeric_limits<double>::epsilon() )
	{
		m_object->m_real->SetVelocity( PLAYER_VELOCITY );
	}
	m_object->m_real->SetDir( Direction::DIR_LEFT );

	return 1;
}


int QixTDPC::RequestStopMoveLeft()
{
	m_object->m_real->SetVelocity( 0 );

	return 1;
}


int QixTDPC::RequestStartMoveRight()
{
	if ( m_object->m_real->GetDirEnum() != DIR_RIGHT )
	{
		StartNewBorder();
	}

	if ( m_object->m_real->GetVelocity() < std::numeric_limits<double>::epsilon())
	{
		m_object->m_real->SetVelocity( PLAYER_VELOCITY );
	}
	m_object->m_real->SetDir( Direction::DIR_RIGHT );

	return 1;
}


int QixTDPC::RequestStopMoveRight()
{
	m_object->m_real->SetVelocity( 0 );

	return 1;
}


int QixTDPC::RequestStartMoveUp()
{
	if ( m_object->m_real->GetDirEnum() != DIR_TOP )
	{
		StartNewBorder();
	}

	if ( m_object->m_real->GetVelocity() < std::numeric_limits<double>::epsilon() )
	{
		m_object->m_real->SetVelocity( PLAYER_VELOCITY );
	}
	m_object->m_real->SetDir( Direction::DIR_TOP );

	return 1;
}


int QixTDPC::RequestStopMoveUp()
{
	m_object->m_real->SetVelocity( 0 );

	return 1;
}


int QixTDPC::RequestStartMoveDown()
{
	if ( m_object->m_real->GetDirEnum() != DIR_BOTTOM )
	{
		StartNewBorder();
	}

	if ( m_object->m_real->GetVelocity() < std::numeric_limits<double>::epsilon() )
	{
		m_object->m_real->SetVelocity( PLAYER_VELOCITY );
	}
	m_object->m_real->SetDir( Direction::DIR_BOTTOM );

	return 1;
}


int QixTDPC::RequestStopMoveDown()
{
	m_object->m_real->SetVelocity( 0 );

	return 1;
}


int QixTDPC::RequestShoot()
{
	return 1;
}


void QixTDPC::StartNewBorder()
{
	GAME->m_borders.push_back( { m_object->m_real->GetPos(), m_object->m_real->GetPos() } );
}


template <>
void Entity::AddComponent( QixTDPC* component )
{
	m_rozum = component;
	component->m_object = this;
}
