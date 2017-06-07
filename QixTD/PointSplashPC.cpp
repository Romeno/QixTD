#include "stdafx.h"
#include "Defines.h"

#ifdef POINT_SPLASH_GAME_TYPE

#include "PointSplashPC.h"
#include "IH.h"
#include "WindowTitleManager.h"
#include "GameManager.h"
#include "Utils.h"


PointSplashPC::PointSplashPC()
	: m_wPoints()

	, m_primitivecount(0)

	, m_maxDistanceFromCenter(50)
{

}


PointSplashPC::~PointSplashPC()
{

}


void PointSplashPC::Tick(Uint32 diff)
{
	WindowTitleManager::Inst()->AddToWindowTitle(std::to_string(m_primitivecount));
}


void PointSplashPC::Render()
{
	DrawPoints();
}


void PointSplashPC::DrawPoints()
{
	SDL_SetRenderDrawColor(REN, 255, 255, 255, 0);

	IH()->Lock();

	for (int i = 0; i < m_wPoints.size(); ++i) {
		SDL_RenderDrawPoint(REN, W2Sx(m_wPoints[i].x), W2Sy(m_wPoints[i].y));
	}

	IH()->Unlock();
}


void PointSplashPC::ClearPoints()
{
	IH()->Lock();

	m_wPoints.clear();

	m_primitivecount = 0;

	IH()->Unlock();
}


void PointSplashPC::AddPoint()
{
	IH()->Lock();

	glm::dvec3 center = IH()->m_lastMouseWPos;

	float angle = Random(0, 2 * M_PI);

	m_wPoints.push_back({ 
		center.x + Random(0, m_maxDistanceFromCenter) * cos(angle),
		center.y + Random(0, m_maxDistanceFromCenter) * sin(angle),
		0
	});

	m_primitivecount++;

	IH()->Unlock();
}


void PointSplashPC::SetWPos(glm::dvec3 plrWPos, Pivot pivot)
{
	m_wPos = plrWPos;
}


glm::dvec3 PointSplashPC::GetWPos()
{
	return m_wPos;
}

#endif