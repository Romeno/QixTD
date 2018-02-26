#pragma once
#include "Engine/Components/Controllable.h"


class AI : public Controllable
{
public:
	typedef Controllable super;

	AI();
	virtual ~AI();

	virtual int Init();
	virtual void Tick(Uint32 diff);
};

