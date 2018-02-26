#pragma once
#include "Engine/Components/Controllable.h"



class Playable : public Controllable
{
public:
	typedef Controllable super;

	Playable();
	virtual ~Playable();

	virtual int Init();
	virtual void Tick(Uint32 diff);
};

