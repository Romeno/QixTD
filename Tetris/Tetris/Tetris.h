#pragma once
#include "Mechanics/Qix/Qix.h"
#include "Engine/Game.h"
#include "Mechanics/Qix/QixIH.h"
#include "Mechanics/Qix/QixCamera.h"
#include "Mechanics/Qix/Config/MapConfigStub.h"


#define GAME ((QixTD*)(GameManager::Inst()->m_game))


class b2World;


class Tetris : public Game
{
public:
	typedef Game super;

	Tetris();
	virtual ~Tetris();

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

	QixIH*					m_input;
	QixCamera*				m_camera;

	std::vector<MapConfigStub*>		m_mapConfigs;
	int 							m_mapNumber;
	MapConfigStub*					m_currentMap;
};