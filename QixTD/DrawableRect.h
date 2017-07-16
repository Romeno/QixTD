#pragma once
#include "Drawable.h"


class DrawableRect : public Drawable
{
public:
	DrawableRect(const std::string& name, glm::dvec3 size);
	DrawableRect(const DrawableRect& other);
	//DrawableRect(DrawableRect&& other);
	DrawableRect& operator=(const DrawableRect& other);
	virtual ~DrawableRect();

	virtual void SetWPos(glm::dvec3 wPos, Pivot pivot = PIVOT_CENTER) override;

	glm::dvec3 GetRectCenter();

	glm::dvec3      m_size;
};

