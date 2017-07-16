#include "stdafx.h"
#include "QixSC.h"
#include "GameManager.h"
#include "QixPC.h"


QixSC::QixSC()
{

}


QixSC::~QixSC()
{

}


void QixSC::Tick(Uint32 diff)
{
	glm::dvec3 pos = PC()->m_sprite->m_wPos;
	m_screenWPos = {
		pos.x + PC()->m_sprite->m_size.x / 2,
		pos.y - PC()->m_sprite->m_size.y / 2,
		0
	};
}
