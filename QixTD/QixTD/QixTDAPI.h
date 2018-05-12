#pragma once
#include "Mechanics/Qix/QixAPI.h"
#include "QixTD/Components/Controlling/QixTDPC.h"


#define API ((QixTDAPI*)(api))
#define HERO (API->qixMech->m_hero)
#define PC ((QixTDPC*)(HERO->m_rozum))


class TickPingPongAI;
class Qix;


class QixTDAPI : public QixAPI
{
public:
	typedef QixAPI super;

	//DECLARE_SINGLETON( QixTDAPI )

	QixTDAPI();
	virtual ~QixTDAPI();

	//void Init( Qix* mech );

	virtual Entity* CreateSprite( const std::string& path, glm::dvec3 wpos, glm::dvec3 size, Direction dir ) override;

	virtual void Play( Entity* e );
	//virtual TickPingPongAI* TickPingPongMonster( Entity* e );

	//Qix*			qixMech;


};









