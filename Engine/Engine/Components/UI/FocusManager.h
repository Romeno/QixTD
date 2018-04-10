#pragma once
#include "Engine/Utils/Singleton.h"


class Entity;


class FocusManager
{
public:
	FocusManager();
	virtual ~FocusManager();

	void SetFocus( Entity* e );

	Entity*		m_currentFocus;
	Entity*		m_prevFocus;
};


extern FocusManager* focusManager;