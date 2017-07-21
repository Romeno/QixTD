#pragma once
#include "AIController.h"


class PingPongMonsterAI : public AIController
{
public:
	PingPongMonsterAI(const std::string& name);
	virtual ~PingPongMonsterAI();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
};
