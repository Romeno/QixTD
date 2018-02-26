#pragma once


class Entity;


class Component
{
public:
	Component();
	virtual ~Component();

	Entity* GetBoundObject();

	Entity		*m_object;
};

