#include "stdafx.h"
#include "Defines.h"
#include "GameManager.h"
#include "Utils.h"
#include "SystemInfo.h"
#include "CoordinateSystem.h"
#include "LevelInfo.h"
#include "Logger.h"
#include "WindowTitleManager.h"
#include "IH.h"
#include "PC.h"
#include "SC.h"
#include "AppConfig.h"


#ifdef PLATFORMER_GAME_TYPE
#include "LeafRain.h"
#include "BackgroundC.h"
#include "PlatformInfo.h"
#endif

#ifdef QIX_GAME_TYPE
#endif

GameManager::GameManager()
	: vpHeight(480)
	, vpWidth(640)

	, win(nullptr)
	, ren(nullptr)

	, winX(0)
	, winY(0)

	, m_fps(0)

	, m_cfg(nullptr)
	, m_pc(nullptr)
	, m_ih(nullptr)
	, m_sc(nullptr)
{

}


GameManager::~GameManager()
{
	delete m_ih;
	delete m_pc;
	delete m_sc;
	delete m_cfg;
}


int GameManager::Init()
{
	int ret;
	ret = InitLogger();
	if (ret != 0)
	{
		ERR(ERR_TYPE_ENGINE_ERROR, "InitLogger failed");
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
		cleanup(win, ren);
		SDL_StopTextInput();
		SDL_Quit();
		_getch();
		return ret;
	}

	PrintInfo(win, ren);

	return 0;
}


int GameManager::InitLogger()
{
	return ::InitLogger();
}


int GameManager::InitSDL() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		ERR(ERR_TYPE_SDL_ERROR, "SDL_Init error: %s", SDL_GetError());
		return 1;
	}

	win = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, vpWidth, vpHeight, SDL_WINDOW_SHOWN);
	if (win == nullptr)
	{
		ERR(ERR_TYPE_SDL_ERROR, "SDL_CreateWindow error: %s", SDL_GetError());
		return 1;
	}

	int numRenderDriver = GetNumOpenGLDriver();
	if (numRenderDriver == -1) {
		ERR(ERR_TYPE_ENGINE_ERROR, "OpenGL driver not found");
	}

	ren = SDL_CreateRenderer(win, numRenderDriver, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "SDL_CreateRenderer error: %s", SDL_GetError());
		cleanup(win);
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
	int ret;

#ifdef PLATFORMER_GAME_TYPE
	m_ih = new PlatformerIH();
	m_pc = new PlatformerPC();
	m_sc = new PlatformerSC();
#endif

#ifdef LINE_CASCADE_GAME_TYPE
	m_ih = new LineIH();
	m_pc = new LineCascadePC();
	m_sc = new PointSplashSC();
#endif

#ifdef POINT_SPLASH_GAME_TYPE
	m_ih = new PointIH();
	m_pc = new PointSplashPC();
	m_sc = new PointSplashSC();
#endif

#ifdef QIX_GAME_TYPE
	m_ih = new QixIH();
	m_pc = new QixPC();
	m_sc = new QixSC();
#endif

	m_cfg = new AppConfig();
	ConfigError cfgRet = m_cfg->Read();
	if (cfgRet != CONFIG_ERROR_OK) 
	{
		return 1;
	}

	WindowTitleManager::Inst()->Init(m_cfg->m_windowTitle);

	// LEVEL_INFO
	LevelInfo::Inst()->Init(2560, 1920);


	// INPUT_HANDLER
	m_ih->Init();


	// PLAYER_CONTROLLER
	ret = m_pc->Init();
	if (ret)
	{
		ERR(ERR_TYPE_ENGINE_ERROR, "PlrCtrl Init failed");
		return ret;
	}

	glm::dvec3 wPos = { -vpWidth / 2, 0, 0 };
	PC()->SetWPos(wPos, PIVOT_CENTER);


	// SCREEN_CONTROLLER
	m_sc->Init(wPos);


	// GENERIC ENTITIES
#ifdef PLATFORMER_GAME_TYPE
	m_entities.push_back(new PlatformInfo());
#endif

	for (size_t i = 0; i < m_entities.size(); i++)
	{
		ret = m_entities[i]->Init();
		if (ret)
		{
			for (size_t j = 0; j <= i; j++)
			{
				m_entities[j]->Clear();
			}
			
			ERR(ERR_TYPE_ENGINE_ERROR, "%s Entity Init failed", m_entities[i]->m_name);
			return ret;
		}
	}


	// OTHER_INSTANCES
#ifdef PLATFORMER_GAME_TYPE
	ret = BackgroundC::Inst()->Init();
	if (ret)
	{
		BackgroundC::Inst()->Clear();
		ERR(ERR_TYPE_ENGINE_ERROR, "BackgroundC Init failed");
		return ret;
	}

	ret = LeafRain::Inst()->Init();
	if (ret)
	{
		BackgroundC::Inst()->Clear();
		LeafRain::Inst()->Clean();
		ERR(ERR_TYPE_ENGINE_ERROR, "LeafRain Init failed");
		return ret;
	}
