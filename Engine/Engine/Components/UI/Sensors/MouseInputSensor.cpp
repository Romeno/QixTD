#include "stdafx.h"
#include "MouseInputSensor.h"
#include "Engine/Components/UIComponent.h"
#include "Engine/Input/Mouse.h"
#include "Math/Math.h"
#include "Engine/Entity.h"
#include "Engine/Components/Drawable.h"
#include "Engine/Utils/Utils.h"


MouseInputSensor::MouseInputSensor(UIComponent* c)
	: super(c)
{

}


MouseInputSensor::~MouseInputSensor()
{

}


void MouseInputSensor::Tick( Uint32 diff )
{

}


UIComponent::PressData* MouseInputSensor::IsPressed()
{
	UIComponent::PressData* d = new UIComponent::PressData();

	//bool onButton = IsPointInRect( Mouse::Inst()->GetPos(), W2R( m_boundComponent->m_object->m_real->GetPos() ), m_boundComponent->m_object->m_real->GetSize() );
	//if ( onButton )
	//{
	//	Mouse::Inst()->m_
	//}

	return d;
}


UIComponent::ClickData* MouseInputSensor::IsClicked()
{
	UIComponent::ClickData* d = new UIComponent::ClickData();

	return d;
}


UIComponent::ReleaseData* MouseInputSensor::IsReleased()
{
	UIComponent::ReleaseData* d = new UIComponent::ReleaseData();

	return d;
}


UIComponent::BeginHoverData* MouseInputSensor::BeginHover()
{
	UIComponent::BeginHoverData* d = new UIComponent::BeginHoverData();

	return d;
}


UIComponent::HoverData* MouseInputSensor::IsHovered()
{
	MouseHoverData* d = new MouseHoverData();

	glm::drect rect = m_boundComponent->m_object->m_malui->GetSelectionRegion();
	d->hovered = rect.ContainsPoint( mouse->GetPos() );
	d->pos = mouse->GetPos();

	//INFO( "RECT: %f, %f, %f, %f", rect.m_topLeft.x, rect.m_topLeft.y, rect.m_size.x, rect.m_size.y );

	return d;
}


UIComponent::EndHoverData* MouseInputSensor::EndHover()
{
	UIComponent::EndHoverData* d = new UIComponent::EndHoverData();

	return d;
}


UIComponent::FocusData* MouseInputSensor::BeginFocused()
{
	UIComponent::FocusData* d = new UIComponent::FocusData();

	return d;
}


UIComponent::FocusData* MouseInputSensor::IsFocused()
{
	UIComponent::FocusData* d = new UIComponent::FocusData();

	//ReleaseData* d = IsReleased();

	//FocusData* f = new FocusData();
	//f->focused = 

	return d;
}


UIComponent::FocusData* MouseInputSensor::EndFocused()
{
	UIComponent::FocusData* d = new UIComponent::FocusData();

	return d;
}
