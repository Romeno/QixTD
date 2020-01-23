#include "stdafx.h"
#include "Heroes.h"
#include "Engine/Input/Keyboard.h"
#include "Engine/InputHandler.h"

#include "Engine/Config/Backends/JsonConfigBackend.h"

#include "Engine/Components/Physics/SimplePhysicsComponent.h"
#include "Engine/Components/UI/UIButton.h"
#include "Engine/Components/UI/Sensors/MouseInputSensor.h"
#include "Engine/Components/TextComponent.h"
#include "Engine/Components/Drawing/Sprite.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Config/AppConfig.h"

#include "Heroes/HeroesCamera.h"
#include "Heroes/HeroesAPI.h"


static int s_res = 0;


Heroes::Heroes()
	: super()

	, m_input( nullptr )
	, m_camera( nullptr )

	//, m_mapConfigs()
	//, m_mapNumber( -1 )
	//, m_currentMap( nullptr )
{

}


Heroes::~Heroes()
{

}


int Heroes::Init()
{
	api = new HeroesAPI();

	//m_qixMech = new Qix();

	//__ic__( m_qixMech->Init() );

	//API->Init( m_qixMech );

	m_camera = new HeroesCamera();

	m_input = new InputHandler();

	__ic__( super::Init() );

	//m_borderController = new LineCascade("borders");

	JsonConfigBackend be( "" );

	//ConfigError configRes = CONFIG_ERROR_OK;

	//for ( int i = 0; i < CFG->m_numMaps; i++ )
	//{
	//	configRes = CONFIG_ERROR_OK;

	//	MapConfigStub* map = new MapConfigStub( std::to_string( i ) );
	//	configRes = map->Read();
	//	if ( configRes != CONFIG_ERROR_OK )
	//	{
	//		ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "error reading config" );
	//		return 1;
	//	}

	//	m_mapConfigs.push_back( map );
	//}

	//m_playerConfig = new PlayerConfig();
	//configRes = m_playerConfig->Read();
	//if ( configRes != CONFIG_ERROR_OK )
	//{
	//	ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "error reading config" );
	//	return 1;
	//}

	//InitPhysics();

	return LoadLevel( 0 );

	return 0;
}


void Heroes::PreTick( Uint32 diff )
{
	
}


void Heroes::Tick( Uint32 diff )
{
	if ( keyboard->IsKeyDown( SDL_SCANCODE_ESCAPE ) )
	{
		Quit();
	}

	super::Tick( diff );

	//m_qixMech->Tick( diff );

	//Entity* hero = m_qixMech->m_hero;
}


void Heroes::PostTick( Uint32 diff )
{
	
}


void Heroes::Render()
{
	super::Render();
}


InputHandler* Heroes::Input()
{
	return m_input;
}


Camera* Heroes::Camera_()
{
	return m_camera;
}


int Heroes::LoadLevel( int num )
{
	int res;

	//m_mapNumber = num;
	//m_currentMap = m_mapConfigs[num];

	//SetWorldScale( m_currentMap->m_worldScale );
	SetWorldScale( 3 );

	Entity* e = nullptr;

	//e = API->CreateHero( "Gluka.png", m_currentMap->m_playerStartPos, glm::dvec3( 300.0, 300.0, 0 ), DIR_LEFT );
	//e->m_name = "hero";
	//API->Play( e );

	LoadArena();


	//m_camera->SetWPos( m_currentMap->m_cameraStartPos );
	m_camera->SetWPos( { 0, 0, 0} );


	//e = API->CreateColoredRect( glm::ivec4( 64, 64, 64, 0 ),
	//	glm::dvec3( 0, 0, -200 ),
	//	glm::dvec3( m_currentMap->m_mapDimensions.x, m_currentMap->m_mapDimensions.y, 0 ) );
	double mapDimensionsX = 1920;
	double mapDimensionsY = 1440;
	e = API->CreateColoredRect( glm::ivec4( 64, 64, 64, 0 ),
		glm::dvec3( 0, 0, -200 ),
		glm::dvec3( 1920, 1440, 0 ) );
	e->m_name = "map dimensions";

	double playableAreaWidth = mapDimensionsX - 300;
	double playableAreaHeight = mapDimensionsY - 300;

	e = API->CreateColoredRect( glm::ivec4( 128, 128, 128, 0 ),
		glm::dvec3( 0, 0, -200 ),
		glm::dvec3( playableAreaWidth, playableAreaHeight, 0 ) );
	e->m_name = "playable map area";

	//m_borders.clear();
	//m_borders.push_back( { { -playableAreaWidth / 2, playableAreaHeight / 2, 0 },{ playableAreaWidth / 2, playableAreaHeight / 2, 0 }, false, 1 } );
	//m_borders.push_back( { { playableAreaWidth / 2, playableAreaHeight / 2, 0 },{ playableAreaWidth / 2, -playableAreaHeight / 2, 0 }, false, 1 } );
	//m_borders.push_back( { { playableAreaWidth / 2, -playableAreaHeight / 2, 0 },{ -playableAreaWidth / 2, -playableAreaHeight / 2, 0 }, false, 1 } );
	//m_borders.push_back( { { -playableAreaWidth / 2, -playableAreaHeight / 2, 0 },{ -playableAreaWidth / 2, playableAreaHeight / 2, 0 }, false, 1 } );

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
	e->AddComponent( text );

	e->Init();

	//e = API->CreateColoredRect( glm::ivec4( 255, 255, 255, 0 ),
	//	glm::dvec3( 150, 0, 0 ),
	//	glm::dvec3( 90, 90, 0 ) );
	//API->TickPingPongMonster( e );
	//e->m_real->SetVelocity( 3 );

	return 0;
}


int Heroes::LoadArena()
{
	ConfigError configRes = CONFIG_ERROR_OK;

	//for ( int i = 0; i < CFG->m_numMaps; i++ )
	//{
	//	configRes = CONFIG_ERROR_OK;

	//	MapConfigStub* map = new MapConfigStub( std::to_string( i ) );
	//	configRes = map->Read();
	//	if ( configRes != CONFIG_ERROR_OK )
	//	{
	//		ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "error reading config" );
	//		return 1;
	//	}

	//	m_mapConfigs.push_back( map );
	//}

	return 0;
}
