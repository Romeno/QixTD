#pragma once


class InputHandler
{
public:
	InputHandler();
	virtual ~InputHandler();

	virtual int Init();
	virtual void Tick(Uint32 diff);
	virtual void Clear();

	virtual void HandleKeyUp(SDL_KeyboardEvent* e);
	virtual void HandleKeyDown(SDL_KeyboardEvent* e);
	virtual void HandleKeymapChanged( SDL_KeyboardEvent* e );
	virtual void HandleTextEditing( SDL_TextEditingEvent* e );
	virtual void HandleTextInput( SDL_TextInputEvent* e );

	virtual void HandleMouseButtonDown(SDL_MouseButtonEvent* e);
	virtual void HandleMouseButtonUp(SDL_MouseButtonEvent* e);
	virtual void HandleMouseMotion(SDL_MouseMotionEvent* e);
	virtual void HandleMouseWheel( SDL_MouseWheelEvent* e );
};

