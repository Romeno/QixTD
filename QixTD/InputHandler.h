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
	virtual void HandleMouseButtonDown(SDL_MouseButtonEvent* e);
	virtual void HandleMouseButtonUp(SDL_MouseButtonEvent* e);
	virtual void HandleMouseMotion(SDL_MouseMotionEvent* e);
};

