#pragma once
#include "Mechanics/Qix/QixIH.h"


class QixTDIH : public QixIH
{
public:
	typedef QixIH super;

	QixTDIH();
	virtual ~QixTDIH();

	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;
	virtual void Clear() override;

	virtual void HandleKeyUp( SDL_KeyboardEvent* e ) override;
	virtual void HandleKeyDown( SDL_KeyboardEvent* e ) override;
	virtual void HandleKeymapChanged( SDL_KeyboardEvent* e ) override;
	virtual void HandleTextEditing( SDL_TextEditingEvent* e ) override;
	virtual void HandleTextInput( SDL_TextInputEvent* e ) override;
	virtual void HandleMouseButtonDown( SDL_MouseButtonEvent* e ) override;
	virtual void HandleMouseButtonUp( SDL_MouseButtonEvent* e ) override;
	virtual void HandleMouseMotion( SDL_MouseMotionEvent* e ) override;
	virtual void HandleMouseWheel( SDL_MouseWheelEvent* e ) override;

};

