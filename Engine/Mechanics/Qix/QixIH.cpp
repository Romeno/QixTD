#include "stdafx.h"
#include "QixIH.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Utils/SystemInfo.h"
#include "Engine/Entity.h"
#include "Mechanics/Qix/Qix.h"
#include "Mechanics/Qix/QixAPI.h"
#include "Mechanics/Qix/Components/Controlling/QixPC.h"


#define GAME (GameManager::Inst()->m_game)


QixIH::QixIH()
	: super()
{

}


QixIH::~QixIH()
{

}


int QixIH::Init()
{
	return super::Init();
}


void QixIH::Tick(Uint32 diff)
{
	super::Tick(diff);
}


void QixIH::Clear()
{
	super::Clear();
}


void QixIH::HandleKeyUp(SDL_KeyboardEvent* e)
{
	//if (e->keysym.scancode == SDL_SCANCODE_LEFT)
	//{
	//	PC->RequestStopMoveLeft();
	//}
	//else if (e->keysym.scancode == SDL_SCANCODE_RIGHT)
	//{
	//	PC->RequestStopMoveRight();
	//}
	//else if (e->keysym.scancode == SDL_SCANCODE_UP)
	//{
	//	PC->RequestStopMoveUp();
	//}
	//else if (e->keysym.scancode == SDL_SCANCODE_DOWN)
	//{
	//	PC->RequestStopMoveDown();
	//}

	super::HandleKeyUp( e );
}


void QixIH::HandleKeyDown(SDL_KeyboardEvent* e)
{
	//if (e->keysym.scancode == SDL_SCANCODE_LEFT)
	//{
	//	PC->RequestStartMoveLeft();
	//}
	//else if (e->keysym.scancode == SDL_SCANCODE_RIGHT)
	//{
	//	PC->RequestStartMoveRight();
	//}
	//else if (e->keysym.scancode == SDL_SCANCODE_UP)
	//{
	//	PC->RequestStartMoveUp();
	//}
	//else if (e->keysym.scancode == SDL_SCANCODE_DOWN)
	//{
	//	PC->RequestStartMoveDown();
	//}
	//else if (e->keysym.scancode == SDL_SCANCODE_SPACE)
	//{
	//	PC->RequestShoot();
	//}

	//else if (e->keysym.scancode == SDL_SCANCODE_ESCAPE)
	//{
	//	//GAME->Quit();
	//}

	super::HandleKeyDown( e );
}


void QixIH::HandleMouseButtonDown(SDL_MouseButtonEvent* e)
{
	super::HandleMouseButtonDown( e );
}


void QixIH::HandleMouseButtonUp(SDL_MouseButtonEvent* e)
{
	super::HandleMouseButtonUp( e );
}


void QixIH::HandleMouseMotion(SDL_MouseMotionEvent* e)
{
	super::HandleMouseMotion( e );
}


void QixIH::HandleMouseWheel( SDL_MouseWheelEvent* e )
{
	super::HandleMouseWheel( e );
}


void QixIH::HandleKeymapChanged( SDL_KeyboardEvent* e )
{
	super::HandleKeymapChanged( e );
}


void QixIH::HandleTextEditing( SDL_TextEditingEvent* e )
{
	super::HandleTextEditing( e );
}


void QixIH::HandleTextInput( SDL_TextInputEvent* e )
{
	super::HandleTextInput( e );
}
