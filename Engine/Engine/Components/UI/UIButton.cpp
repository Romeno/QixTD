#include "stdafx.h"
#include "UIButton.h"
#include "Math/Math.h"
#include "Engine/Utils/Utils.h"

#include "Engine/Components/UI/Sensors/MouseInputSensor.h"
#include "Engine/Components/UI/Sensors/EntityPositionSensor.h"


UIButton::UIButton()
	: super()
	, m_onClickClbck(nullptr)
	, m_onPressedClbck(nullptr)
	, m_onReleasedClbck(nullptr)
	, m_onHoverClbck(nullptr)

	, m_sensor(nullptr)

	, m_pressed(false)

	, m_userData(nullptr)

	, m_clickArea()
{

}


UIButton::~UIButton()
{
	del( m_sensor );
}


int UIButton::Init()
{
	return 0;
}


void UIButton::Tick(Uint32 diff)
{
	if ( m_sensor )
	{
		m_sensor->Tick(diff);

		FocusData* focus = m_sensor->IsFocused();
		if ( focus->focused )
		{
			OnFocus( focus );
		}
		delete focus;

		HoverData* hover = m_sensor->IsHovered();
		if ( hover->hovered )
		{
			OnHover( hover );
		}
		delete hover;

		PressData* press = m_sensor->IsPressed();
		if ( press->pressed )
		{
			OnPressed(press);
		}
		delete press;

		ReleaseData* release = m_sensor->IsReleased();
		if ( release->released )
		{
			OnReleased( release );
		}
		delete release;

		ClickData* click = m_sensor->IsClicked();
		if ( click->clicked )
		{
			OnClick( click );
		}
		delete click;
	}
}


void UIButton::OnFocus( FocusData* focus )
{
	if ( m_onFocusClbck )
	{
		m_onFocusClbck( focus, m_userData );
	}
}


void UIButton::OnHover( HoverData* hover )
{
	INFO( "HOVERED" );

	if ( m_onHoverClbck )
	{
		m_onHoverClbck( hover, m_userData );
	}

	//MouseInputSensor::MouseHoverData* mouseClick = dynamic_cast<MouseInputSensor::MouseHoverData*>(hover);
	//if ( mouseClick )
	//{
	//	INFO( "Hover, pos is %f, %f", mouseClick->pos.x, mouseClick->pos.y );
	//}

	//if (m_onHoverClbck)
	//{
	//	m_onHoverClbck(x, y, m_userData);
	//}
}


void UIButton::OnPressed( PressData* press )
{
	if ( m_onPressedClbck )
	{
		m_onPressedClbck( press, m_userData );
	}
}


void UIButton::OnReleased( ReleaseData* release )
{
	if ( m_onReleasedClbck )
	{
		m_onReleasedClbck(release, m_userData);
	}
}


void UIButton::OnClick( ClickData* click )
{
	if ( m_onClickClbck )
	{
		m_onClickClbck( click, m_userData );
	}
}


void UIButton::SetOnFocus( OnFocusClbck callback )
{
	m_onFocusClbck = callback;
}


void UIButton::SetOnHover( OnHoverClbck callback )
{
	m_onHoverClbck = callback;
}


void UIButton::SetOnPressed(OnPressedClbck callback)
{
	m_onPressedClbck = callback;
}


void UIButton::SetOnReleased(OnReleasedClbck callback)
{
	m_onReleasedClbck = callback;
}


void UIButton::SetOnClick( OnClickClbck callback )
{
	m_onClickClbck = callback;
}


void UIButton::SetText(const std::string& text)
{
	//m_nadpis = text;
}


void UIButton::SetUserData(void* data)
{
	m_userData = data;
}


//void UIButton::SetClickSize( glm::dvec3 size )
//{
//
//}


template <>
void Entity::AddComponent( UIButton* component )
{
	m_ui = component;
	component->m_object = this;
}