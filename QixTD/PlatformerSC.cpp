#include "stdafx.h"
#include "Defines.h"

#ifdef PLATFORMER_GAME_TYPE

#include "PlatformerSC.h"
#include "GameManager.h"
#include "PC.h"


PlatformerSC::PlatformerSC()
{

}


PlatformerSC::~PlatformerSC()
{

}


void PlatformerSC::Tick(Uint32 diff)
{
	glm::dvec3 pos = PC()->GetWPos();
	m_screenWPos = {
		pos.x + PC()->m_imageWidth / 2,
		pos.y - PC()->m_imageHeight / 2,
		0
	};

	//m_screenWPos = {
	//	pos.x - GameManager::Inst()->vpWidth / 2 + PC()->m_imageWidth / 2,
	//	pos.y - GameManager::Inst()->vpHeight / 2 - PC()->m_imageHeight / 2,
	//	0
	//};
}

#endif