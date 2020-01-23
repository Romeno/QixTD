#include "stdafx.h"
#include "QixPC.h"
#include "Engine/Utils/Utils.h"
#include "Mechanics/Qix/Config/PlayerConfig.h"
#include "Math/Math.h"


QixPC::QixPC()
	: super()

    //, m_sprite(nullptr)
	//, m_lastTurnPos(0, 0, 0)
	//, m_playerImagePath("Gluka.png")
	//, m_playerShootImagePath("Gluka.png")
{

}


QixPC::~QixPC()
{

}


int QixPC::Init()
{
    return 0;
}


void QixPC::Tick(Uint32 diff)
{
  //  if (m_sprite) {
  //      if (m_tryingToMove)
  //      {
  //          if (m_facing & Direction::DIR_LEFT)
  //          {
  //              if ((int)m_sprite->m_wPos.x > (int)-GameManager::Inst()->m_currentMap->m_mapDimensions.x / 2)
  //              {
  //                  m_sprite->m_wPos.x -= m_moveSpeed;
  //                  m_moving = true;
		//			GameManager::Inst()->m_borderController->NotifyMovement(m_sprite->GetRectCenter());
  //              }

  //              m_moving = false;
  //          }

  //          if (m_facing & Direction::DIR_RIGHT)
  //          {
  //              if ((int)m_sprite->m_wPos.x < (int)GameManager::Inst()->m_currentMap->m_mapDimensions.x / 2 - (int)m_sprite->m_size.x)
  //              {
  //                  m_sprite->m_wPos.x += m_moveSpeed;
  //                  m_moving = true;
		//			GameManager::Inst()->m_borderController->NotifyMovement(m_sprite->GetRectCenter());
  //              }

  //              m_moving = false;
  //          }

		//	if (m_facing & Direction::DIR_TOP)
		//	{
		//		if ((int)m_sprite->m_wPos.y < (int)GameManager::Inst()->m_currentMap->m_mapDimensions.y / 2)
		//		{
		//			m_sprite->m_wPos.y += m_moveSpeed;
		//			m_moving = true;
		//			GameManager::Inst()->m_borderController->NotifyMovement(m_sprite->GetRectCenter());
		//		}

		//		m_moving = false;
		//	}
		//
		//	if (m_facing & Direction::DIR_BOTTOM)
		//	{
		//		if ((int)m_sprite->m_wPos.y > (int)-GameManager::Inst()->m_currentMap->m_mapDimensions.y / 2 + (int)m_sprite->m_size.y)
		//		{
		//			m_sprite->m_wPos.y -= m_moveSpeed;
		//			m_moving = true;
		//			GameManager::Inst()->m_borderController->NotifyMovement(m_sprite->GetRectCenter());
		//		}

		//		m_moving = false;
		//	}
		//}
  //  }
}


void QixPC::Clear()
{

}


int QixPC::OrderStartMoveLeft()
{
	if ( m_object->m_real->GetVelocity() < std::numeric_limits<double>::epsilon() && m_object->m_real->GetDirEnum() == DIR_LEFT )
	{
		m_object->m_real->SetVelocity( 9. );
		m_object->m_real->SetDir( Direction::DIR_LEFT );
	}


	//if (m_moving) 
	//{
	//	if (m_facing & Direction::DIR_RIGHT)
	//	{
	//		// do nothing
	//	}
	//}

	//if (m_facing != Direction::DIR_LEFT) 
	//{
	//	//m_lastTurnPos = m_sprite->GetRectCenter();
	//	StartNewBorder();
	//}

	//m_facing = Direction::DIR_LEFT;
	//m_tryingToMove = true;

	return 1;
}


int QixPC::OrderStop()
{
	m_object->m_real->SetVelocity( 0 );

	////m_facing &= ~Direction::DIR_LEFT;
	//m_tryingToMove = false;

	return 1;
}


int QixPC::OrderStartMoveRight()
{
	m_object->m_real->SetVelocity( 9. );
	m_object->m_real->SetDir( Direction::DIR_RIGHT );

	//if (!(m_facing & Direction::DIR_LEFT))
	//{
	//	m_facing |= Direction::DIR_RIGHT;
	//}

	//if (m_facing != Direction::DIR_RIGHT)
	//{
	//	m_lastTurnPos = m_sprite->GetRectCenter();
	//	StartNewBorder();
	//}

	//m_facing = Direction::DIR_RIGHT;
	//m_tryingToMove = true;

	//if (m_pos.x < GameManager::Inst()->vpWidth - m_width)
	//{
	//	m_pos.x += m_moveSpeed;
	//	return 0;
	//}

	return 1;
}


int QixPC::OrderStartMoveUp()
{
	m_object->m_real->SetVelocity( 9. );
	m_object->m_real->SetDir( Direction::DIR_TOP );

	//if (m_facing != Direction::DIR_TOP)
	//{
	//	m_lastTurnPos = m_sprite->GetRectCenter();
	//	StartNewBorder();
	//}

	//m_facing = Direction::DIR_TOP;
	//m_tryingToMove = true;

	//if (!(m_facing & Direction::DIR_BOTTOM))
	//{
	//	m_facing |= Direction::DIR_TOP;
	//}
	//m_tryingToMove = true;

	//if (m_pos.y > 0)
	//{
	//	m_pos.y -= m_moveSpeed;
	//	return 0;
	//}

	return 1;
}


int QixPC::OrderStartMoveDown()
{
	m_object->m_real->SetVelocity( 9. );
	m_object->m_real->SetDir( Direction::DIR_BOTTOM );

	//if (m_facing != Direction::DIR_BOTTOM)
	//{
	//	m_lastTurnPos = m_sprite->GetRectCenter();
	//	StartNewBorder();
	//}

	//m_facing = Direction::DIR_BOTTOM;
	//m_tryingToMove = true;

	//if (!(m_facing & Direction::DIR_TOP))
	//{
	//	m_facing |= Direction::DIR_BOTTOM;
	//}
	//m_tryingToMove = true;

	//if (m_pos.y < GameManager::Inst()->vpHeight - m_height)
	//{
	//	m_pos.y += m_moveSpeed;
	//	return 0;
	//}

	return 1;
}


//void QixPC::SetWPos(glm::dvec3 wPos, Pivot pivot)
//{
//    m_sprite->SetWPos(wPos, pivot);
//	m_lastTurnPos = wPos;
//}


int QixPC::OrderShoot()
{
// 	Sprite* shoot = new Sprite("shoot", m_playerShootImagePath, glm::dvec3(10, 10, 0));
// 	shoot->Init();
// 	shoot->SetWPos(GetShootPos());
// 	shoot->SetDirection((Direction)m_facing);
// 	shoot->SetMoveSpeed(3);
// 	shoot->SetTimeToLive(5);
// 	GameManager::Inst()->RegisterDrawable(shoot);

	return 0;
}


template <>
void Entity::AddComponent(QixPC* component)
{
	//SafeDelete( m_rozum );

	m_rozum = component;
	component->m_object = this;
}
