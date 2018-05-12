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


UIComponent::BeginHoverData* MouseInputSensor::BeginHover()
{
	MouseBeginHoverData* d = new MouseBeginHoverData();

	glm::drect rect = m_boundComponent->m_object->m_malui->GetSelectionRegion();
	d->beginHovered = rect.ContainsPoint( mouse->GetPos() ) && !m_boundComponent->m_object->m_ui->m_hovered;
	d->pos = mouse->GetPos();

	return d;
}


UIComponent::HoverData* MouseInputSensor::IsHovered()
{
	MouseHoverData* d = new MouseHoverData();

	glm::drect rect = m_boundComponent->m_object->m_malui->GetSelectionRegion();
	d->hovered = rect.ContainsPoint( mouse->GetPos() );
	d->pos = mouse->GetPos();

	//ILOGBM( MODULE_MOUSE "RECT: %f, %f, %f, %f", rect.m_topLeft.x, rect.m_topLeft.y, rect.m_size.x, rect.m_size.y );

	return d;
}


UIComponent::EndHoverData* MouseInputSensor::EndHover()
{
	MouseEndHoverData* d = new MouseEndHoverData();

	glm::drect rect = m_boundComponent->m_object->m_malui->GetSelectionRegion();
	d->endHovered = !rect.ContainsPoint( mouse->GetPos() ) && m_boundComponent->m_object->m_ui->m_hovered;
	d->pos = mouse->GetPos();

	return d;
}


UIComponent::PressData* MouseInputSensor::WasPressed()
{
	MousePressData* d = new MousePressData();

	glm::drect rect = m_boundComponent->m_object->m_malui->GetSelectionRegion();
	d->pressed = rect.ContainsPoint( mouse->GetPos() ) && mouse->m_lmbPressed;
	d->button = SDL_BUTTON_LEFT;
	d->pos = mouse->GetPos();

	return d;
}


UIComponent::ReleaseData* MouseInputSensor::WasReleased()
{
	MouseReleaseData* d = new MouseReleaseData();

	glm::drect rect = m_boundComponent->m_object->m_malui->GetSelectionRegion();
	d->released = !rect.ContainsPoint( mouse->GetPos() ) && mouse->m_lmbClick && m_boundComponent->m_pressed;
	d->button = SDL_BUTTON_LEFT;
	d->pos = mouse->GetPos();

	return d;
}


UIComponent::ClickData* MouseInputSensor::WasClicked()
{
	MouseClickData* d = new MouseClickData();

	glm::drect rect = m_boundComponent->m_object->m_malui->GetSelectionRegion();
	d->clicked = rect.ContainsPoint( mouse->GetPos() ) && mouse->m_lmbClick && m_boundComponent->m_pressed;
	d->button = SDL_BUTTON_LEFT;
	d->pos = mouse->GetPos();

	return d;
}
