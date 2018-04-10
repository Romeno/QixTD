#pragma once
#include "Mechanics/Qix/Qix.h"
#include "Engine/Game.h"
#include "QixTDIH.h"
#include "Mechanics/Qix/QixCamera.h"
#include "Mechanics/Qix/Config/MapConfigStub.h"


#define GAME ((QixTD*)(gameManager->m_game))


class b2World;


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

	glm::dvec3						m_dir;

	std::vector< std::pair<glm::dvec3, glm::dvec3> >	m_borders;
};







