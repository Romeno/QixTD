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
	virtual UIComponent::ClickData* IsClicked() = 0;
	virtual UIComponent::ReleaseData* IsReleased() = 0;

	virtual UIComponent::BeginHoverData* BeginHover() = 0;
	virtual UIComponent::HoverData* IsHovered() = 0;
	virtual UIComponent::EndHoverData* EndHover() = 0;

	virtual UIComponent::FocusData* BeginFocused() = 0;
	virtual UIComponent::FocusData* IsFocused() = 0;
	virtual UIComponent::FocusData* EndFocused() = 0;

	UIComponent* m_boundComponent;
};

