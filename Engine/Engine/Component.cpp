#include "stdafx.h"
#include "Component.h"
#include "Engine/Entity.h"


Component::Component()
	: m_object(nullptr)
{

}


Component::~Component()
{

}


int Component::Init()
{
	return 0;
}


void Component::Tick(Uint32 diff)
{

}


Entity* Component::GetBoundObject()
{
	return m_object;
}
