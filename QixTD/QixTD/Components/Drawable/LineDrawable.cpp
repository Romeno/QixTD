#include "stdafx.h"
#include "LineDrawable.h"
#include "QixTD/QixTD.h"
#include "Engine/Utils/Utils.h"


LineDrawable::LineDrawable()
{

}


LineDrawable::~LineDrawable()
{

}


int LineDrawable::Init()
{
	return super::Init();
}


void LineDrawable::Tick( Uint32 diff )
{

}


void LineDrawable::Render()
{
	SDL_SetRenderDrawColor( REN, 0, 0, 0, 0);

	for ( auto l : GAME->m_borders )
	{
		SDL_RenderDrawLine( REN, W2Sx( l.first.x ), W2Sy( l.first.y ), W2Sx( l.second.x ), W2Sy( l.second.y ) );
	}
}


glm::drect LineDrawable::GetVisualAABB()
{
	return { {0,0,0}, {0,0,0} };
}


glm::drect LineDrawable::GetSelectionRegion()
{
	return glm::drect();
}


template <>
void Entity::AddComponent( LineDrawable* component )
{
	m_malui = component;
	component->m_object = this;
}