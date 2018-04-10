#include "stdafx.h"
#include "TetrisIH.h"


TetrisIH::TetrisIH()
{

}


TetrisIH::~TetrisIH()
{

}


int TetrisIH::Init()
{
	return super::Init();
}


void TetrisIH::Tick( Uint32 diff )
{
	super::Tick( diff );
}


void TetrisIH::Clear()
{
	super::Clear();
}


void TetrisIH::HandleKeyUp( SDL_KeyboardEvent* e )
{
	super::HandleKeyUp( e );
}


void TetrisIH::HandleKeyDown( SDL_KeyboardEvent* e )
{
	super::HandleKeyDown( e );
}


void TetrisIH::HandleKeymapChanged( SDL_KeyboardEvent* e )
{
	super::HandleKeymapChanged( e );
}


void TetrisIH::HandleTextEditing( SDL_TextEditingEvent* e )
{
	super::HandleTextEditing( e );
}


void TetrisIH::HandleTextInput( SDL_TextInputEvent* e )
{
	super::HandleTextInput( e );
}


void TetrisIH::HandleMouseButtonDown( SDL_MouseButtonEvent* e )
{
	super::HandleMouseButtonDown( e );
}


void TetrisIH::HandleMouseButtonUp( SDL_MouseButtonEvent* e )
{
	super::HandleMouseButtonUp( e );
}


void TetrisIH::HandleMouseMotion( SDL_MouseMotionEvent* e )
{
	super::HandleMouseMotion( e );
}


void TetrisIH::HandleMouseWheel( SDL_MouseWheelEvent* e )
{
	super::HandleMouseWheel( e );
}
