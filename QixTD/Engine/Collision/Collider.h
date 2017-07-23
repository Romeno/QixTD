#pragma once


class Collision;


class Collider
{
public:
	Collider();
	virtual ~Collider();

	Collision*		TestCollision(Collider* other);
};

