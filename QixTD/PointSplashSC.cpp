#include "stdafx.h"
#include "Defines.h"

#if POINT_SPLASH_GAME_TYPE == 1 || LINE_CASCADE_GAME_TYPE == 1

#include "PointSplashSC.h"
#include "IH.h"
#include "PC.h"
#include "GameManager.h"
#include "Logger.h"
#include "Utils.h"


PointSplashSC::PointSplashSC()
	: m_scrollWidth(10)
	, m_scrollSpeed(1)
{

}


PointSplashSC::~PointSplashSC()
{

}

#include "P7_Trace.h"

void PointSplashSC::Tick(Uint32 diff)
{
	SDL_Point pos = W2S(IH()->m_lastMouseWPos);

	if (pos.x > GameManager::Inst()->vpWidth - m_scrollWidth)
	{
		m_screenWPos.x += m_scrollSpeed;
		PC()->m_wPos.x += m_scrollSpeed;
	}
	else if (pos.x < m_scrollWidth)
	{
		m_screenWPos.x -= m_scrollSpeed;
		PC()->m_wPos.x -= m_scrollSpeed;
	}
	
	if (pos.y < m_scrollWidth)
	{
		m_screenWPos.y += m_scrollSpeed;
		PC()->m_wPos.y += m_scrollSpeed;
	}
	else if (pos.y > GameManager::Inst()->vpHeight - m_scrollWidth)
	{
		m_screenWPos.y -= m_scrollSpeed;
		PC()->m_wPos.y -= m_scrollSpeed;
	}
}


#endif