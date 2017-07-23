#include "stdafx.h"
#include "Engine/Controlling/PingPongMonsterAI.h"
#include "Engine/DrawableRect.h"
#include "Math/Math.h"


PingPongMonsterAI::PingPongMonsterAI(const std::string& name)
	: AIController(name)
{

}


PingPongMonsterAI::~PingPongMonsterAI()
{
	
}


void PingPongMonsterAI::SetMoveSpeed(double speed)
{
	m_drawable->SetMoveSpeed(speed);
}


int PingPongMonsterAI::Init()
{
	m_drawable->SetDirection(GetRandomDirection());

	return AIController::Init();
}


void PingPongMonsterAI::Tick(Uint32 diff)
{
	

	AIController::Tick(diff);
}
