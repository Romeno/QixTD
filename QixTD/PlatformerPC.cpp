#include "stdafx.h"
#include "Defines.h"

#ifdef PLATFORMER_GAME_TYPE

#include "PlatformerPC.h"
#include "SC.h"
#include "GameManager.h"
#include "Logger.h"
#include "Utils.h"
#include "LevelInfo.h"


Uint32 TickPlrCtrl(Uint32 interval, void *param);


PlatformerPC::PlatformerPC()
	: m_imageWidth(100)
	, m_imageHeight(100)
	, m_collider({18, 19, 61, 63})
	, m_moveSpeed(3)
	
	//, m_pos({ (int)(GameManager::Inst()->vpWidth - m_width) / 2, (int)(GameManager::Inst()->vpHeight - m_height) / 2 })
	//, m_precisePosY()

	, m_timerId(0)
	, m_timerInterval(10)

	, m_wPos({ 0, 0, 0 })
	, m_tryingToMove(false)
	, m_moving(false)
	, m_facing(Direction::DIR_LEFT)

	, m_jumpInfo()
	, m_plrTex(nullptr)
{
	//m_timerId = SDL_AddTimer(m_timerInterval, TickPlrCtrl, NULL);
}


PlatformerPC::~PlatformerPC()
{
	//SDL_RemoveTimer(m_timerId);
}


void PlatformerPC::Clear()
{
	cleanup(m_plrTex);
}


int PlatformerPC::Init()
{
	std::string imagePath = GetResourcePath() + "Gluka2.png";
	SDL_Surface *img = IMG_Load(imagePath.c_str());
	if (img == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "IMG_Load error: %s", SDL_GetError());
		cleanup(img);
		return 1;
	}

	m_plrTex = SDL_CreateTextureFromSurface(REN, img);
	cleanup(img);
	if (m_plrTex == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "SDL_CreateTextureFromSurface error: %s", SDL_GetError());
		cleanup(m_plrTex);
		return 1;
	}

	return 0;
}


void PlatformerPC::SetWPos(glm::dvec3 plrWPos, Pivot pivot)
{
	if (pivot == Pivot::PIVOT_CENTER)
	{
		m_wPos = { plrWPos.x - (double)m_imageWidth / 2.0, plrWPos.y + (double)m_imageHeight / 2.0, 0 };
	}
	else
	{
		ERR(ERR_TYPE_PROGRAMMING_ERROR, "Unknown pivot: %d", pivot);
	}
}


void PlatformerPC::Render()
{
	SDL_Rect dstrect = {
		W2Sx(m_wPos.x),
		W2Sy(m_wPos.y),
		m_imageWidth,
		m_imageHeight
	};
	SDL_RenderCopy(REN, m_plrTex, NULL, &dstrect);
}


int PlatformerPC::RequestStartMoveLeft()
{
	//if (m_moving) 
	//{
	//	if (m_facing & Direction::DIR_RIGHT)
	//	{
	//		// do nothing
	//	}
	//}

	m_facing = Direction::DIR_LEFT;
	m_tryingToMove = true;

	return 1;
}


int PlatformerPC::RequestStopMoveLeft() 
{
	//m_facing &= ~Direction::DIR_LEFT;
	m_tryingToMove = false;

	return 1;
}


int PlatformerPC::RequestStartMoveRight()
{
	//if (!(m_facing & Direction::DIR_LEFT))
	//{
	//	m_facing |= Direction::DIR_RIGHT;
	//}
	m_facing = Direction::DIR_RIGHT;
	m_tryingToMove = true;

	//if (m_pos.x < GameManager::Inst()->vpWidth - m_width)
	//{
	//	m_pos.x += m_moveSpeed;
	//	return 0;
	//}

	return 1;
}


int PlatformerPC::RequestStopMoveRight()
{
	//m_facing &= ~Direction::DIR_RIGHT;
	//if (m_facing & Direction::DIR_LEFT)
	//{
	//	m_tryingToMove = false;
	//}
	m_tryingToMove = false;

	return 1;
}


