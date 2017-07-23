#pragma once
#include "Engine/Controlling/AIController.h"


class PingPongMonsterAI : public AIController
{
public:
	PingPongMonsterAI(const std::string& name);
	virtual ~PingPongMonsterAI();

	void SetMoveSpeed(double speed);

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
};

