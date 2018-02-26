#pragma once
#include "Engine/Component.h"


class Controllable : public Component
{
public:
	typedef Component super;

	Controllable();
	virtual ~Controllable();

	virtual int Init();
	virtual void Tick(Uint32 diff);

};

