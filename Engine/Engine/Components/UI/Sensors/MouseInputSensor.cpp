#include "stdafx.h"
#include "MouseInputSensor.h"


MouseInputSensor::MouseInputSensor(UIComponent* c)
	: super(c)
{

}


MouseInputSensor::~MouseInputSensor()
{

}


UIComponent::PressData* MouseInputSensor::IsPressed()
{
	return nullptr;
}


UIComponent::HoverData* MouseInputSensor::IsHovered()
{
	return nullptr;
}


UIComponent::FocusData* MouseInputSensor::isFocused()
{
	return nullptr;
}


void MouseInputSensor::Tick( Uint32 diff )
{

}
