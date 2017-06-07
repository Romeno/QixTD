#include "stdafx.h"
#include "QixPC.h"
#include "GameManager.h"
#include "Utils.h"
#include "Logger.h"


QixPC::QixPC()
	: m_imageWidth(100)
	, m_imageHeight(100)
	, m_moveSpeed(3)

	, m_wPos( {0, 0, 0} )
	, m_tryingToMove(false)
	, m_moving(false)
	, m_facing(Direction::DIR_LEFT)

	, m_plrTex(nullptr)
{

}


QixPC::~QixPC()
{

}


int QixPC::Init()
{
	std::string imagePath = GetResourcePath() + "Gluka.png";
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


void QixPC::Render()
{
	SDL_Rect dstrect = {
		W2Sx(m_wPos.x),
		W2Sy(m_wPos.y),
		m_imageWidth,
		m_imageHeight
	};
	SDL_RenderCopy(REN, m_plrTex, NULL, &dstrect);
}


void QixPC::Tick(Uint32 diff)
{
	if (m_tryingToMove)
	{
		if (m_facing & Direction::DIR_LEFT)
		{
			if ((int)m_wPos.x > (int)-GameManager::Inst()->vpWidth / 2)
			{
				m_wPos.x -= m_moveSpeed;
				m_moving = true;
			}

			m_moving = false;
		}

		if (m_facing & Direction::DIR_RIGHT)
		{
			if ((int)m_wPos.x < (int)GameManager::Inst()->vpWidth / 2)
			{
				m_wPos.x += m_moveSpeed;
				m_moving = true;
			}

			m_moving = false;
		}
	}
}


void QixPC::Clear()
{

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
	//m_tryingToMove = false;

	return 1;
}


int QixPC::RequestStartMoveDown()
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


int QixPC::RequestStopMoveDown()
{
	//m_facing &= ~Direction::DIR_BOTTOM;
	//m_tryingToMove = false;

	return 1;
}