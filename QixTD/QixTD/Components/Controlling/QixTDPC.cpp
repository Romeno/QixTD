#include "stdafx.h"
#include "QixTDPC.h"
#include "Engine/Entity.h"
#include "QixTD/QixTD.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Input/Keyboard.h"


QixTDPC::QixTDPC()
	: m_onBorder( false )
	, m_haveBeenOnBorderOnce( false)
	, m_firstTick( true )
	, m_drawingBorder( false )
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
	//if ( m_firstTick )
	//{
	//	CheckIfPointOnBorder(m_object->m_real->GetPos());
	//	m_firstTick = false;
	//}

	CheckIfPointOnBorder( m_object->m_real->GetPos() );

	// если находится не на границе, используя текущую позицию продлить последнюю нарисованную границу
	if ( !m_onBorder && m_haveBeenOnBorderOnce )
	{
		//if ( m_object->m_real->GetVelocity() > std::numeric_limits<double>::epsilon() )
		//{
		GAME->m_borders.back().second = m_object->m_real->GetPos();
		//}
	}

	// если отпущена стрелка - приказать остановиться
	if ( keyboard->IsKeyReleased( SDL_SCANCODE_LEFT ) )
	{
		RequestStopMoveLeft();
	}
	else if ( keyboard->IsKeyReleased( SDL_SCANCODE_RIGHT ) )
	{
		RequestStopMoveRight();
	}
	else if ( keyboard->IsKeyReleased( SDL_SCANCODE_UP ) )
	{
		RequestStopMoveUp();
	}
	else if ( keyboard->IsKeyReleased( SDL_SCANCODE_DOWN ) )
	{
		RequestStopMoveDown();
	}

	// если стрелки нажаты, приказать начать движение в нужную сторону (со следующего кадра)
	if ( keyboard->IsKeyDown( SDL_SCANCODE_LEFT ) )
	{
		RequestStartMoveLeft();
		//Entity* hero = GAME->GetHero();
		//(QixTDPC*)(hero->m_rozum)
	}
	else if ( keyboard->IsKeyDown( SDL_SCANCODE_RIGHT ) )
	{
		RequestStartMoveRight();
	}
	else if ( keyboard->IsKeyDown( SDL_SCANCODE_UP ) )
	{
		RequestStartMoveUp();
	}
	else if ( keyboard->IsKeyDown( SDL_SCANCODE_DOWN ) )
	{
		RequestStartMoveDown();
	}
	else if ( keyboard->IsKeyDown( SDL_SCANCODE_SPACE ) )
	{
		RequestShoot();
	}

	m_onBorder = false;
}


void QixTDPC::Clear()
{

}


void QixTDPC::CheckIfPointOnBorder( const glm::dvec3& point )
{
	bool drawingCompleted = false;

	for ( auto b : GAME->m_borders )
	{
		if ( b.completed && IsPointOn90DegreeAlignedLine( b.first, b.second, point, 2 ) )
		{
			m_onBorder = true;
			m_haveBeenOnBorderOnce = true;

			if ( m_drawingBorder )
			{
				drawingCompleted = true;
			}
			m_drawingBorder = false;
			ILOGA( "point on border" );
		}
	}

	if ( drawingCompleted )
	{
		for ( auto& b : GAME->m_borders )
		{
			if ( !b.completed )
			{
				b.completed = true;
			}
		}
	}
}


bool QixTDPC::CheckIfPointOnBorderSimple( const glm::dvec3& point )
{
	bool res = false;

	Uint32 tickTime = SDL_GetTicks();

	for ( auto b : GAME->m_borders )
	{
		if ( b.completeTickTime != 0 &&										// if border is completed
			 b.completeTickTime < GAME->m_prevTickTime &&					// not the last tick
			 IsPointOn90DegreeAlignedLine( b.first, b.second, point, 2 ) )	// 
		{
			res = true;
		}
	}

	return res;
}


bool QixTDPC::WasPlayerOnBorderLastTick()
{
	bool res = false;

	glm::dvec3 playerPos = m_object->m_real->GetPrevPos();

	for ( auto b : GAME->m_borders )
	{
		if ( b.completeTickTime != 0 &&											// if border is completed
			b.completeTickTime < GAME->m_prevTickTime &&						// not the last tick
			IsPointOn90DegreeAlignedLine( b.first, b.second, playerPos, 2 ) )	// 
		{
			res = true;
		}
	}

	return res;
}


