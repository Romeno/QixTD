#include "stdafx.h"
#include "QixTDAPI.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Components/Drawing/Sprite.h"
#include "Mechanics/Qix/Components/Controlling/TickPingPongAI.h"
#include "Mechanics/Qix/Qix.h"
#include "QixTD/Components/Controlling/QixTDPC.h"
#include "QixTD/Components/Physics/QixPhysComponent.h"


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
		ELOGB( ERR_TYPE_MECHANICS_ERROR, "Set Qix Mechacnics object first" );
		return;
	}

	QixTDPC* pc = new QixTDPC();

	e->AddComponent(pc);

	pc->Init();

	qixMech->SetHero( e );
}


Entity* QixTDAPI::CreateSprite( const std::string& path, glm::dvec3 wpos, glm::dvec3 size, Direction dir )
{
	Entity* e = CreateEntity();

	Sprite* malui = new Sprite();
	malui->SetImage( path );
	e->AddComponent( malui );
	malui->m_originalData->m_visualSize = size;

	QixPhysComponent* real = new QixPhysComponent();
	real->SetSize( size );
	real->SetPos( wpos );
	real->SetDir( dir );
	e->AddComponent( real );

	e->Init();

	return e;
}

//
//TickPingPongAI* QixTDAPI::TickPingPongMonster( Entity* e )
//{
//	if ( !qixMech )
//	{
//		ELOGB( ERR_TYPE_MECHANICS_ERROR, "Set Qix Mechacnics object first" );
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