int PlatformerPC::RequestStartMoveUp()
{
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


int PlatformerPC::RequestStopMoveUp()
{
	//m_facing &= ~Direction::DIR_TOP;
	//m_tryingToMove = false;

	return 1;
}


int PlatformerPC::RequestStartMoveDown()
{
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


int PlatformerPC::RequestStopMoveDown()
{
	//m_facing &= ~Direction::DIR_BOTTOM;
	//m_tryingToMove = false;

	return 1;
}


int PlatformerPC::RequestJump()
{
	if (!m_jumpInfo.jumping)
	{
		m_jumpInfo.jumping = true;
		//jumpInfo.elapsedTime = 0;
		m_jumpInfo.startTime = std::chrono::high_resolution_clock::now();
		//jumpInfo.startTime = SDL_GetTicks();
		return 1;
	}

	return 0;
}


//void PlrCtrl::Tick(Uint32 diff)
//{
//	if (m_jumpInfo.jumping) 
//	{
//		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
//
//		//Uint32 now = SDL_GetTicks();
//		
//		//if (now - m_jumpInfo.startTime > m_jumpInfo.jumpDuration) 
//		//{
//		//	m_jumpInfo.jumping = false;
//		//}
//		//else
//		//{
//			double dy = jumpInfo.jumpSpeed * cos((double)(now.time_since_epoch().count() - jumpInfo.startTime.time_since_epoch().count()) / (double)jumpInfo.jumpDuration.count() * M_PI);
//			std::cout << "Jump value " << dy << std::endl;
//			m_pos.y -= dy;
//		//}
//			
//			/*if (now - jumpInfo.startTime > jumpInfo.jumpDuration / 2)
//		{
//			m_pos.y += jumpInfo.jumpSpeed;
//		}
//		else 
//		{
//			m_pos.y -= jumpInfo.jumpSpeed;
//		}*/
//	}
//}


//Uint32 PlrCtrl::Tick(Uint32 interval)
void PlatformerPC::Tick(Uint32 diff)
{
	if (m_tryingToMove) 
	{
		if (m_facing & Direction::DIR_LEFT) 
		{
			if ((int)m_wPos.x > (int)-LevelInfo::Inst()->m_levelLength / 2) 
			{
				m_wPos.x -= m_moveSpeed;
				m_moving = true;
			}

			m_moving = false;
		}

		if (m_facing & Direction::DIR_RIGHT)
		{
			if ((int)m_wPos.x < (int)LevelInfo::Inst()->m_levelLength / 2)
			{
				m_wPos.x += m_moveSpeed;
				m_moving = true;
			}

			m_moving = false;
		}
	}

	if (m_jumpInfo.jumping)
	{
		//std::cout << "interval " << interval << std::endl;

		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();

		//Uint32 now = SDL_GetTicks();

		if (now.time_since_epoch().count() - m_jumpInfo.startTime.time_since_epoch().count() > m_jumpInfo.jumpDuration.count())
		{
			m_jumpInfo.jumping = false;
		}
		else
		{
			//jumpInfo.elapsedTime += interval;
			double dy = m_jumpInfo.jumpSpeed * cos((double)(now.time_since_epoch().count() - m_jumpInfo.startTime.time_since_epoch().count()) / (double)m_jumpInfo.jumpDuration.count() * M_PI);
			//double dy = jumpInfo.jumpSpeed * cos((double)(jumpInfo.elapsedTime) / (double)jumpInfo.jumpDuration * M_PI);
			//m_precisePosY -= dy;

			//std::cout << "Jump value " << dy << std::endl;
			m_wPos.y += dy;
		}

		/*if (now - jumpInfo.startTime > jumpInfo.jumpDuration / 2)
		{
		m_pos.y += jumpInfo.jumpSpeed;
		}
		else
		{
		m_pos.y -= jumpInfo.jumpSpeed;
		}*/
	}

	//return m_timerInterval;
}


Uint32 TickPlrCtrl(Uint32 interval, void *param)
{
	//return PlrCtrl::Inst()->Tick(interval);
	return 10;
}

#endif