#pragma once
#include "Engine/Components/UI/Sensors/InputSensor.h"


// ������ ��� ����, ������� ����� ����� ������� ������������
class MouseInputSensor : public InputSensor
{
public:
	typedef InputSensor super;

	struct MouseClickData : public UIComponent::ClickData
	{
		glm::dvec3	pos;
		int			button;
	};

	struct MousePressData : public UIComponent::PressData
	{
		glm::dvec3	pos;
		int			button;
	};

	struct MouseReleaseData : public UIComponent::ReleaseData
	{
		glm::dvec3	pos;
		int			button;
	};

	struct MouseBeginHoverData : public UIComponent::BeginHoverData
	{
		glm::dvec3	pos;
	};

	struct MouseHoverData : public UIComponent::HoverData
	{
		glm::dvec3	pos;
	};

	struct MouseEndHoverData : public UIComponent::EndHoverData
	{
		glm::dvec3	pos;
	};

	struct FocusData : public UIComponent::FocusData
	{
		UIComponent*	m_prevFocus;
		UIComponent*	m_currentFocus;
	};

	MouseInputSensor( UIComponent* c );
	virtual ~MouseInputSensor();

	virtual void Tick( Uint32 diff ) override;


	virtual UIComponent::FocusData* BeginFocused() override;
	virtual UIComponent::FocusData* IsFocused() override;
	virtual UIComponent::FocusData* EndFocused() override;

	virtual UIComponent::BeginHoverData* BeginHover() override;
	virtual UIComponent::HoverData* IsHovered() override;
	virtual UIComponent::EndHoverData* EndHover() override;

	virtual UIComponent::PressData* WasPressed() override;
	virtual UIComponent::ReleaseData* WasReleased() override;
	virtual UIComponent::ClickData* WasClicked() override;
};

