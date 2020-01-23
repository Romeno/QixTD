#pragma once
#include "Engine/API.h"
//#include "Heroes/Components/Controlling/QixTDPC.h"


#define API ((HeroesAPI*)(api))
//#define PC ((HeroesPC*)(HERO->m_rozum))


class TickPingPongAI;
class Qix;


class HeroesAPI : public Api
{
public:
	typedef Api super;

	//DECLARE_SINGLETON( QixTDAPI )

	HeroesAPI();
	virtual ~HeroesAPI();

	//void Init( Qix* mech );

	//Qix*			qixMech;


};









