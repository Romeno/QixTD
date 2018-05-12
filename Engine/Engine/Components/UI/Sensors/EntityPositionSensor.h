#pragma once
#include "Engine/Components/UI/Sensors/InputSensor.h"


class Entity;


// сенсор для позиции некой сущности, 
// идея в нажатии кнопки при помощи передивжения персонажа на кнопку или другого объекта
class EntityPositionSensor : public InputSensor
{
public:
	typedef InputSensor super;

	EntityPositionSensor( UIComponent* c );
	virtual ~EntityPositionSensor();

	virtual void Tick( Uint32 diff ) override;

	virtual void SetEntity( Entity* e ) { m_entity = e; }

	virtual UIComponent::FocusData* BeginFocused() override;
	virtual UIComponent::FocusData* IsFocused() override;
	virtual UIComponent::FocusData* EndFocused() override;

	virtual UIComponent::BeginHoverData* BeginHover() override;
	virtual UIComponent::HoverData* IsHovered() override;
	virtual UIComponent::EndHoverData* EndHover() override;

	virtual UIComponent::PressData* WasPressed() override;
	virtual UIComponent::ReleaseData* WasReleased() override;
	virtual UIComponent::ClickData* WasClicked() override;

	Entity*	m_entity;

};

