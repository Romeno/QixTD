#pragma once
#include "Engine/Components/UI/Sensors/InputSensor.h"


class Entity;


// ������ ��� ������� ����� ��������, 
// ���� � ������� ������ ��� ������ ������������ ��������� �� ������ ��� ������� �������
class EntityPositionSensor : public InputSensor
{
public:
	typedef InputSensor super;

	EntityPositionSensor( UIComponent* c );
	virtual ~EntityPositionSensor();

	virtual void Tick( Uint32 diff ) override;

	virtual void SetEntity( Entity* e ) { m_entity = e; }

	virtual UIComponent::PressData* IsPressed() override;
	virtual UIComponent::ReleaseData* IsReleased() override;
	virtual UIComponent::ClickData* IsClicked() override;

	virtual UIComponent::FocusData* BeginFocused() override;
	virtual UIComponent::FocusData* IsFocused() override;
	virtual UIComponent::FocusData* EndFocused() override;

	virtual UIComponent::BeginHoverData* BeginHover() override;
	virtual UIComponent::HoverData* IsHovered() override;
	virtual UIComponent::EndHoverData* EndHover() override;

	Entity*	m_entity;

};

