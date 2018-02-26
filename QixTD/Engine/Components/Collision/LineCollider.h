#pragma once
#include "Engine/Components/Collision/Collider.h"


class LineCollider : public Collider
{
public:
	LineCollider(glm::dvec3 p1, glm::dvec3 p2);
	virtual ~LineCollider();

	virtual Collision* TestCollision(Collider* other) = 0;

	glm::dvec3		m_p1;
	glm::dvec3		m_p2;
};
