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


GameManager::GameManager()
	: m_game(nullptr)

	, vpHeight(480)
	, vpWidth(640)

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
		ERR(ERR_TYPE_ENGINE_ERROR, "InitSDL failed");
		SDL_StopTextInput();
		SDL_Quit();
		_getch();
		return ret;
	}

	ret = InitEngine();
	if (ret != 0)
	{
		ERR(ERR_TYPE_ENGINE_ERROR, "InitEngine failed");
		RemoveSDLObj(win, ren);
		SDL_StopTextInput();
		SDL_Quit();
		_getch();
		return ret;
	}

	PrintInfo(win, ren);

	m_game = game;
	m_game->Init();

	return 0;
}


int GameManager::InitLogger()
{
	int ret = 0;

	BaicalSink* sink = new BaicalSink();
	sink->SetTraceName( TM("Game") );

	Logger* logger = new Logger();
	logger->AddSink( sink );
	ret = logger->Init();

	ShareLogger( logger );

	return ret;
}


int GameManager::InitSDL() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) 
	{
		ERR(ERR_TYPE_SDL_ERROR, "SDL_Init error: %s", SDL_GetError());
		return 1;
	}

	if (TTF_Init())
	{
		ERR(ERR_TYPE_SDL_ERROR, "TTF_Init error: %s", SDL_GetError());
		return 1;
	}

	win = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, vpWidth, vpHeight, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		ERR(ERR_TYPE_SDL_ERROR, "SDL_CreateWindow error: %s", SDL_GetError());
		return 1;
	}

	int numRenderDriver = GetNumOpenGLDriver();
	if (numRenderDriver == -1)
	{
		ERR(ERR_TYPE_ENGINE_ERROR, "OpenGL driver not found");
	}

	ren = SDL_CreateRenderer(win, numRenderDriver, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) 
	{
		ERR(ERR_TYPE_SDL_ERROR, "SDL_CreateRenderer error: %s", SDL_GetError());
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

	WindowTitleManager::Inst()->Init(m_cfg->m_windowTitle);

	return 0;
}


void GameManager::MainLoop()
{
	static Uint32 lastTicks = SDL_GetTicks();

	SDL_Event e;
	bool wasEvent = false;
	int i = 0;

	while (!m_game->m_quit) {
		wasEvent = false;
		i = 0;

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
			{
				INFO( "Quit" );
				m_game->Quit();
				wasEvent = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				INFO( "SDL_KEYDOWN" );

				m_game->Input()->HandleKeyDown(&e.key);

				//PrintKeyboardEvent(&e);
				wasEvent = true;
			}
			else if (e.type == SDL_KEYUP)
			{
				INFO( "SDL_KEYUP" );
				m_game->Input()->HandleKeyUp(&e.key);

				//PrintKeyboardEvent(&e);
				wasEvent = true;
			}
			else if (e.type == SDL_KEYMAPCHANGED)
			{
				INFO( "SDL_KEYMAPCHANGED" );
				std::cout << "KeyMapChanged";
				//PrintKeyboardEvent( &e );
				wasEvent = true;
			}
			else if (e.type == SDL_TEXTEDITING) //CJK
			{
				INFO( "SDL_TEXTEDITING" );
				//PrintTextEditingEvent(&e);
				wasEvent = true;
			}
			else if (e.type == SDL_TEXTINPUT)
			{
				INFO( "SDL_TEXTINPUT" );
				//PrintTextInputEvent(&e);
				wasEvent = true;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				INFO( "SDL_MOUSEBUTTONDOWN" );
				m_game->Input()->HandleMouseButtonDown(&e.button);

				//PrintMouseButtonEvent(&e);
				wasEvent = true;
			}
			else if (e.type == SDL_MOUSEBUTTONUP)
			{
				INFO( "SDL_MOUSEBUTTONUP" );
				m_game->Input()->HandleMouseButtonUp(&e.button);

				//PrintMouseButtonEvent(&e);

				wasEvent = true;
			}
			else if (e.type == SDL_MOUSEWHEEL)
			{
				INFO( "SDL_MOUSEWHEEL" );
				//PrintMouseWheelEvent(&e);

				wasEvent = true;
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				INFO( "SDL_MOUSEMOTION" );
				i++;
				m_game->Input()->HandleMouseMotion(&e.motion);

				//PrintMouseMotionEvent(&e);

				wasEvent = true;
			}
			else if ( e.type == SDL_WINDOWEVENT )
			{
				INFO( "SDL_WINDOWEVENT" );
				//PrintWindowEvent(&e);

				wasEvent = true;
			}
			else
			{
				//INFO( "SDL_GENERICEVENT %s", Str2Wstr(GetEventTypeStr(e.type)).c_str() );
				//PrintGenericEvent(&e);

				wasEvent = true;
			}
		}

		if ( wasEvent ) 
		{
			if ( i >= 2 )
			{
				INFO( "TWICE" );
			}
			INFO( "Event handling finished" );
		}
		//std::cout << "Event handling finished" << std::endl;

		Uint32 newTicks = SDL_GetTicks();

		Tick(newTicks - lastTicks);

		RenderScene(newTicks - lastTicks);

		lastTicks = newTicks;
	}

	Clean();
}


void GameManager::Tick(Uint32 diff) 
{
	WindowTitleManager::Inst()->Tick(diff);

	m_game->Tick(diff);
}


void GameManager::RenderScene(Uint32 diff)
{
    //Render the scene
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
    SDL_RenderClear(ren);

    OutputFPS();

	m_game->Render();

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

		WindowTitleManager::Inst()->AddToWindowTitle(title);
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