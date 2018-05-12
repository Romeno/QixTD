#include "stdafx.h"
#include "InputHandler.h"
#include "Engine/Input/Mouse.h"
#include "Engine/Input/Keyboard.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Utils/SystemInfo.h"


InputHandler::InputHandler()
{

}


InputHandler::~InputHandler()
{

}


int InputHandler::Init()
{
	return 0;
}


void InputHandler::Tick(Uint32 diff)
{

}


void InputHandler::Clear()
{

}


void InputHandler::HandleKeyUp(SDL_KeyboardEvent* e)
{
	ILOGB( "SDL_KEYUP" );

	//Keyboard::Inst()->m_clickState[e->keysym.scancode] = 0;

	LogKeyboardEvent( (SDL_Event*) e, LOGGER_BAICAL, MODULE_KEYBOARD );
}


void InputHandler::HandleKeyDown(SDL_KeyboardEvent* e)
{
	ILOGB( "SDL_KEYDOWN" );

	//Keyboard::Inst()->m_clickState[e->keysym.scancode] = 1;

	LogKeyboardEvent( (SDL_Event*) e, LOGGER_BAICAL, MODULE_KEYBOARD );
}


void InputHandler::HandleKeymapChanged( SDL_KeyboardEvent* e )
{
	ILOGB( "SDL_KEYMAPCHANGED" );

	LogKeyboardEvent( (SDL_Event*) e, LOGGER_BAICAL, MODULE_KEYBOARD );
}


void InputHandler::HandleTextEditing( SDL_TextEditingEvent* e )
{
	ILOGB( "SDL_TEXTEDITING" );

	LogTextEditingEvent( (SDL_Event*) e, LOGGER_BAICAL, MODULE_KEYBOARD );
}


void InputHandler::HandleTextInput( SDL_TextInputEvent* e )
{
	ILOGB( "SDL_TEXTINPUT" );

	keyboard->m_text += e->text;

	LogTextInputEvent( (SDL_Event*) e, LOGGER_BAICAL, MODULE_KEYBOARD );
}


void InputHandler::HandleMouseButtonDown(SDL_MouseButtonEvent* e)
{
	ILOGB( "SDL_MOUSEBUTTONDOWN" );

	if ( e->button == SDL_BUTTON_LEFT ) 
	{
		mouse->m_lmbDown = true;
		mouse->m_lmbPressed = true;
	}
	else if ( e->button == SDL_BUTTON_MIDDLE )
	{
		mouse->m_mmbDown = true;
		mouse->m_mmbPressed = true;
	}
	else if ( e->button == SDL_BUTTON_RIGHT )
	{
		mouse->m_rmbDown = true;
		mouse->m_rmbPressed = true;
	}
	
	LogMouseButtonEvent( (SDL_Event*)e, LOGGER_BAICAL, MODULE_KEYBOARD );
}


void InputHandler::HandleMouseButtonUp(SDL_MouseButtonEvent* e)
{
	ILOGB( "SDL_MOUSEBUTTONUP" );

	bool doubleClick = e->clicks % 2 == 0;

	if ( e->button == SDL_BUTTON_LEFT )
	{
		mouse->m_lmbDown = false;
		mouse->m_lmbClick = true;
		mouse->m_lmbDblClick = doubleClick;
	}
	else if ( e->button == SDL_BUTTON_MIDDLE )
	{
		mouse->m_mmbDown = false;
		mouse->m_mmbClick = true;
		mouse->m_mmbDblClick = doubleClick;
	}
	else if ( e->button == SDL_BUTTON_RIGHT )
	{
		mouse->m_rmbDown = false;
		mouse->m_rmbClick = true;
		mouse->m_rmbDblClick = doubleClick;
	}

	LogMouseButtonEvent( (SDL_Event*) e, LOGGER_BAICAL, MODULE_KEYBOARD );
}


void InputHandler::HandleMouseMotion(SDL_MouseMotionEvent* e)
{
	ILOGB( "SDL_MOUSEMOTION" );

	// LogMouseMotionEvent( (SDL_Event*)e, LOGGER_BAICAL, MODULE_KEYBOARD );
}


void InputHandler::HandleMouseWheel( SDL_MouseWheelEvent* e )
{
	ILOGB( "SDL_MOUSEWHEEL" );

	mouse->m_wheelDelta += e->y;

	// LogMouseWheelEvent( (SDL_Event*) e, LOGGER_BAICAL, MODULE_KEYBOARD );
}
