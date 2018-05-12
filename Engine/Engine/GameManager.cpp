#include "stdafx.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Utils/SystemInfo.h"
#include "Engine/Utils/Logger/Logger.h"
#include "Engine/Utils/Logger/Sink.h"
#include "Engine/Utils/WindowTitleManager.h"
#include "Engine/Config/AppConfig.h"
#include "Engine/Config/MapConfig.h"
#include "Engine/GameManager.h"
#include "Engine/CoordinateSystem.h"
#include "Engine/Game.h"
#include "Engine/InputHandler.h"
#include "Engine/Input/Mouse.h"
#include "Engine/Input/Keyboard.h"
#include "Math/Math.h"
#include "Engine/API.h"
#include "Mechanics/Qix/LineCascade.h"
#include "Engine/Components/Physics/SimplePhysicsComponent.h"
#include "Engine/Components/UI/FocusManager.h"
#include "Engine/Cache/FontCache.h"
#include "Engine/Cache/TextureCache.h"


extern GameManager* gameManager = nullptr;


GameManager::GameManager()
	: m_game(nullptr)

	, vpHeight(720)
	, vpWidth(960)

	, win(nullptr)
	, ren(nullptr)

	, winX(0)
	, winY(0)

	, m_fps(0)

	, m_cfg(nullptr)
{

}


GameManager::~GameManager()
{
	RemoveSDLObj(win, ren);
	win = nullptr;
	ren = nullptr;

	del(m_cfg);

	SDL_StopTextInput();

	SDL_Quit();
}


int GameManager::Init(Game* game)
{
	int ret;
	ret = InitLogger();
	if (ret != 0)
	{
		std::cout << "InitLogger failed" << std::endl;
		_getch();
		return ret;
	}

	ret = InitSDL();
	if (ret != 0) 
	{
		ELOGB(ERR_TYPE_ENGINE_ERROR, "InitSDL failed");
		SDL_StopTextInput();
		SDL_Quit();
		_getch();
		return ret;
	}

	ret = InitEngine();
	if (ret != 0)
	{
		ELOGB(ERR_TYPE_ENGINE_ERROR, "InitEngine failed");
		RemoveSDLObj(win, ren);
		SDL_StopTextInput();
		SDL_Quit();
		_getch();
		return ret;
	}

	LogInfo(win, ren);

	m_game = game;
	m_game->Init();

	return 0;
}


int GameManager::InitLogger()
{
	int ret = 0;

	loggerManager = new LoggerManager();

	BaicalSink* baicalSink = new BaicalSink();
	ConsoleSink* consoleSink = new ConsoleSink();

	loggerManager->AddSink("BAICAL", baicalSink );
	loggerManager->AddSink("CONSOLE", consoleSink );
	loggerManager->AddSink("ALL", baicalSink );
	loggerManager->AddSink("ALL", consoleSink );

	ret = loggerManager->Init();

	loggerManager->AddModule( MODULE_MOUSE );
	loggerManager->AddModule( MODULE_KEYBOARD );
	loggerManager->AddModule( MODULE_GENERIC_INFO );
	loggerManager->AddModule( MODULE_WINDOW_EVENTS );
	loggerManager->AddModule( MODULE_TEXT );
	loggerManager->AddModule( MODULE_RENDER );

	return ret;
}


int GameManager::InitSDL() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) 
	{
		ELOGB(ERR_TYPE_SDL_ERROR, "SDL_Init error: %s", SDL_GetError());
		return 1;
	}

	if (TTF_Init())
	{
		ELOGB(ERR_TYPE_SDL_ERROR, "TTF_Init error: %s", SDL_GetError());
		return 1;
	}

	win = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, vpWidth, vpHeight, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		ELOGB(ERR_TYPE_SDL_ERROR, "SDL_CreateWindow error: %s", SDL_GetError());
		return 1;
	}

	int numRenderDriver = GetNumOpenGLDriver();
	if (numRenderDriver == -1)
	{
		ELOGB(ERR_TYPE_ENGINE_ERROR, "OpenGL driver not found");
	}

	ren = SDL_CreateRenderer(win, numRenderDriver, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) 
	{
		ELOGB(ERR_TYPE_SDL_ERROR, "SDL_CreateRenderer error: %s", SDL_GetError());
		RemoveSDLObj(win);
		return 1;
	}

	SDL_StartTextInput();

	return 0;
}


