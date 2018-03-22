#pragma once
#include "Engine/Components/Drawing/Sprite.h"


class AnimatedSprite : public SpriteBase
{
public:
	typedef SpriteBase super;

	class Data : public Sprite::Data
	{

	};

	AnimatedSprite();
	virtual ~AnimatedSprite();

	virtual void SetColor( const glm::ivec4& color ) override;
	virtual void AddCadre( Data* data );

	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;
	virtual void Render() override;

	std::vector<Data*>	m_cadreData;
	Uint32				m_cadrePS;	// animation speed - cadre per second
	Uint32				m_startTime;
};

