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


UIComponent::BeginHoverData* MouseInputSensor::BeginHover()
{
	return nullptr;
}


UIComponent::HoverData* MouseInputSensor::IsHovered()
{
	UIComponent::HoverData* d = new UIComponent::HoverData();

	//d->hovered = 

	return d;
}


UIComponent::EndHoverData* MouseInputSensor::EndHover()
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
