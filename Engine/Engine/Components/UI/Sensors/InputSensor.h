#pragma once
#include "Engine/Components/UIComponent.h"


// это класс предполагается, что это второстепенный класс для элементов интерфейса (кнопок)
// для определения, что кнопка нажата, визуальная сигнализация, что кнопка может быть нажата (к примеру над ней курсор мыши)
// и др.
class InputSensor
{
public:
	InputSensor( UIComponent* c );
	virtual ~InputSensor();

	virtual void Tick( Uint32 diff ) = 0;

	virtual UIComponent::FocusData* BeginFocused() = 0;
	virtual UIComponent::FocusData* IsFocused() = 0;
	virtual UIComponent::FocusData* EndFocused() = 0;

	virtual UIComponent::PressData* WasPressed() = 0;
	virtual UIComponent::ReleaseData* WasReleased() = 0;
	virtual UIComponent::ClickData* WasClicked() = 0;

	virtual UIComponent::BeginHoverData* BeginHover() = 0;
	virtual UIComponent::HoverData* IsHovered() = 0;
	virtual UIComponent::EndHoverData* EndHover() = 0;
	
	UIComponent* m_boundComponent;
};

