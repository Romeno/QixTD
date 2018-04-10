#include "stdafx.h"
#include "TextComponent.h"
#include "Engine/API.h"
#include "Engine/Entity.h"
#include "Math/Math.h"


const int TextComponent::defaultFontSize = 10;


TextComponent::TextComponent()
	: super()

	, m_text( "" )

	, m_font( "" )
	, m_fontSize( defaultFontSize )

	, m_textOFfset()
	, m_positioning( POS_CAPTION )
{
	
}


TextComponent::~TextComponent()
{

}


int TextComponent::Init()
{
	return super::Init();
}


void TextComponent::Tick( Uint32 diff )
{

}


void TextComponent::Render()
{
	glm::dvec3 pos;
	glm::dvec3 size;

	if ( m_positioning == POS_CAPTION ) 
	{
		pos = GetBoundObject()->m_malui->GetVisualAABB().GetTopMiddle();
	}
	else if ( m_positioning == POS_CENTER )
	{
		pos = GetBoundObject()->m_malui->GetVisualAABB().GetCenter();
	}
	else if ( m_positioning == POS_TOP_LEFT )
	{
		pos = GetBoundObject()->m_malui->GetVisualAABB().GetTopLeft();
	}
	else if ( m_positioning == POS_TOP_RIGHT )
	{
		pos = GetBoundObject()->m_malui->GetVisualAABB().GetTopRight();
	}
	else if ( m_positioning == POS_BOTTOM_LEFT )
	{
		pos = GetBoundObject()->m_malui->GetVisualAABB().GetBottomLeft();
	}
	else if ( m_positioning == POS_BOTTOM_RIGHT )
	{
		pos = GetBoundObject()->m_malui->GetVisualAABB().GetBottomRight();
	}
	else
	{
		ERROR( "Unknown TextComponent positioning %d", (int) m_positioning );
	}

	api->DrawTextBlock( pos, size, m_font, m_text, m_fontSize, { (Uint8) m_color.r, (Uint8) m_color.g, (Uint8) m_color.b, (Uint8) m_color.a } );
}
