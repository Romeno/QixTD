#include "stdafx.h"
#include "DrawableController.h"


DrawableController::DrawableController(const std::string& name)
	: Entity(name)

	, m_drawable(nullptr)
{

}


DrawableController::~DrawableController()
{

}


void DrawableController::Possess(DrawableRect * d)
{
	m_drawable = d;
}


int DrawableController::Init()
{
	return Entity::Init();
}


void DrawableController::Tick(Uint32 diff)
{
	Entity::Tick();
}

