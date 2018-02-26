#include "stdafx.h"
#include "EntityPositionSensor.h"


EntityPositionSensor::EntityPositionSensor( UIComponent* c )
	: super(c)
{

}


EntityPositionSensor::~EntityPositionSensor()
{

}


UIComponent::PressData* EntityPositionSensor::IsPressed()
{
	return nullptr;
}


UIComponent::HoverData* EntityPositionSensor::IsHovered()
{
	return nullptr;
}
