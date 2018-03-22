#include "stdafx.h"
#include "Qix.h"
#include "Engine/Utils/Utils.h"
#include "Mechanics/Qix/QixAPI.h"


static int s_res = 0;


Qix::Qix()
	: super()

	, m_hero(nullptr)
	, m_monsters()
{

}


Qix::~Qix()
{
	//DEL(m_borderController);
}


int Qix::Init()
{
	return super::Init();
}


void Qix::Tick(Uint32 diff)
{
	super::Tick(diff);
}


void Qix::SetHero( Entity* e )
{
	m_hero = e;
}


void Qix::Render()
{
	super::Render();
}