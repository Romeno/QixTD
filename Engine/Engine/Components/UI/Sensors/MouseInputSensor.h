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

	struct MouseHoverData : public UIComponent::HoverData
	{
		glm::dvec3	pos;
	};

	MouseInputSensor( UIComponent* c );
	virtual ~MouseInputSensor();

	virtual void Tick( Uint32 diff ) override;

	virtual UIComponent::PressData* IsPressed() override;
	virtual UIComponent::HoverData* IsHovered() override;
	virtual UIComponent::FocusData* isFocused() override;
};

