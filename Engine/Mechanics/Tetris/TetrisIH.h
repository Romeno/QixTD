#pragma once
#include "Engine/InputHandler.h"


class TetrisIH : public InputHandler
{
public:
	typedef InputHandler super;

	TetrisIH();
	virtual ~TetrisIH();

	virtual int Init();
	virtual void Tick( Uint32 diff );
	virtual void Clear();

	virtual void HandleKeyUp( SDL_KeyboardEvent* e ) override;
	virtual void HandleKeyDown( SDL_KeyboardEvent* e ) override;
	virtual void HandleKeymapChanged( SDL_KeyboardEvent* e ) override;
	virtual void HandleTextEditing( SDL_TextEditingEvent* e ) override;
	virtual void HandleTextInput( SDL_TextInputEvent* e ) override;

	virtual void HandleMouseButtonDown( SDL_MouseButtonEvent* e ) override;
	virtual void HandleMouseButtonUp( SDL_MouseButtonEvent* e ) override;
	virtual void HandleMouseMotion( SDL_MouseMotionEvent* e ) override;
	virtual void HandleMouseWheel( SDL_MouseWheelEvent* e ) override;

	//SDL_Point			m_lastMouseSPos;
	//glm::dvec3			m_lastMouseWPos;
	//SDL_TimerID			m_timerID;
	//CRITICAL_SECTION	m_addPointCS;





};

