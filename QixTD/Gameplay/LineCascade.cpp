#include "stdafx.h"
#include "LineCascade.h"
#include "Engine/Utils/Utils.h"


LineCascade::LineCascade(const std::string& name)
	: Drawable(name)
	, m_lines()
	, m_color(0, 0, 0, 0)
	, m_borderZ(50)
{

}


LineCascade::~LineCascade()
{

}


//LineCascade::LineCascade(const LineCascade& other)
//	: Drawable(other)
//	, m_lines()
//	, m_color(0, 0, 0, 0)
//	, m_borderZ(50)
//{
//
//}
//
//
//LineCascade& LineCascade::operator=(const LineCascade& other)
//{
//
//
//	return (*this);
//}


void LineCascade::AddLine(glm::dvec3 wPos1, glm::dvec3 wPos2)
{
	m_lines.push_back(Line(glm::dvec3(wPos1.x, wPos1.y, m_borderZ), glm::dvec3(wPos2.x, wPos2.y, m_borderZ)));
}


void LineCascade::NotifyMovement(glm::dvec3 to)
{
	m_lines.back().second = glm::dvec3(to.x, to.y, m_borderZ);
}


int LineCascade::Init()
{
	return Drawable::Init();
}


void LineCascade::Tick(Uint32 diff)
{
	Drawable::Tick(diff);
}


void LineCascade::Render()
{
	SDL_SetRenderDrawColor(REN, m_color.r, m_color.g, m_color.b, m_color.a);

	for (auto it = m_lines.begin(); it != m_lines.end(); it++)
	{
		SDL_RenderDrawLine(REN, W2Sx(it->first.x), W2Sy(it->first.y), W2Sx(it->second.x), W2Sy(it->second.y));
	}
}
