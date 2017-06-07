#include "stdafx.h"
#include "Defines.h"

#ifdef PLATFORMER_GAME_TYPE

#include "PlatformInfo.h"
#include "Utils.h"
#include "Logger.h"
#include "GameManager.h"
#include "PC.h"


PlatformInfo::PlatformInfo()
	: Entity("PlatformInfo")
{

}


PlatformInfo::~PlatformInfo()
{

}


int PlatformInfo::Init()
{
	std::string imagePath = GetResourcePath() + "platform.jpg";
	SDL_Surface *img = IMG_Load(imagePath.c_str());
	if (img == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "IMG_Load error: %s", SDL_GetError());
		cleanup(img);
		return 1;
	}

	m_platformTex = SDL_CreateTextureFromSurface(REN, img);
	cleanup(img);
	if (m_platformTex == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "SDL_CreateTextureFromSurface error: %s", SDL_GetError());
		cleanup(m_platformTex);
		return 1;
	}

	m_platforms.push_back( { (double)-VP_WIDTH, (double)-(PC()->m_collider.height + PC()->m_collider.top - PC()->m_imageHeight / 2), (double)VP_WIDTH, 20. } );

	return 0;
}


void PlatformInfo::Render()
{
	SDL_Rect dstrect;
	for (size_t i = 0; i < m_platforms.size(); i++)
	{
		dstrect = {
			W2Sx(m_platforms[i].left),
			W2Sy(m_platforms[i].top),
			(int)m_platforms[i].width,
			(int)m_platforms[i].height
		};
		SDL_RenderCopy(REN, m_platformTex, NULL, &dstrect);
	}
}


void PlatformInfo::Tick(Uint32 diff)
{

}


void PlatformInfo::Clear()
{
	cleanup(m_platformTex);
}


#endif