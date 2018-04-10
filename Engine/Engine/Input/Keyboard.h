#pragma once
#include "Engine/Utils/Singleton.h"


class Keyboard
{
public:
	Keyboard();
	virtual ~Keyboard();

	void Init();
	void PreTick( Uint32 diff );
	void Tick( Uint32 diff );
	void PostTick( Uint32 diff );
	
	bool IsKeyDown( SDL_Scancode code );
	bool IsKeyUp( SDL_Scancode code );
	bool IsKeyClicked( SDL_Scancode code );
	bool IsKeyReleased( SDL_Scancode code );

	// ALT
	bool IsAltPressed();

	bool IsLAltPressed();
	bool IsRAltPressed();

	// CTRL
	bool IsCtrlPressed();

	bool IsLCtrlPressed();
	bool IsRCtrlPressed();

	// SHIFT
	bool IsShiftPressed();

	bool IsLShiftPressed();
	bool IsRShiftPressed();

	// SPECIAL (Win, ?)
	bool IsSpecialPressed();

	bool IsLSpecialPressed();
	bool IsRSpecialPressed();

	// Num Lock
	bool IsNumLockPressed();
	bool IsNumLockActive();

	// Caps Lock
	bool IsCapsLockPressed();
	bool IsCapsLockActive();

	// Scroll Lock
	bool IsScrollLockPressed();
	bool IsScrollLockActive();

	Uint8			m_prevState[SDL_NUM_SCANCODES];
	const Uint8*	m_state;
	Uint8			m_clickState[SDL_NUM_SCANCODES];
	std::string		m_text;
};


extern Keyboard* keyboard;