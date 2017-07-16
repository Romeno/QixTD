#pragma once
#include "Defines.h"
#include "Singleton.h"
#include "DrawableRect.h"
#include <set>


class LineCascade;
class AppConfig;
class MapConfigStub;
class PlayerController;
class InputHandler;
class ScreenController;


//template<class _Ty = void>
//struct p_less
//{	// functor for operator<
//	typedef _Ty first_argument_type;
//	typedef _Ty second_argument_type;
//	typedef bool result_type;
//
//	_CONST_FUN bool operator()(const _Ty& _Left, const _Ty& _Right) const
//	{	// apply operator< to operands
//		return ((*_Left) < (*_Right));
//	}
//};


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
    int LoadMap(int num);

    void Quit();

	void RegisterDrawable(Drawable* d);
	void DeleteDrawable(Drawable* d);

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

    bool                m_quit;

	std::vector<MapConfigStub*>		m_mapConfigs;
	int 							m_mapNumber;
	MapConfigStub*					m_currentMap;

	LineCascade*					m_borderController;

private:
	GameManager();

	void OutputFPS();

	AppConfig                  *m_cfg;

	PlayerController           *m_pc;
	InputHandler               *m_ih;
	ScreenController           *m_sc;

	std::vector<Drawable*>      m_drawables;
};



class QixPC;
class QixIH;
class QixSC;

QixPC* PC();
QixIH* IH();
QixSC* SC();
