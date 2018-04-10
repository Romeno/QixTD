#include "stdafx.h"
#include "QixTDAPI.h"
#include "Engine/Utils/Utils.h"
#include "Mechanics/Qix/Components/Controlling/TickPingPongAI.h"
#include "Mechanics/Qix/Qix.h"
#include "QixTD/Components/Controlling/QixTDPC.h"


//DEFINE_SINGLETON( QixTDAPI )


QixTDAPI::QixTDAPI()
	: super()
{

}


QixTDAPI::~QixTDAPI()
{

}


//void QixTDAPI::Init( Qix* mech )
//{
//	qixMech = mech;
//}


void QixTDAPI::Play(Entity* e)
{
	if ( !qixMech )
	{
		ERR( ERR_TYPE_MECHANICS_ERROR, "Set Qix Mechacnics object first" );
		return;
	}

	QixTDPC* pc = new QixTDPC();

	e->AddComponent(pc);

	pc->Init();

	qixMech->SetHero( e );
}

//
//TickPingPongAI* QixTDAPI::TickPingPongMonster( Entity* e )
//{
//	if ( !qixMech )
//	{
//		ERR( ERR_TYPE_MECHANICS_ERROR, "Set Qix Mechacnics object first" );
//		return nullptr;
//	}
//
//	TickPingPongAI* ai = new TickPingPongAI();
//
//	e->AddComponent( ai );
//
//	ai->Init();
//
//	qixMech->m_monsters.push_back( e );
//
//	return ai;
//}



