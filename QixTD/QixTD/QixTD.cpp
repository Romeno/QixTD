#include "stdafx.h"
#include "QixTD.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Config/AppConfig.h"
#include "Mechanics/Qix/Config/MapConfigStub.h"
#include "Mechanics/Qix/QixAPI.h"
#include "Engine/Components/Physics/Box2DPhysicsComponent.h"
#include "Engine/Utils/SystemInfo.h"


static int s_res = 0;

static b2Vec2 PHYSICS_GRAVITY = { 0.0f, -1.0f };


QixTD::QixTD()
	: super()

	, m_qixMech( nullptr )
	//, m_tdMech( nullptr )

	, m_input( nullptr )
	, m_camera( nullptr )

	, m_mapConfigs()
	, m_mapNumber( -1 )
	, m_currentMap( nullptr )
{

}


QixTD::~QixTD()
{
	delete Box2DPhysicsComponent::s_world;

	std::for_each( m_mapConfigs.begin(), m_mapConfigs.end(), []( auto config ) { SafeDelete( config ); } );
	m_mapConfigs.clear();
	m_currentMap = nullptr;

	delete m_input;

	delete m_camera;

	delete m_qixMech;
}


int QixTD::Init()
{
	m_qixMech = new Qix();

	m_camera = new QixCamera();

	m_input = new QixIH();

	__ic__( m_qixMech->Init() );

	api->Init( m_qixMech );

	__ic__( super::Init() );

	//m_borderController = new LineCascade("borders");

	ConfigError configRes = CONFIG_ERROR_OK;

	for ( int i = 0; i < CFG->m_numMaps; i++ ) {
		MapConfigStub* map = new MapConfigStub( std::to_string( i ) );
		configRes = map->Read();
		if ( configRes != CONFIG_ERROR_OK )
		{
			return 1;
		}

		m_mapConfigs.push_back( map );
	}

	InitPhysics();

	return LoadLevel( 0 );
}


int QixTD::InitPhysics()
{
	Box2DPhysicsComponent::s_world = new b2World( PHYSICS_GRAVITY );

	return 0;
}


void QixTD::Tick( Uint32 diff )
{
	m_qixMech->Tick( diff );

	super::Tick( diff );

	//ListenKeyboardH( WIN );
}


void QixTD::Render()
{
	m_qixMech->Render();

	super::Render();
}


int QixTD::LoadLevel( int num )
{
	int res;

	m_mapNumber = num;
	m_currentMap = m_mapConfigs[num];

	Entity* e = nullptr;

	e = api->CreateSprite( "Gluka.png", m_currentMap->m_playerStartPos, glm::dvec3( 100.0, 100.0, 0 ), DIR_LEFT );
	e->m_name = "hero";
	api->Play( e );

	m_camera->SetWPos( m_currentMap->m_playerStartPos );

	e = api->CreateColoredRect( glm::ivec4( 128, 128, 128, 0 ),
		glm::dvec3( 0, 0, -200 ),
		glm::dvec3( m_currentMap->m_mapDimensions.x, m_currentMap->m_mapDimensions.y, 0 ) );
	e->m_name = "map bg";

	e = api->CreateColoredRect( glm::ivec4( 196, 196, 196, 0 ),
		glm::dvec3( 0, 0, -100 ),
		glm::dvec3( 100, 100, 0 ) );
	e->m_name = "bg at center";

	e = api->CreateButton( glm::dvec3( 100, 100, 100 ),
		glm::dvec3( 100, 100, 0 ),
		"Push me" );
	e->m_name = "button";

	e = api->CreateColoredRect( glm::ivec4( 255, 255, 255, 0 ),
		glm::dvec3( 150, 0, 0 ),
		glm::dvec3( 30, 30, 0 ) );
	api->TickPingPongMonster( e );
	e->m_real->SetVelocity( 1 );

	return 0;
}


Entity* QixTD::GetHero()
{
	return m_qixMech->m_hero;
}


InputHandler* QixTD::Input()
{
	return m_input;
}


Camera* QixTD::Camera_()
{
	return m_camera;
}






