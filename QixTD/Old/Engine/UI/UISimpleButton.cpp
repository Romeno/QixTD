#include "stdafx.h"
#include "UISimpleButton.h"

#include "Engine/GameManager.h"
#include "Engine/Utils/EngiUtils.h"
#include "Engine/Utils/Uncategorized.h"


UISimpleButton::UISimpleButton(const std::string& name, glm::dvec3 size, glm::ivec4& color)
	: UIButton(name, size)

	, m_color(color)
	, m_pressedColor(color)
{

}


UISimpleButton::~UISimpleButton()
{

}


void UISimpleButton::Render()
{
	SDL_Rect rect = ToSDLRect(m_wPos, m_size);

	SDL_SetRenderDrawColor(REN, m_color.r, m_color.g, m_color.b, m_color.a);

	SDL_RenderDrawRect(REN, &rect);

	DrawTextBlock(m_font, m_text, m_fontSize);

	//for (auto it = m_lines.begin(); it != m_lines.end(); it++)
	//{
	//	SDL_RenderDrawLine(REN, W2Sx(it->first.x), W2Sy(it->first.y), W2Sx(it->second.x), W2Sy(it->second.y));
	//}
}
