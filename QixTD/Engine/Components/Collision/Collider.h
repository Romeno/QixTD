#pragma once


class Collision;
class Drawable;


class Collider
{
public:
	Collider();
	virtual ~Collider();

	virtual Collision* TestCollision(Collider* other) = 0;
	virtual bool HitTest(glm::dvec3 pos) = 0;

	Drawable*	m_drawable;
};

