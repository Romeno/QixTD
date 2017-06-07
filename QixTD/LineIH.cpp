#include "stdafx.h"
#include "Defines.h"

#ifdef LINE_CASCADE_GAME_TYPE

#include "LineIH.h"
#include "GameManager.h"
#include "Utils.h"
#include "PC.h"


Uint32 timerInterval = 1;
Uint32 SDLCALL continiousaddline(Uint32 interval, void *param);


LineIH::LineIH()
	: m_lastMouseSPos( {0, 0} )
	, m_lastMouseWPos(0, 0, 0)
	, m_timerID(0)
	, m_addPointCS()
{

}


LineIH::~LineIH()
{

}


int LineIH::Init()
{
	if (!InitializeCriticalSectionAndSpinCount(&m_addPointCS, 0x00000400))
	{
		return 1;
	}

	return 0;
}


void LineIH::Tick(Uint32 diff)
{
	m_lastMouseWPos = S2W(m_lastMouseSPos);
}


void LineIH::Clear()
{
	DeleteCriticalSection(&m_addPointCS);
}


void LineIH::Lock()
{
	EnterCriticalSection(&m_addPointCS);
}


void LineIH::Unlock()
{
	LeaveCriticalSection(&m_addPointCS);
}


void LineIH::HandleKeyUp(SDL_KeyboardEvent* e)
{
	if (e->keysym.scancode == SDL_SCANCODE_ESCAPE) {
		PC()->ClearLines();
	}
}


void LineIH::HandleKeyDown(SDL_KeyboardEvent* e)
{

}


void LineIH::HandleMouseButtonDown(SDL_MouseButtonEvent* e)
{
	Lock();

	m_lastMouseSPos = { e->x, e->y };
	m_lastMouseWPos = S2W(m_lastMouseSPos);

	Unlock();

	m_timerID = SDL_AddTimer(timerInterval, continiousaddline, 0);

	PC()->AddLineOnDistFromCenter();
}


void LineIH::HandleMouseButtonUp(SDL_MouseButtonEvent* e)
{
	SDL_RemoveTimer(m_timerID);
}


void LineIH::HandleMouseMotion(SDL_MouseMotionEvent* e)
{
	Lock();

	m_lastMouseSPos = { e->x, e->y };
	m_lastMouseWPos = S2W(m_lastMouseSPos);

	Unlock();
}


Uint32 SDLCALL continiousaddline(Uint32 interval, void *param)
{
	PC()->AddLineOnDistFromCenter();

	return timerInterval;
}


#endif