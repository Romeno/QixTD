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


void EntityPositionSensor::Tick( Uint32 diff )
{
	
}


UIComponent::BeginHoverData* EntityPositionSensor::BeginHover()
{
	return nullptr;
}


UIComponent::EndHoverData* EntityPositionSensor::EndHover()
{
	return nullptr;
}


UIComponent::FocusData* EntityPositionSensor::isFocused()
{
	return nullptr;
}
