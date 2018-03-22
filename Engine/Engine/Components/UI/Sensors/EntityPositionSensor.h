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

	virtual void SetEntity( Entity* e ) { m_entity = e; }

	virtual UIComponent::PressData* IsPressed() override;
	virtual UIComponent::HoverData* IsHovered() override;

	Entity*	m_entity;
};

