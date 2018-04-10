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


UIComponent::ClickData* EntityPositionSensor::IsClicked()
{
	return nullptr;
}


UIComponent::ReleaseData* EntityPositionSensor::IsReleased()
{
	return nullptr;
}


UIComponent::FocusData* EntityPositionSensor::BeginFocused()
{
	return nullptr;
}


UIComponent::FocusData* EntityPositionSensor::EndFocused()
{
	return nullptr;
}


UIComponent::FocusData* EntityPositionSensor::IsFocused()
{
	return nullptr;
}