#endif

	return 0;
}


void GameManager::MainLoop()
{
	static Uint32 lastTicks = SDL_GetTicks();

	SDL_Event e;

	bool quit = false;

	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				m_ih->HandleKeyDown(&e.key);

				//PrintKeyboardEvent(&e);
			}
			else if (e.type == SDL_KEYUP)
			{
				m_ih->HandleKeyUp(&e.key);

				//PrintKeyboardEvent(&e);
			}
			else if (e.type == SDL_KEYMAPCHANGED)
			{
				//PrintKeyboardEvent(&e);
			}
			else if (e.type == SDL_TEXTEDITING) //CJK
			{
				//PrintTextEditingEvent(&e);
			}
			else if (e.type == SDL_TEXTINPUT)
			{
				//PrintTextInputEvent(&e);
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				m_ih->HandleMouseButtonDown(&e.button);

				//PrintMouseButtonEvent(&e);
			}
			else if (e.type == SDL_MOUSEBUTTONUP)
			{
				m_ih->HandleMouseButtonUp(&e.button);

				//PrintMouseButtonEvent(&e);
			}
			else if (e.type == SDL_MOUSEWHEEL)
			{
				//PrintMouseWheelEvent(&e);
			}
			else if (e.type == SDL_MOUSEMOTION)
			{
				m_ih->HandleMouseMotion(&e.motion);

				//PrintMouseMotionEvent(&e);
			}
		}

		Uint32 newTicks = SDL_GetTicks();

		Tick(newTicks - lastTicks);

		RenderScene(newTicks - lastTicks);

		lastTicks = newTicks;
	}
}


void GameManager::Tick(Uint32 diff) 
{
	WindowTitleManager::Inst()->Tick(diff);

#ifdef PLATFORMER_GAME_TYPE
	BackgroundC::Inst()->Tick();
#endif

	m_ih->Tick(diff);

	m_pc->Tick(diff);

	m_sc->Tick(diff);

	for (size_t i = 0; i < m_entities.size(); i++) 
	{
		m_entities[i]->Tick(diff);
	}

#ifdef PLATFORMER_GAME_TYPE
	LeafRain::Inst()->Tick(diff);
#endif
}


void GameManager::Clean()
{
	SDL_StopTextInput();

	cleanup(ren, win);

	SDL_Quit();
}


void GameManager::RenderScene(Uint32 diff)
{
	//Render the scene
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
	SDL_RenderClear(ren);

	OutputFPS();

#ifdef PLATFORMER_GAME_TYPE
	BackgroundC::Inst()->Render();
#endif

	//SDL_Point imagePos = { (vpWidth - imageLength) / 2, (vpHeight - imageHeight) / 2 };

#ifdef PLATFORMER_GAME_TYPE
	LeafRain::Inst()->Render(true);
#endif

	m_pc->Render();

#ifdef PLATFORMER_GAME_TYPE
	LeafRain::Inst()->Render(false);
#endif

#ifdef QIX_GAME_TYPE




#endif


	//for (size_t i = 0; i < m_entities.size(); i++)
	//{
	//	m_entities[i]->Render();
	//}

	//renderTexture(image, renderer, x, y);

	//glClearColor(0.5, 1.0, 1.0, 0);
	//glClear(GL_COLOR_BUFFER_BIT);

	//GLuint shader = glCreateShader(GL_VERTEX_SHADER);

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


#ifdef PLATFORMER_GAME_TYPE
PlatformerPC* PC()
{
	return (PlatformerPC*)GameManager::Inst()->GetPC();
}


PlatformerIH* IH()
{
	return (PlatformerIH*)GameManager::Inst()->GetIH();
}


PlatformerSC* SC()
{
	return (PlatformerSC*)GameManager::Inst()->GetSC();
}
#endif


#ifdef LINE_CASCADE_GAME_TYPE
LineCascadePC* PC() 
{
	return (LineCascadePC*)GameManager::Inst()->GetPC();
}


LineIH* IH()
{
	return (LineIH*)GameManager::Inst()->GetIH();
}


PointSplashSC* SC()
{
	return (PointSplashSC*)GameManager::Inst()->GetSC();
}
#endif


#ifdef POINT_SPLASH_GAME_TYPE
PointSplashPC* PC()
{
	return (PointSplashPC*)GameManager::Inst()->GetPC();
}


PointIH* IH()
{
	return (PointIH*)GameManager::Inst()->GetIH();
}


PointSplashSC* SC()
{
	return (PointSplashSC*)GameManager::Inst()->GetSC();
}

#endif


#ifdef QIX_GAME_TYPE
QixPC* PC()
{
	return (QixPC*)GameManager::Inst()->GetPC();
}


QixIH* IH()
{
	return (QixIH*)GameManager::Inst()->GetIH();
}


QixSC* SC()
{
	return (QixSC*)GameManager::Inst()->GetSC();
}

#endif


/*
 *
 * Romeno's code
 * To be Romeno Company
 * Project: Learning game development
 *
 */