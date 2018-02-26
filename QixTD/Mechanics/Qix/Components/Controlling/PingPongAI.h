#pragma once
#include "Engine/Components/Controlling/AI.h"


class PingPongAI : public AI
{
public:
	typedef AI super;

	PingPongAI();
	virtual ~PingPongAI();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
};

