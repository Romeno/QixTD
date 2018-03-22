#pragma once
#include "Engine/Mechanics.h"

//#include "Mechanics/Qix/LineCascade.h"


class Entity;


class Qix : public Mechanics
{
public:
	typedef Mechanics super;

	Qix();
	virtual ~Qix();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Render() override;

	virtual void SetHero( Entity* e );

	Entity*					m_hero;
	std::vector<Entity*>	m_monsters;

	//LineCascade*		m_borderController;
};




