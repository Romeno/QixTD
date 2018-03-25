#include "stdafx.h"
#include "UIButton.h"
#include "Math/Math.h"
#include "Engine/Utils/Utils.h"

#include "Engine/Components/UI/Sensors/MouseInputSensor.h"
#include "Engine/Components/UI/Sensors/EntityPositionSensor.h"


UIButton::UIButton()
	: super()
	, m_onClickCallback(nullptr)
	, m_onPressedCallback(nullptr)
	, m_onReleasedCallback(nullptr)
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
		HoverData* hover = m_sensor->IsHovered();
		if ( hover->hovered )
		{
			OnHover( hover );
		}

		if ( m_sensor->IsPressed() )
		{
			//OnPressed()
		}
	}

	int x = 0, y = 0;
	Uint32 state = SDL_GetMouseState(&x, &y);

	int wx = S2Wx(x), wy = S2Wy(y);
	
	//if (IsPointInRect(glm::dvec3(wx, wy, 0), m_wPos, m_size))
	//{
	//	OnHover(wx, wy);

	//	if (state & SDL_BUTTON(SDL_BUTTON_LEFT))
	//	{

	//	}
	//}

	//else if (state & SDL_BUTTON(SDL_BUTTON_LEFT))
	//{

	//}
	//else
	//{

	//}
}


void UIButton::OnClick(ClickData* click)
{

}


void UIButton::OnPressed( PressData* press )
{

}


void UIButton::OnReleased( ReleaseData* release )
{

}


void UIButton::OnHover( HoverData* hover )
{
	MouseInputSensor::MouseHoverData* mouseClick = dynamic_cast<MouseInputSensor::MouseHoverData*>(hover);
	if ( mouseClick ) 
	{
		INFO( "Hover, pos is %f, %f", mouseClick->pos.x, mouseClick->pos.y );
	}

	//if (m_onHoverClbck)
	//{
	//	m_onHoverClbck(x, y, m_userData);
	//}
}


void UIButton::SetOnClick(OnClickClbck callback)
{

}


void UIButton::SetOnPressed(OnPressedClbck callback)
{

}


void UIButton::SetOnReleased(OnReleasedClbck callback)
{

}


void UIButton::SetOnHover(OnHoverClbck callback)
{

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