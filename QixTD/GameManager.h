#pragma once
#include "Defines.h"
#include "Singleton.h"
#include "Entity.h"


class AppConfig;
class PlayerController;
class InputHandler;
class ScreenController;


class GameManager : public Singleton<GameManager>
{
public:
	friend Singleton<GameManager>;

	~GameManager();

	int Init();
	int InitSDL();
	int InitLogger();
	int InitEngine();

	void CenterWindow();

	void MainLoop();

	void Tick(Uint32 diff);
	void RenderScene(Uint32 diff);
	void Clean();

	PlayerController* GetPC() { return m_pc; }
	InputHandler* GetIH() { return m_ih; }
	ScreenController* GetSC() { return m_sc; }

	int		GetNumOpenGLDriver();

	int					vpHeight;
	int					vpWidth;

	SDL_Window	       *win;
	SDL_Renderer       *ren;

	int					winX;
	int					winY;

	int					m_fps;

private:
	GameManager();

	void OutputFPS();

	AppConfig          *m_cfg;

	PlayerController   *m_pc;
	InputHandler       *m_ih;
	ScreenController   *m_sc;

	std::vector<Entity*> m_entities;
};



#ifdef PLATFORMER_GAME_TYPE
class PlatformerPC;
class PlatformerIH;
class PlatformerSC;

PlatformerPC* PC();
PlatformerIH* IH();
PlatformerSC* SC();
#endif

#ifdef LINE_CASCADE_GAME_TYPE
class LineCascadePC;
class LineIH;
class PointSplashSC;

LineCascadePC* PC();
LineIH* IH();
PointSplashSC* SC();
#endif

#ifdef POINT_SPLASH_GAME_TYPE
class PointSplashPC;
class PointIH;
class PointSplashSC;

PointSplashPC* PC();
PointIH* IH();
PointSplashSC* SC();
#endif

#ifdef QIX_GAME_TYPE
class QixPC;
class QixIH;
class QixSC;

QixPC* PC();
QixIH* IH();
QixSC* SC();
#endif