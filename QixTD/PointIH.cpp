#include "stdafx.h"
#include "Defines.h"

#ifdef POINT_SPLASH_GAME_TYPE

#include "PointIH.h"
#include "PC.h"
#include "GameManager.h"
#include "Utils.h"


Uint32 SDLCALL continiousaddpoint(Uint32 interval, void *param);

int timerInterval = 1;


PointIH::PointIH()
	: m_lastMouseSPos({ 0, 0 })
	, m_lastMouseWPos(0, 0, 0)
	, m_timerID(0)
	, m_addPointCS()
{

}


PointIH::~PointIH()
{
	Clear();
}


int PointIH::Init()
{
	if (!InitializeCriticalSectionAndSpinCount(&m_addPointCS, 0x00000400))
	{
		return 1;
	}

	return 0;
}


void PointIH::Tick(Uint32 diff)
{
	m_lastMouseWPos = S2W(m_lastMouseSPos);
}


void PointIH::Clear()
{
	DeleteCriticalSection(&m_addPointCS);
}


void PointIH::Lock()
{
	EnterCriticalSection(&m_addPointCS);
}


void PointIH::Unlock()
{
	LeaveCriticalSection(&m_addPointCS);
}


void PointIH::HandleKeyUp(SDL_KeyboardEvent* e)
{
	if (e->keysym.scancode == SDL_SCANCODE_ESCAPE) {
		PC()->ClearPoints();
	}
}


void PointIH::HandleKeyDown(SDL_KeyboardEvent* e)
{

}


void PointIH::HandleMouseButtonDown(SDL_MouseButtonEvent* e)
{
	Lock();

	m_lastMouseSPos = { e->x, e->y };
	m_lastMouseWPos = S2W(m_lastMouseSPos);

	Unlock();

	m_timerID = SDL_AddTimer(timerInterval, continiousaddpoint, 0);

	PC()->AddPoint();
}


void PointIH::HandleMouseButtonUp(SDL_MouseButtonEvent* e)
{
	SDL_RemoveTimer(m_timerID);
}


void PointIH::HandleMouseMotion(SDL_MouseMotionEvent* e)
{
	Lock();

	m_lastMouseSPos = { e->x, e->y };
	m_lastMouseWPos = S2W(m_lastMouseSPos);

	Unlock();
}


Uint32 SDLCALL continiousaddpoint(Uint32 interval, void *param)
{
	PC()->AddPoint();

	return timerInterval;
}

#endif