#include "stdafx.h"
#include "AIController.h"


AIController::AIController(const std::string& name)
	: DrawableController(name)
{

}


AIController::~AIController()
{

}


int AIController::Init()
{
	return DrawableController::Init();
}


void AIController::Tick(Uint32 diff)
{
	DrawableController::Tick();
}

