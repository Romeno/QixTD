#pragma once
#include "Engine/API.h"


#define API ((QixAPI*)(api))
#define HERO (API->qixMech->m_hero)
#define PC ((QixPC*)(HERO->m_rozum))


class TickPingPongAI;
class Qix;


class QixAPI : public Api
{
public:
	typedef Api super;

	//DECLARE_SINGLETON( QixAPI )

	QixAPI();
	virtual ~QixAPI();

	void Init( Qix* mech );

	virtual void Play( Entity* e );
	virtual TickPingPongAI* TickPingPongMonster( Entity* e );

	Qix*			qixMech;
};