int QixTDPC::RequestStartMoveLeft()
{
	// не выполнять приказ движения, если за пределами карты
	if ( m_object->m_real->GetPos().x < -GAME->m_currentMap->m_mapDimensions.x / 2 )
	{
		return 0;
	}


	if ( ( WasPlayerOnBorderLastTick() &&		// was on border last tick
		!m_onBorder ) ||
		( m_object->m_real->GetDirEnum() != DIR_LEFT &&
		  m_drawingBorder )
		) 						// now is not on border
	{
		// then from last tick to current there were a border drawned
		StartNewBorder( m_object->m_real->GetPrevPos(), m_object->m_real->GetPos() );
	}

	glm::dvec3 predictedFuturePos = PredictFuturePos( QixTDPC::PLAYER_VELOCITY, DIR_LEFT );
	if (   ( m_object->m_real->GetDirEnum() != DIR_LEFT 
			&& !m_onBorder )   // если новое направление и он не на границе (тогда это под вопросом надо вообще или нет)
		|| ( m_onBorder 
			&& !CheckIfPointOnBorderSimple( predictedFuturePos ) 
			&& GAME->m_currentMap->m_mapRect.ContainsRect( { GetRectTopLeft( predictedFuturePos, m_object->m_real->GetSize() ), m_object->m_real->GetSize() } )
			)   // или если будущая позиция будет не на границе
		)
	{
		StartNewBorder( m_object->m_real->GetPrevPos(), m_object->m_real->GetPos() );
	}


	//glm::dvec3 predictedFuturePos = PredictFuturePos( QixTDPC::PLAYER_VELOCITY, DIR_LEFT );
	//if (   ( m_object->m_real->GetDirEnum() != DIR_LEFT 
	//		&& !m_onBorder )   // если новое направление и он не на границе (тогда это под вопросом надо вообще или нет)
	//	|| ( m_onBorder 
	//		&& !CheckIfPointOnBorderSimple( predictedFuturePos ) 
	//		&& GAME->m_currentMap->m_mapRect.ContainsRect( { GetRectTopLeft( predictedFuturePos, m_object->m_real->GetSize() ), m_object->m_real->GetSize() } )
	//		)   // или если будущая позиция будет не на границе
	//	)
	//{
	//	StartNewBorder();
	//}

	// установить скорость и направление
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
	if ( m_object->m_real->GetPos().x > GAME->m_currentMap->m_mapDimensions.x / 2 )
	{
		return 0;
	}

	//glm::dvec3 predictedFuturePos = PredictFuturePos( QixTDPC::PLAYER_VELOCITY, DIR_RIGHT );
	//if ( (m_object->m_real->GetDirEnum() != DIR_RIGHT 
	//	  && !m_onBorder)		// если новое направление и он не на границе (тогда это под вопросом надо вообще или нет)
	//	|| ( m_onBorder 
	//		&& !CheckIfPointOnBorderSimple( predictedFuturePos )
	//		&& GAME->m_currentMap->m_mapRect.ContainsRect( { GetRectTopLeft( predictedFuturePos, m_object->m_real->GetSize() ), m_object->m_real->GetSize() } )
	//		)   // или если будущая позиция будет не на границе
	//	)
	//{
	//	StartNewBorder();
	//}

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
	if ( m_object->m_real->GetPos().y > GAME->m_currentMap->m_mapDimensions.y / 2 )
	{
		return 0;
	}

	//glm::dvec3 predictedFuturePos = PredictFuturePos( QixTDPC::PLAYER_VELOCITY, DIR_TOP );

	//if ( (m_object->m_real->GetDirEnum() != DIR_TOP 
	//	  && !m_onBorder)							// если новое направление и он не на границе (тогда это под вопросом надо вообще или нет)
	//	|| ( m_onBorder 
	//		&& !CheckIfPointOnBorderSimple( predictedFuturePos )
	//		&& GAME->m_currentMap->m_mapRect.ContainsRect( { GetRectTopLeft( predictedFuturePos, m_object->m_real->GetSize() ), m_object->m_real->GetSize() } )
	//		)   // или если будущая позиция будет не на границе
	//	)
	//{
	//	StartNewBorder();
	//}

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
	if ( m_object->m_real->GetPos().y < -GAME->m_currentMap->m_mapDimensions.y / 2 )
	{
		return 0;
	}

	//glm::dvec3 predictedFuturePos = PredictFuturePos( QixTDPC::PLAYER_VELOCITY, DIR_BOTTOM );
	//if ( (m_object->m_real->GetDirEnum() != DIR_BOTTOM 
	//	  && !m_onBorder)		 // если новое направление и он не на границе (тогда это под вопросом надо вообще или нет)
	//	|| (m_onBorder 
	//		&& !CheckIfPointOnBorderSimple( predictedFuturePos )
	//		&& GAME->m_currentMap->m_mapRect.ContainsRect( { GetRectTopLeft(predictedFuturePos, m_object->m_real->GetSize() ), m_object->m_real->GetSize() } )
	//		)   // или если будущая позиция будет не на границе
	//	)
	//{
	//	StartNewBorder();
	//}

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


void QixTDPC::StartNewBorder( glm::dvec3 point1, glm::dvec3 point2 )
{
	m_drawingBorder = true;
	GAME->m_borders.push_back( { point1, point2, true, SDL_GetTicks() } );
}


glm::dvec3 QixTDPC::PredictFuturePos( double velocity, Direction dir )
{
	return m_object->m_real->GetPos() + velocity * Dir2Vec( dir );
}


template <>
void Entity::AddComponent( QixTDPC* component )
{
	m_rozum = component;
	component->m_object = this;
}
