#include "stdafx.h"
#include "QixCamera.h"
#include "Engine/Utils/Utils.h"
#include "Mechanics/Qix/Qix.h"
#include "Mechanics/Qix/QixAPI.h"


QixCamera::QixCamera()
	: super()
{

}


QixCamera::~QixCamera()
{

}


void QixCamera::Tick(Uint32 diff)
{
	SetWPos( HERO->m_real->GetWPos() );
}
