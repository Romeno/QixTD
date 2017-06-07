#include "stdafx.h"
#include "Defines.h"

#ifdef PLATFORMER_GAME_TYPE

#include "PlatformerIH.h"
#include "PC.h"
#include "GameManager.h"
#include "Utils.h"


PlatformerIH::PlatformerIH()
{

}


PlatformerIH::~PlatformerIH()
{

}


int PlatformerIH::Init()
{
	return 0;
}


void PlatformerIH::Tick(Uint32 diff)
{
	//int numKeys = 0;
	//const Uint8* keys = SDL_GetKeyboardState(&numKeys);
	//if (keys[SDL_SCANCODE_RETURN]) 
	//{
	//	printf("<RETURN> is pressed.\n");
	//}
}


void PlatformerIH::Clear()
{

}


void PlatformerIH::HandleKeyUp(SDL_KeyboardEvent* e)
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
	else if (e->keysym.scancode == SDL_SCANCODE_SPACE)
	{
		PC()->RequestJump();
	}
}


void PlatformerIH::HandleKeyDown(SDL_KeyboardEvent* e) 
{
	if (e->keysym.scancode == SDL_SCANCODE_LEFT)
	{
		PC()->RequestStartMoveLeft();
	}
	else if (e->keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		PC()->RequestStartMoveRight();
	}
	else if (e->keysym.scancode == SDL_SCANCODE_UP)
	{
		PC()->RequestStartMoveUp();
	}
	else if (e->keysym.scancode == SDL_SCANCODE_DOWN)
	{
		PC()->RequestStartMoveDown();
	}
	else if (e->keysym.scancode == SDL_SCANCODE_SPACE)
	{
		PC()->RequestJump();
	}

}

#endif