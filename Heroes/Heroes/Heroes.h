#pragma once
#include "Engine/Game.h"
//#include "Heroes/Config/MapConfigStub.h"


class InputHandler;
class HeroesCamera;


class Heroes : public Game
{
public:
	typedef Game super;

	Heroes();
	virtual ~Heroes();


	virtual int Init() override;

	virtual void PreTick( Uint32 diff ) override;
	virtual void Tick( Uint32 diff ) override;
	virtual void PostTick( Uint32 diff ) override;

	virtual void Render() override;

	virtual InputHandler* Input() override;
	virtual Camera* Camera_() override;
	virtual int LoadLevel( int num ) override;

	virtual int LoadArena( );


	//Qix*					m_qixMech;
	//TD*						m_tdMech;

	InputHandler*				m_input;
	HeroesCamera*				m_camera;

	//std::vector<MapConfigStub*>		m_mapConfigs;
	//int 							m_mapNumber;
	//MapConfigStub*					m_currentMap;
	//PlayerConfig*					m_playerConfig;
};

