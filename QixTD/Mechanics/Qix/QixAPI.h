#pragma once
#include "Engine/API.h"


#define api ((QixAPI*)(QixAPI::Inst()))
#define HERO (QixAPI::Inst()->qixMech->m_hero)
#define PC ((QixPC*)(HERO->m_rozum))


class TickPingPongAI;
class Qix;


class QixAPI : public API
{
public:
	typedef API super;

	DECLARE_SINGLETON( QixAPI )

	QixAPI();
	virtual ~QixAPI();

	void Init( Qix* mech );

	virtual void Play( Entity* e );
	virtual TickPingPongAI* TickPingPongMonster( Entity* e );

	Qix*			qixMech;
};









