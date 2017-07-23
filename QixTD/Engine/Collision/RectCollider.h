#pragma once
#include "Engine/Collision/Collider.h"


class RectCollider : public Collider
{
public:
	RectCollider();
	virtual ~RectCollider();

	glm::dvec3		m_size;
};

