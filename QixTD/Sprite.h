#pragma once
#include "DrawableRect.h"
#include "CoordinateSystem.h"


class Sprite : public DrawableRect
{
public:
	Sprite(const std::string& name, const std::string& imagePath, glm::dvec3 size);
	virtual ~Sprite();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Clear() override;
	virtual void Render() override;


    std::string		m_imagePath;

    SDL_Texture	   *m_texture;
};

//class ColoredRect;

//bool operator <(const Sprite& one, const Sprite& two);
//bool operator <(const Sprite& one, const ColoredRect& two);
//bool operator <(const ColoredRect& one, const Sprite& two);

