#pragma once
#ifndef _TEXTUREMANAGER__H_

#include "Engine/Utils/Singleton.h"
#include <map>


class TextureCache
{
public:
	TextureCache();
	~TextureCache();

	SDL_Texture* GetTexture(const std::string& path);

	std::map<std::string, SDL_Texture*> m_textures;



private:
	SDL_Texture* LoadTexture(const std::string& path);

};


extern TextureCache* textureCache;

#endif