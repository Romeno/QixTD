#pragma once

#include "Mechanics/Qix/Components/Controlling/PingPongAI.h"


class TickPingPongAI : public PingPongAI
{
public:
	typedef PingPongAI super;

	TickPingPongAI();
	virtual ~TickPingPongAI();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;

	virtual void SetPeriod(int period);

	Uint32		m_lastChangeDirTs;
	Uint32		m_changeDirPeriod;
};





