#include "stdafx.h"
#include "Keyboard.h"
#include "Engine/Utils/Utils.h"


extern Keyboard* keyboard = nullptr;


Keyboard::Keyboard()
{
	ZeroMemory( &m_prevState, SDL_NUM_SCANCODES );
}


Keyboard::~Keyboard()
{

}


void Keyboard::Init()
{

}


void Keyboard::PreTick( Uint32 diff )
{
	ZeroMemory( &m_clickState, SDL_NUM_SCANCODES );
	m_text = "";
}


bool InitPrevState()
{
	keyboard->m_state = SDL_GetKeyboardState( NULL );

	return true;
}


void Keyboard::Tick( Uint32 diff )
{
	static bool init = InitPrevState();

	m_state = SDL_GetKeyboardState( NULL );

	if ( !m_text.empty() )
	{
		INFO( "TEXT %s", Str2Wstr(m_text).c_str() );
	}
}


void Keyboard::PostTick( Uint32 diff )
{
	memcpy( keyboard->m_prevState, keyboard->m_state, SDL_NUM_SCANCODES );
}


bool Keyboard::IsKeyDown( SDL_Scancode code )
{
	return m_state[code];
}


bool Keyboard::IsKeyUp( SDL_Scancode code )
{
	return !IsKeyDown( code );
}


bool Keyboard::IsKeyClicked( SDL_Scancode code )
{
	return false;
}


bool Keyboard::IsKeyReleased( SDL_Scancode code )
{
	INFO( "PREVSTATE %d", m_prevState[code] );
	INFO( "NOWSTATE %d", m_state[code] );

	return m_prevState[code] && !m_state[code];
}


bool Keyboard::IsAltPressed()
{
	return false;
}


bool Keyboard::IsLAltPressed()
{
	return false;
}


bool Keyboard::IsRAltPressed()
{
	return false;
}


bool Keyboard::IsCtrlPressed()
{
	return false;
}


bool Keyboard::IsLCtrlPressed()
{
	return false;
}


bool Keyboard::IsRCtrlPressed()
{
	return false;
}


bool Keyboard::IsShiftPressed()
{
	return false;
}


bool Keyboard::IsLShiftPressed()
{
	return false;
}


bool Keyboard::IsRShiftPressed()
{
	return false;
}


bool Keyboard::IsSpecialPressed()
{
	return false;
}


bool Keyboard::IsLSpecialPressed()
{
	return false;
}


bool Keyboard::IsRSpecialPressed()
{
	return false;
}


bool Keyboard::IsNumLockPressed()
{
	return false;
}


bool Keyboard::IsNumLockActive()
{
	return false;
}


bool Keyboard::IsCapsLockPressed()
{
	return false;
}


bool Keyboard::IsCapsLockActive()
{
	return false;
}


bool Keyboard::IsScrollLockPressed()
{
	return false;
}


bool Keyboard::IsScrollLockActive()
{
	return false;
}
