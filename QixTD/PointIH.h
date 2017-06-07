#pragma once
#include "Defines.h"

#ifdef POINT_SPLASH_GAME_TYPE

#include "Singleton.h"
#include "InputHandler.h"


class PointIH : public InputHandler
{
public:
	PointIH();
	virtual ~PointIH();

	virtual int Init();
	virtual void Tick(Uint32 diff);
	virtual void Clear();

	void Lock();
	void Unlock();

	virtual void HandleKeyUp(SDL_KeyboardEvent* e);
	virtual void HandleKeyDown(SDL_KeyboardEvent* e);
	virtual void HandleMouseButtonDown(SDL_MouseButtonEvent* e);
	virtual void HandleMouseButtonUp(SDL_MouseButtonEvent* e);
	virtual void HandleMouseMotion(SDL_MouseMotionEvent* e);

	SDL_Point			m_lastMouseSPos;
	glm::dvec3			m_lastMouseWPos;
	SDL_TimerID			m_timerID;
	CRITICAL_SECTION	m_addPointCS;
};


#endif