int GameManager::GetNumOpenGLDriver() 
{
	SDL_RendererInfo info;
	int numRenderDrivers = SDL_GetNumRenderDrivers();
	for (int i = 0; i < numRenderDrivers; i++)
	{
		SDL_GetRenderDriverInfo(i, &info);
		if (!strcmp(info.name, "opengl")) {
			return i;
		}
	}

	return -1;
}


void GameManager::CenterWindow()
{
	SDL_DisplayMode mode;
	int display = SDL_GetWindowDisplayIndex(win);
	SDL_GetDesktopDisplayMode(display, &mode);

	winX = (mode.w - vpWidth) / 2;
	winY = (mode.h - vpHeight) / 2;

	SDL_SetWindowPosition(win, winX, winY);
}


int GameManager::InitEngine()
{
	m_cfg = new AppConfig();
	ConfigError cfgRet = m_cfg->Read();
	if (cfgRet != CONFIG_ERROR_OK) 
	{
		return 1;
	}

	keyboard = new Keyboard();
	keyboard->Init();

	mouse = new Mouse();
	mouse->Init();

	windowTitleManager = new WindowTitleManager();
	windowTitleManager->Init(m_cfg->m_windowTitle);

	focusManager = new FocusManager();

	fontCache = new FontCache();

	textureCache = new TextureCache();

	//SDL_Cursor* c = SDL_CreateSystemCursor( SDL_SYSTEM_CURSOR_WAIT );

	Mouse::Cursor::Load( "i:\\Wc3Icon1.png", 6, 4, 0 );

	//SDL_Surface *img = IMG_Load("i:\\Wc3Icon1.png");
	//SDL_Cursor* c = SDL_CreateColorCursor( img, 6, 4 );

	//SDL_SetCursor( c );

	return 0;
}


void GameManager::MainLoop()
{
	static Uint32 lastTicks = SDL_GetTicks();

	SDL_Event e;
	bool wasEvent = false;
	int i = 0;
	int tiEventCount = 0 ;

	while (!m_game->m_quit) {
		wasEvent = false;
		i = 0;
		tiEventCount = 0;

		Uint32 newTicks = SDL_GetTicks();

		PreTick( newTicks - lastTicks );

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
			{
				m_game->Quit();

				wasEvent = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				m_game->Input()->HandleKeyDown(&e.key);

				wasEvent = true;
			}
			else if (e.type == SDL_KEYUP)
			{
				m_game->Input()->HandleKeyUp(&e.key);

				wasEvent = true;
			}
			else if (e.type == SDL_KEYMAPCHANGED)
			{
				m_game->Input()->HandleKeymapChanged( &e.key );

				wasEvent = true;
			}
			else if (e.type == SDL_TEXTEDITING) //CJK
			{
				m_game->Input()->HandleTextEditing( &e.edit );

				wasEvent = true;
			}
			else if (e.type == SDL_TEXTINPUT)
			{
				m_game->Input()->HandleTextInput( &e.text );

				tiEventCount++;

				wasEvent = true;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				m_game->Input()->HandleMouseButtonDown(&e.button);

				wasEvent = true;
			}
			else if (e.type == SDL_MOUSEBUTTONUP)
			{
				m_game->Input()->HandleMouseButtonUp(&e.button);

				wasEvent = true;
			}
			else if (e.type == SDL_MOUSEWHEEL)
			{
				m_game->Input()->HandleMouseWheel( &e.wheel );

				wasEvent = true;
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				i++;
				m_game->Input()->HandleMouseMotion(&e.motion);

				wasEvent = true;
			}
			else if ( e.type == SDL_WINDOWEVENT )
			{
				LogWindowEvent( &e, LOGGER_BAICAL, MODULE_WINDOW_EVENTS );

				wasEvent = true;
			}
			else
			{
				LogGenericEvent( &e, LOGGER_BAICAL, MODULE_WINDOW_EVENTS );

				wasEvent = true;
			}
		}

		if ( wasEvent ) 
		{
			if ( i >= 2 )
			{
				LOG( "TWICE" );
			}
			ILOGB( "Event handling finished" );

			if( tiEventCount >= 2 )
			{
				ILOGB( "LETTERS in TICK %d", tiEventCount );
			}
		}
		//std::cout << "Event handling finished" << std::endl;

		Tick(newTicks - lastTicks);

		//while ( SDL_GetTicks() - lastTicks < 1000 * 3)
		//{
		//	
		//}

		RenderScene(newTicks - lastTicks);

		PostTick( newTicks - lastTicks );

		lastTicks = newTicks;
	}

	Clean();
}



