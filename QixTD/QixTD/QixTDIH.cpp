#include "stdafx.h"
#include "QixTDIH.h"
#include "Engine/Input/Keyboard.h"
#include "Engine/Input/Mouse.h"
#include "Mechanics/Qix/Components/Controlling/QixPC.h"
#include "Mechanics/Qix/Qix.h"
#include "QixTD/QixTDAPI.h"
#include "QixTD/Components/Controlling/QixTDPC.h"
#include "QixTD/QixTD.h"
#include "Engine/Utils/Utils.h"


QixTDIH::QixTDIH()
{

}


QixTDIH::~QixTDIH()
{

}


int QixTDIH::Init()
{
	return super::Init();
}


void QixTDIH::Tick( Uint32 diff )
{
	super::Tick( diff );
}


void QixTDIH::Clear()
{
	super::Clear();
}


void QixTDIH::HandleKeyUp( SDL_KeyboardEvent* e )
{
	//if ( e->keysym.scancode == SDL_SCANCODE_LEFT )
	//{
	//	PC->RequestStopMoveLeft();
	//}
	//else if ( e->keysym.scancode == SDL_SCANCODE_RIGHT )
	//{
	//	PC->RequestStopMoveRight();
	//}
	//else if ( e->keysym.scancode == SDL_SCANCODE_UP )
	//{
	//	PC->RequestStopMoveUp();
	//}
	//else if ( e->keysym.scancode == SDL_SCANCODE_DOWN )
	//{
	//	PC->RequestStopMoveDown();
	//}

	super::HandleKeyUp( e );
}


void QixTDIH::HandleKeyDown( SDL_KeyboardEvent* e )
{
	//if ( e->keysym.scancode == SDL_SCANCODE_LEFT )
	//{
	//	PC->RequestStartMoveLeft();
	//}
	//else if ( e->keysym.scancode == SDL_SCANCODE_RIGHT )
	//{
	//	PC->RequestStartMoveRight();
	//}
	//else if ( e->keysym.scancode == SDL_SCANCODE_UP )
	//{
	//	PC->RequestStartMoveUp();
	//}
	//else if ( e->keysym.scancode == SDL_SCANCODE_DOWN )
	//{
	//	PC->RequestStartMoveDown();
	//}
	//else if ( e->keysym.scancode == SDL_SCANCODE_SPACE )
	//{
	//	PC->RequestShoot();
	//}

	//else if ( e->keysym.scancode == SDL_SCANCODE_ESCAPE )
	//{
	//	//GAME->Quit();
	//}

	super::HandleKeyDown( e );
}


void QixTDIH::HandleMouseButtonDown( SDL_MouseButtonEvent* e )
{
	super::HandleMouseButtonDown( e );
}


void QixTDIH::HandleMouseButtonUp( SDL_MouseButtonEvent* e )
{
	super::HandleMouseButtonUp( e );
}


void QixTDIH::HandleMouseMotion( SDL_MouseMotionEvent* e )
{
	super::HandleMouseMotion( e );
}


void QixTDIH::HandleMouseWheel( SDL_MouseWheelEvent* e )
{
	super::HandleMouseWheel( e );
}


void QixTDIH::HandleKeymapChanged( SDL_KeyboardEvent* e )
{
	super::HandleKeymapChanged( e );
}


void QixTDIH::HandleTextEditing( SDL_TextEditingEvent* e )
{
	super::HandleTextEditing( e );
}


void QixTDIH::HandleTextInput( SDL_TextInputEvent* e )
{
	super::HandleTextInput( e );
}