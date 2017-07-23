#include "stdafx.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Sprite.h"
#include "ColoredRect.h"


ColoredRect::ColoredRect(const std::string& name, glm::ivec4 color, glm::dvec3 size)
    : DrawableRect(name, size)

	, m_color(color)
{

}


ColoredRect::~ColoredRect()
{
	
}


ColoredRect::ColoredRect(const ColoredRect& other)
	: DrawableRect(other)

	, m_color(other.m_color)
{

}


ColoredRect& ColoredRect::operator=(const ColoredRect& other)
{
	m_color = other.m_color;

	return (*this);
}


int ColoredRect::Init()
{
	return DrawableRect::Init();
}


void ColoredRect::Render()
{
    SDL_Rect r = {
        W2Sx(m_wPos.x),
        W2Sy(m_wPos.y),
        m_size.x,
        m_size.y
    };

    SDL_SetRenderDrawColor(REN, m_color.r, m_color.g, m_color.b, m_color.a);
    SDL_RenderFillRect(REN, &r);
}


void ColoredRect::Tick(Uint32 diff)
{
	DrawableRect::Tick(diff);
}


//void ColoredRect::Clear()
//{
//
//}


//void ColoredRect::SetWPos(glm::dvec3 wPos, Pivot pivot /*= Pivot::PIVOT_CENTER*/)
//{
//    if (pivot == PIVOT_CENTER) {
//        m_wPos.x = wPos.x - m_size.x / 2;
//        m_wPos.y = wPos.y + m_size.y / 2;
//		m_wPos.z = wPos.z;
//    }
//    else
//    {
//
//    }
//}


//bool ColoredRect::lessThan(const Entity& other) const
//{
//	const ColoredRect* crp = dynamic_cast<const ColoredRect*>(&other);
//
//	if (crp == nullptr)
//	{
//		const Sprite* sp = dynamic_cast<const Sprite*>(&other);
//
//		if (sp == nullptr)
//		{
//			return this->Entity::lessThan(other);
//		}
//		else
//		{
//			return (*this) < (*sp);
//		}
//	}
//	else 
//	{
//		return (*this) < (*crp);
//	}
//}
//
//
//bool ColoredRect::lessThan(const ColoredRect& other) const
//{
//	std::cout << "MCC" << std::endl;
//	return m_wPos.z < other.m_wPos.z;
//}
//
//
//bool ColoredRect::lessThan(const Sprite& other) const
//{
//	std::cout << "MCS" << std::endl;
//	return m_wPos.z < two.m_wPos.z;
//}
//
//
//bool operator<(const ColoredRect& one, const ColoredRect& two)
//{
//	std::cout << "OCC" << std::endl;
//	return one.m_wPos.z < two.m_wPos.z;
//}
