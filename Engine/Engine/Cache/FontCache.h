#pragma once
#include "Engine/Utils/Singleton.h"


class FontCache : public Singleton<FontCache>
{
public:
	typedef Singleton<FontCache> super;

	FontCache();
	virtual ~FontCache();

	TTF_Font* GetFont(const std::string& path, int pointSize);

public:
	// font name to point size then to TTF_Font
	std::map<std::string, std::map<int, TTF_Font*> > m_fonts;

private:
	TTF_Font* LoadFont(const std::string& path, int pointSize);
};

