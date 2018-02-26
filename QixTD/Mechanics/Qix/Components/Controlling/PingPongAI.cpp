#include "stdafx.h"
#include "PingPongAI.h"
#include "Engine/Entity.h"
#include "Math/Math.h"


PingPongAI::PingPongAI()
	: super()
{

}


PingPongAI::~PingPongAI()
{
	
}


int PingPongAI::Init()
{
	m_object->m_real->SetDirection(GetRandomDirection());

	return AI::Init();
}


void PingPongAI::Tick(Uint32 diff)
{
	AI::Tick(diff);
}


template <>
void Entity::AddComponent( PingPongAI* component )
{
	m_rozum = component;
	component->m_object = this;
}
