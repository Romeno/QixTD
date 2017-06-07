#include "stdafx.h"
#include "BackgroundC.h"
#include "GameManager.h"
#include "Utils.h"
#include "Logger.h"


BackgroundC::BackgroundC()
	: m_bgTex(nullptr)
{

}


BackgroundC::~BackgroundC()
{

}


int BackgroundC::Init()
{
	std::string imagePath = GetResourcePath() + "bg.jpg";
	SDL_Surface *img = IMG_Load(imagePath.c_str());
	if (img == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "IMG_Load error: %s", SDL_GetError());
		cleanup(img);
		return 1;
	}

	m_bgTex = SDL_CreateTextureFromSurface(REN, img);
	cleanup(img);
	if (m_bgTex == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "SDL_CreateTextureFromSurface error: %s", SDL_GetError());
		cleanup(m_bgTex);
		return 1;
	}

	return 0;
}


void BackgroundC::Tick()
{

}


void BackgroundC::Render()
{
	SDL_Rect dstrect = {
		0,
		0,
		VP_WIDTH,
		VP_HEIGHT
	};
	SDL_RenderCopy(REN, m_bgTex, NULL, &dstrect);
}


void BackgroundC::Clear()
{
	cleanup(m_bgTex);
}
