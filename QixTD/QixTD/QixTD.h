#pragma once
#include "Mechanics/Qix/Qix.h"
#include "Engine/Game.h"
#include "QixTDIH.h"
#include "Mechanics/Qix/QixCamera.h"
#include "Mechanics/Qix/Config/MapConfigStub.h"
#include "Mechanics/Qix/Config/PlayerConfig.h"


#define GAME ((QixTD*)(gameManager->m_game))


class b2World;


struct Border
{
	glm::dvec3 first;			// first point
	glm::dvec3 second;			// second point
	bool visible;				// should this border be visible?
	Uint32 completeTickTime;	// when this border was completed 
								// 0 for not completed borders
};


class QixTD : public Game
{
public:
	typedef Game super;

	QixTD();
	virtual ~QixTD();

	virtual int Init() override;
	int InitPhysics();

	virtual void Tick( Uint32 diff ) override;
	virtual void Render() override;

	virtual InputHandler* Input() override;
	virtual Camera* Camera_() override;

	virtual int LoadLevel( int num ) override;

	virtual Entity* GetHero();



	Qix*					m_qixMech;
	//TD*						m_tdMech;

	QixTDIH*				m_input;
	QixCamera*				m_camera;

	std::vector<MapConfigStub*>		m_mapConfigs;
	int 							m_mapNumber;
	MapConfigStub*					m_currentMap;
	PlayerConfig*					m_playerConfig;

	glm::dvec3						m_dir;

	//bool	m_borderInProgress;

	std::vector< Border >	m_borders;
};







