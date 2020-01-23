#include "stdafx.h"
#include "QixTDPC.h"
#include "Engine/Entity.h"
#include "QixTD/QixTD.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Input/Keyboard.h"


QixTDPC::QixTDPC()
	: m_onOwnTerritory( false )
	, m_haveBeenOnOwnTerritoryOnce( false)
	, m_drawingBorder( false )
	, m_startedBorder( false )
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
	m_startedBorder = false;
	m_onOwnTerritory = false;

	if ( !m_object || !m_object->m_firstTickHappened )
	{
		m_onOwnTerritory = IsOnOwnTerritory( m_object->m_real->GetPos() );
	}

	// если отпущена стрелка - приказать остановиться
	if ( keyboard->IsKeyReleased( SDL_SCANCODE_LEFT ) ||
		keyboard->IsKeyReleased( SDL_SCANCODE_RIGHT ) ||
		keyboard->IsKeyReleased( SDL_SCANCODE_UP ) || 
		keyboard->IsKeyReleased( SDL_SCANCODE_DOWN ) )
	{
		OrderStop();
	}

	// если стрелки нажаты, приказать начать движение в нужную сторону (со следующего кадра)
	if ( keyboard->IsKeyDown( SDL_SCANCODE_LEFT ) )
	{
		OrderStartMoveLeft();
	}
	else if ( keyboard->IsKeyDown( SDL_SCANCODE_RIGHT ) )
	{
		OrderStartMoveRight();
	}
	else if ( keyboard->IsKeyDown( SDL_SCANCODE_UP ) )
	{
		OrderStartMoveUp();
	}
	else if ( keyboard->IsKeyDown( SDL_SCANCODE_DOWN ) )
	{
		OrderStartMoveDown();
	}
	else if ( keyboard->IsKeyDown( SDL_SCANCODE_SPACE ) )
	{
		OrderShoot();
	}

	CompleteBorders();

	// если находится не на захваченной территории или рисуется граница, начать новую или продлить последнюю нарисованную границу
	if ( !m_onOwnTerritory && m_haveBeenOnOwnTerritoryOnce && !m_drawingBorder )
	{
		StartNewBorder( m_object->m_real->GetPrevPos(), m_object->m_real->GetPos() );
	}
	else if ( m_drawingBorder )
	{
		GAME->m_borders.back().second = m_object->m_real->GetPos();
	}
	
	if ( m_object->m_real->GetDirEnum() != m_object->m_real->GetPrevDirEnum() &&	// direction has changed
		 m_drawingBorder &&
		 !m_startedBorder			// prevent several border starts same tick
		) 						
	{
		// then start new border. for now it has same start and end
		StartNewBorder( m_object->m_real->GetPos(), m_object->m_real->GetPos() );
	}

	//glm::dvec3 predictedFuturePos = PredictFuturePos( QixTDPC::PLAYER_VELOCITY, DIR_LEFT );
	//if (   ( m_object->m_real->GetDirEnum() != DIR_LEFT 
	//		&& !m_onOwnTerritory )   // если новое направление и он не на границе (тогда это под вопросом надо вообще или нет)
	//	|| ( m_onOwnTerritory 
	//		&& !CheckIfPointOnBorderSimple( predictedFuturePos ) 
	//		&& GAME->m_currentMap->m_mapRect.ContainsRect( { GetRectTopLeft( predictedFuturePos, m_object->m_real->GetSize() ), m_object->m_real->GetSize() } )
	//		)   // или если будущая позиция будет не на границе
	//	)
	//{
	//	StartNewBorder( m_object->m_real->GetPrevPos(), m_object->m_real->GetPos() );
	//}
}


bool QixTDPC::IsOnOwnTerritory( glm::dvec3 pos )
{
	bool res = false;

	for ( auto b : GAME->m_borders )
	{
		if ( b.completeTickTime != 0 &&											// if border is completed
			b.completeTickTime < GAME->m_curTickTime &&							// not completed just now
			IsPointOn90DegreeAlignedLine( b.first, b.second, pos, 2 ) )			// 
		{
			res = true;
		}
	}

	// TODO: Add check for not only on border but also on own territory (crossed the border during tick) (tunneling)

	return res;
}


