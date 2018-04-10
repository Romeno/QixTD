#pragma once
#include "Engine/Utils/Singleton.h"

#define LMB_PRESSED mouse->isLMBPressed()
#define MMB_PRESSED mouse->isMMBPressed()
#define RMB_PRESSED mouse->isRMBPressed()
#define MOUSE_POS mouse->GetPos()
#define MOUSE_SET_POS(rPos) mouse->SetPos(rPos)


class Mouse
{
public:
	typedef Singleton<Mouse> super;

	Mouse();
	virtual ~Mouse();

	void Init();
	void PreTick( Uint32 diff );
	void Tick( Uint32 diff );
	void PostTick( Uint32 diff );

	glm::dvec3 GetPos(); // returns rPos
	void SetPos( glm::dvec3 rPos );

	bool isLMBPressed();
	bool isMMBPressed();
	bool isRMBPressed();

	

	// TODO: drag n drop
	// TODO: rectangle selection
	// TODO: dbl clicks
	// TODO: is clicked
	// TODO: click cursor change support
	// TODO: rectangle select cursor change support

	int*	m_x;
	int*	m_y;
	Uint32	m_state;

	// показатели, что на данном тике произошёл клик
	bool m_lmbClick;
	bool m_mmbClick;
	bool m_rmbClick;

	// показатели, что на данном тике произошёл двойной клик
	bool m_lmbDblClick;
	bool m_mmbDblClick;
	bool m_rmbDblClick;

	// эти для проверки, что оба способа считывания положения нажатий мыши работают одинаково
	bool m_lmbDown;
	bool m_mmbDown;
	bool m_rmbDown;

	int m_wheelDelta;

	static std::string MouseState2Str( Uint32 state );
	static std::string WheelDirection2Str( Uint32 direction );


	//////////////////////////////////////////////////////////////////////////////////////////////

	// Cursor stuff
	class Cursor 
	{
	public:
		Cursor();
		~Cursor();

		void Enable();
		static Cursor* Load(const std::string& path, int pointerX, int pointerY, int id );

		SDL_Cursor* cur;
	};

	void SetCursor( int id );

	std::map<int, Cursor*> m_cursors;
};


extern Mouse* mouse;