#include "stdafx.h"
#include "TextureManager.h"
#include "Engine/GameManager.h"
#include "Engine/Utils/Logger.h"
#include "Engine/Utils/Utils.h"


TextureManager::TextureManager()
	: Singleton<TextureManager>()
	, m_textures()
{

}


TextureManager::~TextureManager()
{
	std::for_each(m_textures.begin(), m_textures.end(), [](auto val) { RemoveSDLObj(val.second); });
}


SDL_Texture* TextureManager::GetTexture(const std::string& path)
{
	auto it = m_textures.find(path);
	if (it != m_textures.end())
	{
		return it->second;
	} 
	else
	{
		return LoadTexture(path);
	}
}


SDL_Texture* TextureManager::LoadTexture(const std::string& path)
{
	SDL_Surface *img = IMG_Load(path.c_str());
	if (img == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "IMG_Load error: %s", SDL_GetError());
		RemoveSDLObj(img);
		return nullptr;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(REN, img);
	RemoveSDLObj(img);
	if (texture == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "SDL_CreateTextureFromSurface error: %s", SDL_GetError());
		RemoveSDLObj(texture);
		return nullptr;
	}
	m_textures[path] = texture;

	return texture;
}

