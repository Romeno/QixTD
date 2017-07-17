#include "stdafx.h"
#include "QixPC.h"
#include "GameManager.h"
#include "Utils.h"
#include "Logger.h"
#include "MapConfigStub.h"
#include "LineCascade.h"
#include "my_math.h"


QixPC::QixPC()
	: PlayerController()
	, m_moveSpeed(3)

	, m_tryingToMove(false)
	, m_moving(false)
	, m_facing(DIR_UNKNOWN)

    , m_sprite(nullptr)
	, m_lastTurnPos(0, 0, 0)
	, m_playerImagePath("Gluka.png")
	, m_playerShootImagePath("Gluka.png")
{

}


QixPC::~QixPC()
{

}


int QixPC::Init()
{
    m_sprite = new Sprite("character", m_playerImagePath, glm::dvec3(100.0, 100.0, 0));
    m_sprite->Init();

    return 0;
}


void QixPC::Tick(Uint32 diff)
{
    if (m_sprite) {
        if (m_tryingToMove)
        {
            if (m_facing & Direction::DIR_LEFT)
            {
                if ((int)m_sprite->m_wPos.x > (int)-GameManager::Inst()->m_currentMap->m_mapDimensions.x / 2)
                {
                    m_sprite->m_wPos.x -= m_moveSpeed;
                    m_moving = true;
					GameManager::Inst()->m_borderController->NotifyMovement(m_sprite->GetRectCenter());
                }

                m_moving = false;
            }

            if (m_facing & Direction::DIR_RIGHT)
            {
                if ((int)m_sprite->m_wPos.x < (int)GameManager::Inst()->m_currentMap->m_mapDimensions.x / 2 - (int)m_sprite->m_size.x)
                {
                    m_sprite->m_wPos.x += m_moveSpeed;
                    m_moving = true;
					GameManager::Inst()->m_borderController->NotifyMovement(m_sprite->GetRectCenter());
                }

                m_moving = false;
            }

			if (m_facing & Direction::DIR_TOP)
			{
				if ((int)m_sprite->m_wPos.y < (int)GameManager::Inst()->m_currentMap->m_mapDimensions.y / 2)
				{
					m_sprite->m_wPos.y += m_moveSpeed;
					m_moving = true;
					GameManager::Inst()->m_borderController->NotifyMovement(m_sprite->GetRectCenter());
				}

				m_moving = false;
			}
		
			if (m_facing & Direction::DIR_BOTTOM)
			{
				if ((int)m_sprite->m_wPos.y > (int)-GameManager::Inst()->m_currentMap->m_mapDimensions.y / 2 + (int)m_sprite->m_size.y)
				{
					m_sprite->m_wPos.y -= m_moveSpeed;
					m_moving = true;
					GameManager::Inst()->m_borderController->NotifyMovement(m_sprite->GetRectCenter());
				}

				m_moving = false;
			}
		}
    }
}


void QixPC::Clear()
{
    delete m_sprite;
}


int QixPC::RequestStartMoveLeft()
{
	//if (m_moving) 
	//{
	//	if (m_facing & Direction::DIR_RIGHT)
	//	{
	//		// do nothing
	//	}
	//}

	if (m_facing != Direction::DIR_LEFT) 
	{
		m_lastTurnPos = m_sprite->GetRectCenter();
		StartNewBorder();
	}

	m_facing = Direction::DIR_LEFT;
	m_tryingToMove = true;

	return 1;
}


int QixPC::RequestStopMoveLeft()
{
	//m_facing &= ~Direction::DIR_LEFT;
	m_tryingToMove = false;

	return 1;
}


int QixPC::RequestStartMoveRight()
{
	//if (!(m_facing & Direction::DIR_LEFT))
	//{
	//	m_facing |= Direction::DIR_RIGHT;
	//}

	if (m_facing != Direction::DIR_RIGHT)
	{
		m_lastTurnPos = m_sprite->GetRectCenter();
		StartNewBorder();
	}

	m_facing = Direction::DIR_RIGHT;
	m_tryingToMove = true;

	//if (m_pos.x < GameManager::Inst()->vpWidth - m_width)
	//{
	//	m_pos.x += m_moveSpeed;
	//	return 0;
	//}

	return 1;
}


int QixPC::RequestStopMoveRight()
{
	//m_facing &= ~Direction::DIR_RIGHT;
	//if (m_facing & Direction::DIR_LEFT)
	//{
	//	m_tryingToMove = false;
	//}
	m_tryingToMove = false;

	return 1;
}


int QixPC::RequestStartMoveUp()
{
	if (m_facing != Direction::DIR_TOP)
	{
		m_lastTurnPos = m_sprite->GetRectCenter();
		StartNewBorder();
	}

	m_facing = Direction::DIR_TOP;
	m_tryingToMove = true;

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


int QixPC::RequestStopMoveUp()
{
	//m_facing &= ~Direction::DIR_TOP;
	m_tryingToMove = false;

	return 1;
}


int QixPC::RequestStartMoveDown()
{
	if (m_facing != Direction::DIR_BOTTOM)
	{
		m_lastTurnPos = m_sprite->GetRectCenter();
		StartNewBorder();
	}

	m_facing = Direction::DIR_BOTTOM;
	m_tryingToMove = true;

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


int QixPC::RequestStopMoveDown()
{
	//m_facing &= ~Direction::DIR_BOTTOM;
	m_tryingToMove = false;

	return 1;
}




void QixPC::Possess(Sprite* sprite)
{
    m_sprite = sprite;
}


void QixPC::Render()
{
    m_sprite->Render();
}


void QixPC::SetWPos(glm::dvec3 wPos, Pivot pivot)
{
    m_sprite->SetWPos(wPos, pivot);
	m_lastTurnPos = wPos;
}


void QixPC::StartNewBorder()
{
	GameManager::Inst()->m_borderController->AddLine(m_lastTurnPos, m_sprite->GetRectCenter());
}


int QixPC::RequestShoot()
{
	Sprite* shoot = new Sprite("shoot", m_playerShootImagePath, glm::dvec3(10, 10, 0));
	shoot->Init();
	shoot->SetWPos(glm::dvec3(0, 0, 0));
	shoot->SetDirection((Direction)m_facing);
	//shoot->SetMoveSpeed(10);
	//shoot->SetTimeToLive(5);
	GameManager::Inst()->RegisterDrawable(shoot);

	return 0;
}
