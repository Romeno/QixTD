#pragma once
#include "Engine/Components/Drawable.h"


class TextComponent : public Drawable
{
public:
	typedef Drawable super;

	enum Positioning 
	{
		POS_CAPTION,
		POS_CENTER,
		POS_TOP_LEFT,
		POS_TOP_RIGHT,
		POS_BOTTOM_LEFT,
		POS_BOTTOM_RIGHT,
		POS_SIZE
	};

	enum XAlignment
	{
		XALIGN_CENTER,
		XALIGN_LEFT,
		XALIGN_RIGHT,
		XALIGN_SIZE
	};

	enum YAlignment
	{
		YALIGN_CENTER,
		YALIGN_TOP,
		YALIGN_BOTTOM,
		YALIGN_SIZE
	};

	struct Alignment 
	{
		XAlignment xal;
		YAlignment yal;
	};

	enum Overflow
	{
		OVERFLOW_SHOW,
		OVERFLOW_HIDDEN,
		OVERFLOW_HIDDEN_X,
		OVERFLOW_HIDDEN_Y,
		OVERFLOW_SIZE
	};

	enum RichText
	{
		RICHTEXT_NONE,
		RICHTEXT_OWN,
		RICHTEXT_MARKDOWN,
		RICHTEXT_HTML,
		RICHTEXT_SIZE
	};

	TextComponent();
	virtual ~TextComponent();

	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;
	virtual void Render() override;

	virtual glm::drect GetVisualAABB() override;
	virtual glm::drect GetSelectionRegion() override;

	virtual void SetPositioning( Positioning pos ) { m_positioning = pos; }
	virtual void SetOverflow( Overflow flow ) { m_overflow = flow; }


	std::string			m_text;

	glm::dvec3			m_textOFfset;			// offset from physical position

	std::string			m_font;
	int					m_fontSize;
	glm::ivec4			m_color;

	Positioning			m_positioning;
	Overflow			m_overflow;
	RichText			m_richText;

	static const int	defaultFontSize; 
	static const std::string defaultFont;

};

