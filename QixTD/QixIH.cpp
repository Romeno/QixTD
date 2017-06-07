#include "stdafx.h"
#include "QixIH.h"
#include "PC.h"
#include "GameManager.h"


QixIH::QixIH()
{

}


QixIH::~QixIH()
{

}


int QixIH::Init()
{
	return 0;
}


void QixIH::Tick(Uint32 diff)
{

}


void QixIH::Clear()
{

}


void QixIH::HandleKeyUp(SDL_KeyboardEvent* e)
{
	if (e->keysym.scancode == SDL_SCANCODE_LEFT)
	{
		PC()->RequestStopMoveLeft();
	}
	else if (e->keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		PC()->RequestStopMoveRight();
	}
	else if (e->keysym.scancode == SDL_SCANCODE_UP)
	{
		PC()->RequestStopMoveUp();
	}
	else if (e->keysym.scancode == SDL_SCANCODE_DOWN)
	{
		PC()->RequestStopMoveDown();
	}
}


void QixIH::HandleKeyDown(SDL_KeyboardEvent* e)
{

}


void QixIH::HandleMouseButtonDown(SDL_MouseButtonEvent* e)
{

}


void QixIH::HandleMouseButtonUp(SDL_MouseButtonEvent* e)
{

}


void QixIH::HandleMouseMotion(SDL_MouseMotionEvent* e)
{

}
