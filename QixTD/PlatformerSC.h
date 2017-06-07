#pragma once
#include "Defines.h"

#ifdef PLATFORMER_GAME_TYPE

#include "ScreenController.h"


class PlatformerSC : public ScreenController
{
public:
	PlatformerSC();
	virtual ~PlatformerSC();

	virtual void Tick(Uint32 diff);
};

#endif