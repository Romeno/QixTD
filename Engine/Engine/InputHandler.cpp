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
	INFO( "SDL_KEYUP" );

	//Keyboard::Inst()->m_clickState[e->keysym.scancode] = 0;

	PrintKeyboardEvent( (SDL_Event*) e );
}


void InputHandler::HandleKeyDown(SDL_KeyboardEvent* e)
{
	INFO( "SDL_KEYDOWN" );

	//Keyboard::Inst()->m_clickState[e->keysym.scancode] = 1;

	PrintKeyboardEvent( (SDL_Event*) e );
}


void InputHandler::HandleKeymapChanged( SDL_KeyboardEvent* e )
{
	INFO( "SDL_KEYMAPCHANGED" );

	PrintKeyboardEvent( (SDL_Event*) e );
}


void InputHandler::HandleTextEditing( SDL_TextEditingEvent* e )
{
	INFO( "SDL_TEXTEDITING" );

	PrintTextEditingEvent( (SDL_Event*) e );
}


void InputHandler::HandleTextInput( SDL_TextInputEvent* e )
{
	INFO( "SDL_TEXTINPUT" );

	keyboard->m_text += e->text;

	PrintTextInputEvent( (SDL_Event*) e );
}


void InputHandler::HandleMouseButtonDown(SDL_MouseButtonEvent* e)
{
	INFO( "SDL_MOUSEBUTTONDOWN" );

	if ( e->button == SDL_BUTTON_LEFT ) 
	{
		mouse->m_lmbDown = true;
	}
	else if ( e->button == SDL_BUTTON_MIDDLE )
	{
		mouse->m_mmbDown = true;
	}
	else if ( e->button == SDL_BUTTON_RIGHT )
	{
		mouse->m_rmbDown = true;
	}
	
	PrintMouseButtonEvent((SDL_Event*)e);
}


void InputHandler::HandleMouseButtonUp(SDL_MouseButtonEvent* e)
{
	INFO( "SDL_MOUSEBUTTONUP" );

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

	PrintMouseButtonEvent( (SDL_Event*) e);
}


void InputHandler::HandleMouseMotion(SDL_MouseMotionEvent* e)
{
	INFO( "SDL_MOUSEMOTION" );

	//PrintMouseMotionEvent((SDL_Event*)e);
}


void InputHandler::HandleMouseWheel( SDL_MouseWheelEvent* e )
{
	INFO( "SDL_MOUSEWHEEL" );

	mouse->m_wheelDelta += e->y;

	//PrintMouseWheelEvent((SDL_Event*) e );
}
