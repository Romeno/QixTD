#include "stdafx.h"
#include "Defines.h"
#include "GameManager.h"
#include "Utils.h"
#include "SystemInfo.h"
#include "CoordinateSystem.h"
#include "Logger.h"
#include "WindowTitleManager.h"
#include "IH.h"
#include "PC.h"
#include "SC.h"
#include "AppConfig.h"
#include "MapConfigStub.h"
#include "ColoredRect.h"
#include "LineCascade.h"



GameManager::GameManager()
	: vpHeight(480)
	, vpWidth(640)

	, win(nullptr)
	, ren(nullptr)

	, winX(0)
	, winY(0)

	, m_fps(0)

	, m_quit(false)

    , m_mapConfigs()
	, m_mapNumber(0)
	, m_currentMap(nullptr)

	, m_borderController(nullptr)

	, m_cfg(nullptr)

	, m_pc(nullptr)
	, m_ih(nullptr)
	, m_sc(nullptr)

	, m_drawables()
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


void GameManager::RegisterDrawable(Drawable* d)
{
	m_drawables.push_back(d);
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
	m_ih = new QixIH();
	m_pc = new QixPC();
	m_sc = new QixSC();

	m_cfg = new AppConfig();
	ConfigError cfgRet = m_cfg->Read();
	if (cfgRet != CONFIG_ERROR_OK) 
	{
		return 1;
	}

	WindowTitleManager::Inst()->Init(m_cfg->m_windowTitle);

    for (int i = 0; i < m_cfg->m_numMaps; i++) {
		MapConfigStub* map = new MapConfigStub(std::to_string(i));
		cfgRet = map->Read();
		if (cfgRet != CONFIG_ERROR_OK)
		{
			return 1;
		}

        m_mapConfigs.push_back(map);
    }

	m_borderController = new LineCascade("borders");
	//m_drawables.push_back(m_borderController);

    return LoadMap(0);
}


int GameManager::LoadMap(int num) 
{
    int ret;

	m_mapNumber = num;
    m_currentMap = m_mapConfigs[num];
	

	//for (int i = 0; i < 40; i++)
	//{
	//	for (int j = 0; j < 30; j++)
	//	{
	//		ColoredRect* bg = new ColoredRect("bg", glm::ivec4(i % 2 == j % 2 ? 255 : 0, 0, i % 2 == j % 2 ? 0 : 255, 0), glm::dvec3(64, 64, 0));
	//		bg->SetWPos(glm::dvec3(64 * i - m_currentMap->m_mapDimensions.x / 2, m_currentMap->m_mapDimensions.y / 2 - 64 * j, -100));
	//		m_entities.insert(bg);
	//	}
	//}

	ColoredRect* bg = new ColoredRect("bg", glm::ivec4(128, 128, 128, 0), glm::dvec3(m_currentMap->m_mapDimensions.x, m_currentMap->m_mapDimensions.y, 0));
	bg->SetWPos(glm::dvec3(0, 0, -200));
	m_drawables.push_back(bg);

	bg = new ColoredRect("bg2", glm::ivec4(255, 0, 255, 0), glm::dvec3(100, 100, 0));
	bg->SetWPos(glm::dvec3(0, 0, -100));
	m_drawables.push_back(bg);


    // INPUT_HANDLER
    m_ih->Init();


    // PLAYER_CONTROLLER
    ret = m_pc->Init();
    if (ret)
    {
        ERR(ERR_TYPE_ENGINE_ERROR, "PlrCtrl Init failed");
        return ret;
    }

    PC()->SetWPos(m_currentMap->m_playerStartPos);


    // SCREEN_CONTROLLER
    m_sc->Init(m_currentMap->m_playerStartPos);


    // GENERIC ENTITIES
    //m_entities.push_back(new PlatformInfo());

    for (auto it = m_drawables.begin(); it != m_drawables.end(); it++)
    {
        ret = (*it)->Init();
        if (ret)
        {
			ERR(ERR_TYPE_ENGINE_ERROR, "%s Entity Init failed", (*it)->m_name);
			
			for (auto itc = m_drawables.begin(); itc != m_drawables.end(); itc++)
            {
                (*itc)->Clear();
            }

            return ret;
        }
    }

    return 0;
}


void GameManager::MainLoop()
{
	static Uint32 lastTicks = SDL_GetTicks();

	SDL_Event e;

	while (!m_quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
			{
				m_quit = true;
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

	//m_drawables.erase(std::remove_if(m_drawables.begin(), m_drawables.end(), ), m_drawables.end());

	m_ih->Tick(diff);

	m_pc->Tick(diff);

	m_sc->Tick(diff);

	for (auto it = m_drawables.begin(); it != m_drawables.end(); it++) 
	{
		(*it)->Tick(diff);
	}
}


void GameManager::Clean()
{
	SDL_StopTextInput();

	cleanup(ren, win);

	SDL_Quit();
}


void GameManager::Quit()
{
    m_quit = true;
}


void GameManager::RenderScene(Uint32 diff)
{
    //Render the scene
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
    SDL_RenderClear(ren);

    OutputFPS();

    //	//SDL_Point imagePos = { (vpWidth - imageLength) / 2, (vpHeight - imageHeight) / 2 };
    //
    //#ifdef PLATFORMER_GAME_TYPE
    //	LeafRain::Inst()->Render(true);
    //#endif
    //
    //
    //#ifdef PLATFORMER_GAME_TYPE
    //	LeafRain::Inst()->Render(false);
    //#endif

	std::sort(m_drawables.begin(), m_drawables.end(), [](Drawable* one, Drawable* two) -> bool { return one->m_wPos.z < two->m_wPos.z; });

	for (auto it = m_drawables.begin(); it != m_drawables.end(); it++)
	{
		(*it)->Render();
	}

	m_pc->Render();

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


void GameManager::DeleteDrawable(Drawable* d)
{
	auto it = std::find_if(m_drawables.begin(), m_drawables.end(), [d](Drawable* found) { return found->m_id == d->m_id; });
	m_drawables.erase(it);
	delete (*it);
}


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


/*
 *
 * Romeno's code
 * To be Romeno Company
 * Project: Learning game development
 *
 */