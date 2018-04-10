#include "stdafx.h"
#include "FocusManager.h"
#include "Engine/Entity.h"


extern FocusManager* focusManager = nullptr;


FocusManager::FocusManager()
{

}


FocusManager::~FocusManager()
{

}


void FocusManager::SetFocus( Entity* e )
{
	m_prevFocus = m_currentFocus;
	m_currentFocus = e;
}
