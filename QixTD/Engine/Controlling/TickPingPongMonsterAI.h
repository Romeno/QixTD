#pragma once
#ifndef _TICKPINGPONGMONSTERAI__H_

#include "Engine/Controlling/PingPongMonsterAI.h"


class TickPingPongMonsterAI : public PingPongMonsterAI
{
public:
	TickPingPongMonsterAI(const std::string& name);
	virtual ~TickPingPongMonsterAI();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;

	Uint32		m_lastChangeDirTs;
	Uint32		m_changeDirPeriod;
};

/********************************************************************
created:	2017/07/22
created:	22:7:2017   4:27
filename: 	i:\Romeno\Projects\Visual Studio\Qix TD\QixTD\TickPingPongMonsterAI.h
file base:	TickPingPongMonsterAI
author:		Romeno

purpose:
*********************************************************************/
#endif