static glm::dvec3 lastPos;
static glm::dvec3 curPos;
Entity* cascade;

bool InitMousePos()
{
	int x, y;
	SDL_GetMouseState( &x, &y );

	lastPos = glm::dvec3( S2Wx( x ), S2Wy( y ), 50 );

	cascade = api->CreateEntity();

	LineCascade* d = new LineCascade();
	cascade->AddComponent( d );

	SimplePhysicsComponent* real = new SimplePhysicsComponent();
	real->SetPos(curPos);
	cascade->AddComponent( real );

	return true;
}


void GameManager::PreTick( Uint32 diff )
{
	mouse->PreTick( diff );
	keyboard->PreTick( diff );

	m_game->PreTick( diff );
}


bool a = false;

void GameManager::Tick(Uint32 diff) 
{
	static bool inited = InitMousePos();

	mouse->Tick( diff );

	keyboard->Tick( diff );

	windowTitleManager->Tick( diff );

	Uint32 t = SDL_GetTicks();

	//int x, y;
	//SDL_GetMouseState( &x, &y );
	//curPos = glm::dvec3( S2Wx( x ), S2Wy( y ), 50 );
	//LineCascade* lc = (LineCascade*) (cascade->m_malui);
	//lc->AddLine( lastPos, curPos );
	//lastPos = curPos;

	//if ( t > 1000 * 5 && !a)
	//{
	//	MOUSE_SET_POS( glm::dvec3( Random( -VP_WIDTH / 2, +VP_WIDTH / 2 ), Random(-VP_HEIGHT / 2, + VP_HEIGHT / 2), 0 ) );
	//	a = true;
	//}

	m_game->Tick(diff);

	te += keyboard->m_text;
}


void GameManager::PostTick( Uint32 diff )
{
	keyboard->PostTick( diff );
	mouse->PostTick( diff );
}


void GameManager::RenderScene(Uint32 diff)
{
    //Render the scene
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
    SDL_RenderClear(ren);

    OutputFPS();

	m_game->Render();

	//API::Inst()->DrawTextBlock( R2W(glm::dvec3( 0, 0, 400 )), glm::dvec3( 300, 100, 0 ), "fonts/Snap.ttf", std::to_string(Keyboard::Inst()->IsKeyDown(SDL_SCANCODE_RETURN)), 24 );
	api->DrawTextBlock( R2W( glm::dvec3( -VP_WIDTH / 2, VP_HEIGHT / 2, 400 ) ), { TextComponent::XALIGN_LEFT, TextComponent::YALIGN_TOP }, "fonts/Snap.ttf", te, 24 );


	//SDL_SetRenderDrawColor( ren, 1, 1, 1, 0 );
	//SDL_RenderDrawLine( REN, W2Sx( curPos.x ), W2Sy( curPos.y ), W2Sx( lastPos.x ), W2Sy( lastPos.y ) );
	//lastPos = curPos;

	//cascade->Re

	SDL_RenderPresent(ren);
}


void GameManager::OutputFPS() {
	static int frameCount = 0;
	static std::chrono::high_resolution_clock::time_point lastTimePoint = std::chrono::high_resolution_clock::now();
	static std::chrono::high_resolution_clock::time_point nowTimePoint;

	++frameCount;
	nowTimePoint = std::chrono::high_resolution_clock::now();
	long long diff = nowTimePoint.time_since_epoch().count() - lastTimePoint.time_since_epoch().count();
	if (diff > 1000000000) // every 1 second (10000000000 in nanoseconds)
	{
		m_fps = (float)frameCount / ((float)diff / (float)1000000000);
		lastTimePoint = lastTimePoint + std::chrono::seconds(1);
		frameCount = 0;

		std::string title = ". Draw FPS: ";
		title += std::to_string(m_fps);

		windowTitleManager->AddToWindowTitle(title);
	}
}


void GameManager::Clean()
{
	TTF_Quit();
}



/*
 *
 * Romeno's code
 * To be Romeno Company
 * Project: Learning game development
 *
 */