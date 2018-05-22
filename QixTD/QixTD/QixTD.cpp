#include "stdafx.h"
#include "QixTD.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Config/AppConfig.h"
#include "Mechanics/Qix/Config/MapConfigStub.h"
#include "Engine/Components/Physics/Box2DPhysicsComponent.h"
#include "Engine/Components/Physics/SimplePhysicsComponent.h"
#include "Engine/Utils/SystemInfo.h"
#include "Engine/Input/Mouse.h"
#include "Engine/Input/Keyboard.h"
#include "QixTD/QixTDAPI.h"
#include "QixTD/Components/Drawable/LineDrawable.h"
#include "Engine/Components/UI/UIButton.h"
#include "Engine/Components/Drawing/Sprite.h"
#include "Engine/Components/UI/Sensors/MouseInputSensor.h"
#include "Engine/Components/TextComponent.h"


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
	api = new QixTDAPI();

	m_qixMech = new Qix();

	__ic__( m_qixMech->Init() );

	API->Init( m_qixMech );

	m_camera = new QixCamera();

	m_input = new QixTDIH();

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
		else
		{
			ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "error reading config" );
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
	if ( keyboard->IsKeyDown( SDL_SCANCODE_ESCAPE ) )
	{
		Quit();
	}

	super::Tick( diff );

	m_qixMech->Tick( diff );

	Entity* hero = m_qixMech->m_hero;
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

	SetWorldScale( m_currentMap->m_worldScale );

	Entity* e = nullptr;

	e = API->CreateHero( "Gluka.png", m_currentMap->m_playerStartPos, glm::dvec3( 300.0, 300.0, 0 ), DIR_LEFT );
	e->m_name = "hero";
	API->Play( e );

	
	m_camera->SetWPos( m_currentMap->m_playerStartPos );


	e = API->CreateColoredRect( glm::ivec4( 64, 64, 64, 0 ),
		glm::dvec3( 0, 0, -200 ),
		glm::dvec3( m_currentMap->m_mapDimensions.x, m_currentMap->m_mapDimensions.y, 0 ) );
	e->m_name = "map dimensions";

	double playableAreaWidth = m_currentMap->m_mapDimensions.x - 300;
	double playableAreaHeight = m_currentMap->m_mapDimensions.y - 300;

	e = API->CreateColoredRect( glm::ivec4( 128, 128, 128, 0 ),
		glm::dvec3( 0, 0, -200 ),
		glm::dvec3( playableAreaWidth, playableAreaHeight, 0 ) );
	e->m_name = "playable map area";

	m_borders.clear();
	m_borders.push_back( { { -playableAreaWidth / 2, playableAreaHeight / 2, 0 },{ playableAreaWidth / 2, playableAreaHeight / 2, 0 }, false, 1 } );
	m_borders.push_back( { { playableAreaWidth / 2, playableAreaHeight / 2, 0 },{ playableAreaWidth / 2, -playableAreaHeight / 2, 0 }, false, 1 } );
	m_borders.push_back( { { playableAreaWidth / 2, -playableAreaHeight / 2, 0 },{ -playableAreaWidth / 2, -playableAreaHeight / 2, 0 }, false, 1 } );
	m_borders.push_back( { { -playableAreaWidth / 2, -playableAreaHeight / 2, 0 },{ -playableAreaWidth / 2, playableAreaHeight / 2, 0 }, false, 1 } );

	e = API->CreateColoredRect( glm::ivec4( 196, 196, 196, 0 ),
		glm::dvec3( 0, 0, -100 ),
		glm::dvec3( 300, 300, 0 ) );
	e->m_name = "bg at center";

	//e = API->CreateButton( glm::dvec3( 100, 100, 100 ),
	//	glm::dvec3( 100, 100, 0 ),
	//	"Push me" );
	//e->m_name = "button";

	e = API->CreateEntity();

	SimplePhysicsComponent* real = new SimplePhysicsComponent();
	real->SetAbsolutePosition( true );
	real->SetSize( glm::dvec3( 300, 300, 0 ) );
	real->SetPos( glm::dvec3( 750, 750, 0 ) );
	e->AddComponent( real );

	UIButton* button = new UIButton();
	button->SetSensor( new MouseInputSensor( button ) );
	//button->SetText(text);
	e->AddComponent( button );

	Sprite* sStandard = new Sprite();
	sStandard->SetImage( "UI/Button.png" );
	sStandard->m_originalData->m_visualSize = glm::dvec3( 300, 300, 0 );
	e->AddComponent( sStandard );

	Sprite* sHover = new Sprite();
	sHover->SetImage( "UI/ButtonHovered.png" );
	sHover->m_originalData->m_visualSize = glm::dvec3( 300, 300, 0 );
	sHover->Init();

	Sprite* sClick = new Sprite();
	sClick->SetImage( "UI/ButtonPressed.png" );
	sClick->m_originalData->m_visualSize = glm::dvec3( 300, 300, 0 );
	sClick->Init();

	((UIButton*) e->m_ui)->SetStandardDrawable( sStandard );
	((UIButton*) e->m_ui)->SetHoveredDrawable( sHover );
	((UIButton*) e->m_ui)->SetClickedDrawable( sClick );

	TextComponent* text = new TextComponent();
	text->SetPositioning( TextComponent::POS_CENTER );
	text->SetOverflow( TextComponent::OVERFLOW_HIDDEN );
	text->m_text = "Push Me!";
	e->AddComponent(text);

	e->Init();


	e = API->CreateColoredRect( glm::ivec4( 255, 255, 255, 0 ),
		glm::dvec3( 150, 0, 0 ),
		glm::dvec3( 90, 90, 0 ) );
	API->TickPingPongMonster( e );
	e->m_real->SetVelocity( 3 );

	e = API->CreateEntity();
	SimplePhysicsComponent* p = new SimplePhysicsComponent();
	p->m_pos = { 0, 0, 150 };
	e->AddComponent( p );
	LineDrawable* d = new LineDrawable();
	e->AddComponent( d );

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






