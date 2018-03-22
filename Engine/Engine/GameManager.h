#pragma once
#include "Engine/Utils/Singleton.h"
#include "Engine/Entity.h"
#include "Engine/Game.h"


#define CFG GameManager::Inst()->m_cfg


class AppConfig;


class GameManager : public Singleton<GameManager>
{
public:
	friend Singleton<GameManager>;

	~GameManager();

	int Init(Game* game);
	int InitSDL();
	int InitLogger();
	int InitEngine();

	void CenterWindow();

	void MainLoop();
	void Clean();

	void Tick(Uint32 diff);
	void RenderScene(Uint32 diff);

	int	GetNumOpenGLDriver();

public:
	Game*				m_game;

	int					vpHeight;
	int					vpWidth;

	SDL_Window*			win;
	SDL_Renderer*		ren;

	int					winX;
	int					winY;

	int					m_fps;

	AppConfig*			m_cfg;





protected:
	GameManager();

	void OutputFPS();

};






