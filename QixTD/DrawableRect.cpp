#include "stdafx.h"
#include "DrawableRect.h"
#include "my_math.h"


DrawableRect::DrawableRect(const std::string& name, glm::dvec3 size)
	: Drawable(name)

	, m_size(size)
{

}


DrawableRect::~DrawableRect()
{

}


DrawableRect::DrawableRect(const DrawableRect& other)
	: Drawable(other)

	, m_size(other.m_size)
{

}


DrawableRect& DrawableRect::operator=(const DrawableRect& other)
{
	m_size = other.m_size;

	return (*this);
}


void DrawableRect::SetWPos(glm::dvec3 wPos, Pivot pivot)
{
	if (pivot == PIVOT_CENTER) {
		m_wPos = GetRectTopLeft(wPos, m_size);
	}
	else
	{

	}
}


glm::dvec3 DrawableRect::GetRectCenter()
{
	return ::GetRectCenter(m_wPos, m_size);
}
