#pragma once
#include "Defines.h"

#ifdef PLATFORMER_GAME_TYPE

#include "Singleton.h"
#include "InputHandler.h"


class PlatformerIH : public InputHandler
{
public:
	PlatformerIH();
	virtual ~PlatformerIH();

	virtual int Init();
	virtual void Tick(Uint32 diff);
	virtual void Clear();

	virtual void HandleKeyUp(SDL_KeyboardEvent* e);
	virtual void HandleKeyDown(SDL_KeyboardEvent* e);
};

#endif