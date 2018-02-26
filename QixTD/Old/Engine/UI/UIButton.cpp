#include "stdafx.h"
#include "UIButton.h"
#include "Math/Math.h"
#include "Engine/Utils/Logger.h"


UIButton::UIButton()
	: UIElement()
	, m_onClickCallback(nullptr)
	, m_onPressedCallback(nullptr)
	, m_onReleasedCallback(nullptr)
	, m_onHoverClbck(nullptr)

	, m_pressed(false)

	, m_text("")
	, m_font("fonts/Snap.ttf")
	, m_fontSize(24)

	, m_userData(nullptr)
{

}


UIButton::~UIButton()
{

}


int UIButton::Init()
{
	return 0;
}


void UIButton::Tick(Uint32 diff)
{
	int x = 0, y = 0;
	Uint32 state = SDL_GetMouseState(&x, &y);

	int wx = S2Wx(x), wy = S2Wy(y);
	
	if (IsPointInRect(glm::dvec3(wx, wy, 0), m_wPos, m_size))
	{
		OnHover(wx, wy);

		if (state & SDL_BUTTON(SDL_BUTTON_LEFT))
		{

		}
	}

	//else if (state & SDL_BUTTON(SDL_BUTTON_LEFT))
	//{

	//}
	//else
	//{

	//}
}


void UIButton::Render()
{

}


void UIButton::OnClick()
{

}


void UIButton::OnPressed()
{

}


void UIButton::OnReleased()
{

}


void UIButton::OnHover(double x, double y)
{
	INFO("Hover, pos is %f, %f", x, y);
	if (m_onHoverClbck)
	{
		m_onHoverClbck(x, y, m_userData);
	}
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
	m_text = text;
}


void UIButton::SetUserData(void* data)
{
	m_userData = data;
}

