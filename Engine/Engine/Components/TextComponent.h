#pragma once
#include "Engine/Components/Drawable.h"


class TextComponent : public Drawable
{
public:
	typedef Drawable super;

	enum Positioning {
		CAPTION,
		CENTER,
		TOP_LEFT,
		TOP_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_RIGHT,
		SIZE
	};

	TextComponent();
	virtual ~TextComponent();

	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;
	virtual void Render() override;

	virtual void SetPositioning( Positioning pos ) { m_positioning = pos; }

	std::string			m_text;

	std::string			m_font;
	int					m_fontSize;
	glm::ivec4			m_color;

	glm::dvec3			m_textOFfset;
	Positioning			m_positioning;

	static const int	defaultFontSize; 
};

