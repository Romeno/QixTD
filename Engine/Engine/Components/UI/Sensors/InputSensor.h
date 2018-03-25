#pragma once
#include "Engine/Components/UIComponent.h"


// ��� ����� ��������������, ��� ��� �������������� ����� ��� ��������� ���������� (������)
// ��� �����������, ��� ������ ������, ���������� ������������, ��� ������ ����� ���� ������ (� ������� ��� ��� ������ ����)
// � ��.
class InputSensor
{
public:
	InputSensor( UIComponent* c );
	virtual ~InputSensor();

	virtual void Tick( Uint32 diff ) = 0;

	virtual UIComponent::PressData* IsPressed() = 0;

	virtual UIComponent::BeginHoverData* BeginHover() = 0;
	virtual UIComponent::HoverData* IsHovered() = 0;
	virtual UIComponent::EndHoverData* EndHover() = 0;

	virtual UIComponent::FocusData* isFocused() = 0;

	UIComponent* m_boundComponent;
};

