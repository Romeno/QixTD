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


void UIButton::PreTick( Uint32 diff )
{
	m_beginHovered = false;
	m_endHovered = false;
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

		BeginHoverData* beginHover = m_sensor->BeginHover();
		if ( beginHover->beginHovered )
		{
			OnBeginHover( beginHover );
		}
		delete beginHover;

		EndHoverData* endHover = m_sensor->EndHover();
		if ( endHover->endHovered )
		{
			OnEndHover( endHover );
		}
		delete endHover;

		HoverData* hover = m_sensor->IsHovered();
		if ( hover->hovered )
		{
			OnHover( hover );
		}
		delete hover;

		ClickData* click = m_sensor->WasClicked();
		if ( click->clicked )
		{
			OnClick( click );
		}
		delete click;

		ReleaseData* release = m_sensor->WasReleased();
		if ( release->released )
		{
			OnReleased( release );
		}
		delete release;

		PressData* press = m_sensor->WasPressed();
		if ( press->pressed || m_pressed )
		{
			OnPressed( press );
		}
		delete press;
	}
}


void UIButton::PostTick( Uint32 diff )
{

}


void UIButton::OnFocus( FocusData* focus )
{
	if ( m_onFocusClbck )
	{
		m_onFocusClbck( focus, m_userData );
	}
}


void UIButton::OnBeginHover( BeginHoverData* hover )
{
	ILOGB( "BEGIN HOVERED" );

	m_beginHovered = true;

	if ( m_hoverDrawable )
	{
		m_object->AddComponent( m_hoverDrawable );
	}

	if ( m_onBeginHoverClbck )
	{
		m_onBeginHoverClbck( hover, m_userData );
	}
}


void UIButton::OnHover( HoverData* hover )
{
	ILOGB( "HOVERED" );

	m_hovered = true;

	if ( m_onHoverClbck )
	{
		m_onHoverClbck( hover, m_userData );
	}
}


void UIButton::OnEndHover( EndHoverData* hover )
{
	ILOGB( "END HOVERED" );

	m_endHovered = true;
	m_hovered = false;

	if ( m_standardDrawable )
	{
		m_object->AddComponent( m_standardDrawable );
	}

	if ( m_onEndHoverClbck )
	{
		m_onEndHoverClbck( hover, m_userData );
	}
}


void UIButton::OnPressed( PressData* press )
{
	m_pressed = true;

	if ( m_clickedDrawable )
	{
		m_object->AddComponent( m_clickedDrawable );
	}

	if ( m_onPressedClbck )
	{
		m_onPressedClbck( press, m_userData );
	}
}


void UIButton::OnReleased( ReleaseData* release )
{
	m_pressed = false;

	if ( m_standardDrawable )
	{
		m_object->AddComponent( m_standardDrawable );
	}

	if ( m_onReleasedClbck )
	{
		m_onReleasedClbck(release, m_userData);
	}
}


void UIButton::OnClick( ClickData* click )
{
	m_pressed = false;
	m_clicked = true;

	if ( m_hoverDrawable )
	{
		m_object->AddComponent( m_hoverDrawable );
	}
	else if ( m_standardDrawable )
	{
		m_object->AddComponent( m_standardDrawable );
	}

	if ( m_onClickClbck )
	{
		m_onClickClbck( click, m_userData );
	}

	gameManager->te += "shit";
}


void UIButton::SetOnFocus( OnFocusClbck callback )
{
	m_onFocusClbck = callback;
}


void UIButton::SetOnBeginHover( OnBeginHoverClbck callback )
{
	m_onBeginHoverClbck = callback;
}


void UIButton::SetOnHover( OnHoverClbck callback )
{
	m_onHoverClbck = callback;
}


void UIButton::SetOnEndHover( OnEndHoverClbck callback )
{
	m_onEndHoverClbck = callback;
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
	//SafeDelete( m_ui );

	m_ui = component;
	component->m_object = this;
}