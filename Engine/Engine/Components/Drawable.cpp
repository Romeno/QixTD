#include "stdafx.h"
#include "Drawable.h"
#include "Engine/GameManager.h"


Drawable::Drawable()
	: super()
{

}


Drawable::Drawable(const Drawable& other)
	: super(other)
{

}


Drawable& Drawable::operator=(const Drawable& other)
{
	return (*this);
}


Drawable::~Drawable()
{

}


int Drawable::Init()
{
	return 0;
}


void Drawable::Tick(Uint32 diff)
{

}