#include "stdafx.h"
#include "Defines.h"

#ifdef LINE_CASCADE_GAME_TYPE

#include "IH.h"
#include "PC.h"
#include "my_math.h"
#include "WindowTitleManager.h"
#include "GameManager.h"
#include "Utils.h"


LineCascadePC::LineCascadePC()
	: m_wpStart()
	, m_wpEnd()
	, m_primitivecount(0)
	, m_maxLineLength(50)
	, m_maxDistanceFromCenter(100)
	, m_wPos(0, 0, 0)
{

}


LineCascadePC::~LineCascadePC()
{

}


void LineCascadePC::Tick(Uint32 diff)
{
	WindowTitleManager::Inst()->AddToWindowTitle(std::to_string(m_primitivecount));
}


void LineCascadePC::Render()
{
	DrawLines();
}


void LineCascadePC::DrawLines()
{
	SDL_SetRenderDrawColor(REN, 255, 255, 255, 0);

	IH()->Lock();

	for (int i = 0; i < m_wpStart.size(); ++i) 
	{
		SDL_RenderDrawLine(REN, W2Sx(m_wpStart[i].x), W2Sy(m_wpStart[i].y), W2Sx(m_wpEnd[i].x), W2Sy(m_wpEnd[i].y));
	}

	IH()->Unlock();
}


void LineCascadePC::ClearLines()
{
	IH()->Lock();

	m_wpStart.clear();
	m_wpEnd.clear();

	m_primitivecount = 0;

	IH()->Unlock();
}


void LineCascadePC::AddLine()
{
	IH()->Lock();

	glm::dvec3& center = IH()->m_lastMouseWPos;

	float angle = Random(0, M_PI);
	float r = Random(0, m_maxLineLength);

	glm::dvec3 wp1, wp2;
	FindPointsOnDistFromPointOnLine(angle, center, r, wp1, wp2);

	m_wpStart.push_back(wp1);
	m_wpEnd.push_back(wp2);

	m_primitivecount++;

	IH()->Unlock();
}


void LineCascadePC::AddLineOnDistFromCenter()
{
	IH()->Lock();

	glm::dvec3 center = IH()->m_lastMouseWPos;

	float angle = Random(0, M_PI);
	float lineLen = Random(0, m_maxLineLength);
	float distFromC = Random(0, m_maxDistanceFromCenter);

	float bngle = angle - M_PI / 2;

	glm::dvec3 pc1, pc2;
	if (round(Random(0, 10)) < 7)
	{
		FindPointsOnDistFromPointOnLine(bngle, center, distFromC, pc1, pc2);
	}
	else
	{
		pc1 = pc2 = center;
	}

	glm::dvec3 p1, p2;
	if (round(Random(0, 1)))
	{
		FindPointsOnDistFromPointOnLine(angle, pc1, lineLen, p1, p2);
	}
	else
	{
		FindPointsOnDistFromPointOnLine(angle, pc2, lineLen, p1, p2);
	}

	m_wpStart.push_back(p1);
	m_wpEnd.push_back(p2);

	m_primitivecount++;

	IH()->Unlock();
}


#endif