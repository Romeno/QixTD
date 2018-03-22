#include "stdafx.h"
#include "FontCache.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Utils/Logger.h"


FontCache::FontCache()
{

}


FontCache::~FontCache()
{
	std::for_each(m_fonts.begin(), m_fonts.end(), 
		[](auto ptSizeMapPair) 
		{ 
			std::for_each(ptSizeMapPair.second.begin(), ptSizeMapPair.second.end(), [](auto fontPair) {RemoveSDLObj(fontPair.second); });
		});
}


TTF_Font* FontCache::GetFont(const std::string& path, int pointSize)
{
	auto itPoints = m_fonts.find(path);
	if (itPoints != m_fonts.end())
	{
		auto it = itPoints->second.find(pointSize);
		if (it != itPoints->second.end())
		{
			return it->second;
		}
		else 
		{
			return LoadFont(path, pointSize);
		}
	}
	else
	{
		return LoadFont(path, pointSize);
	}

}


TTF_Font* FontCache::LoadFont(const std::string& path, int pointSize)
{
	TTF_Font* font = TTF_OpenFont(path.c_str(), pointSize);
	if (font == nullptr) {
		ERR(ERR_TYPE_SDL_ERROR, "TTF_OpenFont error: %s", SDL_GetError());
		return nullptr;
	}
	m_fonts[path][pointSize] = font;

	return font;
}
