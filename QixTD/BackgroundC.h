#pragma once
#include "Singleton.h"


class BackgroundC : public Singleton<BackgroundC>
{
public:
	BackgroundC();
	~BackgroundC();

	int Init();
	void Tick();
	void Render();
	void Clear();

	SDL_Texture	   *m_bgTex;
};

