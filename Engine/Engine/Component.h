#pragma once


class Entity;


class Component
{
public:
	Component();
	virtual ~Component();

	virtual int Init() = 0;

	virtual void PreTick( Uint32 diff );
	virtual void Tick(Uint32 diff) = 0;
	virtual void PostTick( Uint32 diff );

	Entity* GetBoundObject();

	Entity		*m_object;
};

