#include "stdafx.h"
#include "TickPingPongMonsterAI.h"
#include "Engine/GameManager.h"
#include "Engine/Utils/Utils.h"
#include "Math/Math.h"


TickPingPongMonsterAI::TickPingPongMonsterAI(const std::string& name)
	: PingPongMonsterAI(name)

	, m_lastChangeDirTs(0)
	, m_changeDirPeriod(3000)
{

}


TickPingPongMonsterAI::~TickPingPongMonsterAI()
{

}




int TickPingPongMonsterAI::Init()
{
	m_lastChangeDirTs = SDL_GetTicks();

	return PingPongMonsterAI::Init();
}


void TickPingPongMonsterAI::Tick(Uint32 diff)
{
	Uint32 now = SDL_GetTicks();
	if (now - m_lastChangeDirTs > m_changeDirPeriod)
	{
		m_lastChangeDirTs = now;
		m_drawable->SetDirection(GetRandomDirection());
	}

	PingPongMonsterAI::Tick(diff);
}

