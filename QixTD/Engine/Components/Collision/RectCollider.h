#pragma once
#include "Engine/Components/Collision/Collider.h"


class RectCollider : public Collider
{
public:
	RectCollider();
	virtual ~RectCollider();

	glm::dvec3		m_size;
};

