#pragma once
#include "Engine/Components/UI/Sensors/InputSensor.h"


// сенсор для мыши, нажатия могут любой кнопкой потенциально
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

	struct MouseHoverData : public UIComponent::HoverData
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

	virtual UIComponent::PressData* IsPressed() override;
	virtual UIComponent::ClickData* IsClicked() override;
	virtual UIComponent::ReleaseData* IsReleased() override;

	virtual UIComponent::BeginHoverData* BeginHover() override;
	virtual UIComponent::HoverData* IsHovered() override;
	virtual UIComponent::EndHoverData* EndHover() override;

	virtual UIComponent::FocusData* BeginFocused() override;
	virtual UIComponent::FocusData* IsFocused() override;
	virtual UIComponent::FocusData* EndFocused() override;
};

