#include "stdafx.h"
#include "HeroesAPI.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Components/Drawing/Sprite.h"
//#include "QixTD/Components/Controlling/QixTDPC.h"
//#include "QixTD/Components/Physics/QixHeroPhysComponent.h"
//#include "QixTD/Components/Physics/QixMonsterPhysComponent.h"


//DEFINE_SINGLETON( QixTDAPI )


HeroesAPI::HeroesAPI()
	: super()
{

}


HeroesAPI::~HeroesAPI()
{

}


//void QixTDAPI::Init( Qix* mech )
//{
//	qixMech = mech;
//}


//void HeroesAPI::Play(Entity* e)
//{
//	if ( !qixMech )
//	{
//		ELOGB( ERR_TYPE_MECHANICS_ERROR, "Set Qix Mechacnics object first" );
//		return;
//	}
//
//	QixTDPC* pc = new QixTDPC();
//
//	e->AddComponent(pc);
//
//	pc->Init();
//
//	qixMech->SetHero( e );
//}

//
//Entity* HeroesAPI::CreateMonster( const std::string& path, glm::dvec3 wpos, glm::dvec3 size, Direction dir )
//{
//	Entity* e = CreateEntity();
//
//	Sprite* malui = new Sprite();
//	malui->SetImage( path );
//	e->AddComponent( malui );
//	malui->m_originalData->m_visualSize = size;
//
//	QixMonsterPhysComponent* real = new QixMonsterPhysComponent();
//	real->SetSize( size );
//	real->SetPos( wpos );
//	real->SetDir( dir );
//	e->AddComponent( real );
//
//	e->Init();
//
//	return e;
//}
//
//
//Entity* HeroesAPI::CreateHero( const std::string& path, glm::dvec3 wpos, glm::dvec3 size, Direction dir )
//{
//	Entity* e = CreateEntity();
//
//	Sprite* malui = new Sprite();
//	malui->SetImage( path );
//	e->AddComponent( malui );
//	malui->m_originalData->m_visualSize = size;
//
//	QixHeroPhysComponent* real = new QixHeroPhysComponent();
//	real->SetSize( size );
//	real->SetPos( wpos );
//	real->SetDir( dir );
//	e->AddComponent( real );
//
//	e->Init();
//
//	return e;
//}

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