void QixTDPC::CompleteBorders()
{
	bool drawingCompleted = false;

	for ( auto b : GAME->m_borders )
	{
		if ( b.completeTickTime != 0 && 
			IsPointOn90DegreeAlignedLine( b.first, b.second, m_object->m_real->GetPos(), 2 ) )
		{
			m_onOwnTerritory = true;
			m_haveBeenOnOwnTerritoryOnce = true;

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
			if ( b.completeTickTime == 0 )
			{
				b.completeTickTime = GAME->m_curTickTime;
			}
		}
	}
}


void QixTDPC::StartNewBorder( glm::dvec3 point1, glm::dvec3 point2 )
{
	m_startedBorder = true;
	m_drawingBorder = true;
	GAME->m_borders.push_back( { point1, point2, true, 0 } );
}


//bool QixTDPC::CheckIfPointOnBorderSimple( const glm::dvec3& point )
//{
//	bool res = false;
//
//	Uint32 tickTime = SDL_GetTicks();
//
//	for ( auto b : GAME->m_borders )
//	{
//		if ( b.completeTickTime != 0 &&										// if border is completed
//			 b.completeTickTime < GAME->m_prevTickTime &&					// not the last tick
//			 IsPointOn90DegreeAlignedLine( b.first, b.second, point, 2 ) )	// 
//		{
//			res = true;
//		}
//	}
//
//	return res;
//}


int QixTDPC::OrderStop()
{
	m_object->m_real->SetVelocity( 0 );

	return 0;
}


int QixTDPC::OrderStartMoveLeft()
{
	// не выполнять приказ движения, если за пределами карты
	if ( m_object->m_real->GetPos().x < -GAME->m_currentMap->m_mapDimensions.x / 2 )
	{
		return 0;
	}

	//if ( ( IsOnOwnTerritory( m_object->m_real->GetPrevPos() ) &&		// was on border last tick
	//	!m_onOwnTerritory ) ||
	//	( m_object->m_real->GetDirEnum() != DIR_LEFT &&
	//	  m_drawingBorder )
	//	) 						// now is not on border
	//{
	//	// then from last tick to current there were a border drawn
	//	StartNewBorder( m_object->m_real->GetPrevPos(), m_object->m_real->GetPos() );
	//}

	//glm::dvec3 predictedFuturePos = PredictFuturePos( QixTDPC::PLAYER_VELOCITY, DIR_LEFT );
	//if (   ( m_object->m_real->GetDirEnum() != DIR_LEFT 
	//		&& !m_onOwnTerritory )   // если новое направление и он не на границе (тогда это под вопросом надо вообще или нет)
	//	|| ( m_onOwnTerritory 
	//		&& !CheckIfPointOnBorderSimple( predictedFuturePos ) 
	//		&& GAME->m_currentMap->m_mapRect.ContainsRect( { GetRectTopLeft( predictedFuturePos, m_object->m_real->GetSize() ), m_object->m_real->GetSize() } )
	//		)   // или если будущая позиция будет не на границе
	//	)
	//{
	//	StartNewBorder( m_object->m_real->GetPrevPos(), m_object->m_real->GetPos() );
	//}

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
		m_object->m_real->SetVelocity( GAME->m_playerConfig->m_playerVelocity );
	}
	m_object->m_real->SetDir( Direction::DIR_LEFT );

	return 0;
}


int QixTDPC::OrderStartMoveRight()
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
		m_object->m_real->SetVelocity( GAME->m_playerConfig->m_playerVelocity );
	}
	m_object->m_real->SetDir( Direction::DIR_RIGHT );

	return 0;
}


int QixTDPC::OrderStartMoveUp()
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
		m_object->m_real->SetVelocity( GAME->m_playerConfig->m_playerVelocity );
	}
	m_object->m_real->SetDir( Direction::DIR_TOP );

	return 0;
}


int QixTDPC::OrderStartMoveDown()
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
		m_object->m_real->SetVelocity( GAME->m_playerConfig->m_playerVelocity );
	}
	m_object->m_real->SetDir( Direction::DIR_BOTTOM );

	return 0;
}


int QixTDPC::OrderShoot()
{
	return 0;
}


void QixTDPC::Clear()
{

}


//
//glm::dvec3 QixTDPC::PredictFuturePos( double velocity, Direction dir )
//{
//	return m_object->m_real->GetPos() + velocity * Dir2Vec( dir );
//}


template <>
void Entity::AddComponent( QixTDPC* component )
{
	m_rozum = component;
	component->m_object = this;
}