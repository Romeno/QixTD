#pragma once
#include "Engine/DrawableRect.h"
#include "Engine/CoordinateSystem.h"


class Sprite;


class ColoredRect : public DrawableRect
{
public:
    ColoredRect(const std::string& name, glm::ivec4 color, glm::dvec3 size);
	ColoredRect(const ColoredRect& other);
	//ColoredRect(ColoredRect&& other);
	ColoredRect& operator=(const ColoredRect& other);
    ~ColoredRect();

    virtual int Init() override;
    virtual void Tick(Uint32 diff) override;
    //virtual void Clear() override;
	virtual void Render() override;

	//virtual bool lessThan(const Entity& other) const override;
	//
	//bool lessThan(const ColoredRect& other) const;
	//bool lessThan(const Sprite& other) const;

    //void SetWPos(glm::dvec3 wPos, Pivot pivot = Pivot::PIVOT_CENTER);

    glm::ivec4      m_color;
};

//bool operator <(const ColoredRect& one, const ColoredRect& two);