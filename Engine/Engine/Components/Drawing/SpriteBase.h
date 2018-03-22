#pragma once
#include "Engine/Components/Drawable.h"


class SpriteBase : public Drawable
{
public:
	typedef Drawable super;

	class Data
	{
	public:
		Data();
		~Data();

		glm::ivec4			m_color;

		glm::dvec3			m_size;

		glm::dvec3			m_offset;
	};

	SpriteBase();
	virtual ~SpriteBase();

	virtual void SetColor( const glm::ivec4& color ) = 0;
};

