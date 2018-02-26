#include "stdafx.h"
#include "Component.h"
#include "Engine/Entity.h"


Component::Component()
{

}


Component::~Component()
{

}


Entity* Component::GetBoundObject()
{
	return m_object;
}
