#pragma once
#ifndef _TEXTUREMANAGER__H_

#include "Engine/Utils/Singleton.h"
#include <map>


class TextureCache : public Singleton<TextureCache>
{
public:
	TextureCache();
	~TextureCache();

	SDL_Texture* GetTexture(const std::string& path);

	std::map<std::string, SDL_Texture*> m_textures;

private:
	SDL_Texture* LoadTexture(const std::string& path);
};


/********************************************************************
created:	2017/07/18
created:	18:7:2017   3:30
filename: 	I:\Romeno\Projects\Visual Studio\Qix TD\QixTD\TextureManager.h
file base:	TextureManager
author:		Romeno

purpose:
*********************************************************************/
#endif