#include "stdafx.h"
#include "TickPingPongAI.h"
#include "Engine/GameManager.h"
#include "Engine/Utils/Utils.h"
#include "Math/Math.h"


TickPingPongAI::TickPingPongAI()
	: super()

	, m_lastChangeDirTs(0)
	, m_changeDirPeriod(3000)
{

}


TickPingPongAI::~TickPingPongAI()
{

}


int TickPingPongAI::Init()
{
	m_lastChangeDirTs = SDL_GetTicks();

	return PingPongAI::Init();
}


void TickPingPongAI::Tick(Uint32 diff)
{
	Uint32 now = SDL_GetTicks();
	if (now - m_lastChangeDirTs > m_changeDirPeriod)
	{
		m_lastChangeDirTs = now;
		m_object->m_real->SetDirection(GetRandomDirection());
	}

	PingPongAI::Tick(diff);
}


void TickPingPongAI::SetPeriod(int period)
{
	m_changeDirPeriod = period;
}


template <>
void Entity::AddComponent( TickPingPongAI* component )
{
	m_rozum = component;
	component->m_object = this;
}
