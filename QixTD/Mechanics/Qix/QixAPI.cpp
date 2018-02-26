#include "stdafx.h"
#include "QixAPI.h"
#include "Engine/Utils/Utils.h"
#include "Mechanics/Qix/Components/Controlling/QixPC.h"
#include "Mechanics/Qix/Components/Controlling/TickPingPongAI.h"
#include "Mechanics/Qix/Qix.h"


DEFINE_SINGLETON(QixAPI)


QixAPI::QixAPI()
	: super()

	, qixMech(nullptr)
{

}


QixAPI::~QixAPI()
{

}


void QixAPI::Init( Qix* mech )
{
	qixMech = mech;
}


void QixAPI::Play(Entity* e)
{
	if ( !qixMech )
	{
		ERR( ERR_TYPE_MECHANICS_ERROR, "Set Qix Mechacnics object first" );
		return;
	}

	QixPC* pc = new QixPC();

	e->AddComponent(pc);

	pc->Init();

	qixMech->SetHero( e );
}


TickPingPongAI* QixAPI::TickPingPongMonster( Entity* e )
{
	if ( !qixMech )
	{
		ERR( ERR_TYPE_MECHANICS_ERROR, "Set Qix Mechacnics object first" );
		return nullptr;
	}

	TickPingPongAI* ai = new TickPingPongAI();

	e->AddComponent( ai );

	ai->Init();

	qixMech->m_monsters.push_back( e );

	return ai;
}



