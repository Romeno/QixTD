#pragma once


class Entity;


class Component
{
public:
	Component();
	virtual ~Component();

	virtual int Init() = 0;

	virtual void Tick(Uint32 diff) = 0;

	Entity* GetBoundObject();

	Entity		*m_object;
};

