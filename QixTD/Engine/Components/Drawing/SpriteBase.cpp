#include "stdafx.h"
#include "SpriteBase.h"
#include "Engine/Utils/Utils.h"


SpriteBase::Data::Data()
	: m_color( 0, 0, 0, 0 )
	, m_size( 0, 0, 0 )
	, m_offset(0, 0, 0 )
{

}


SpriteBase::Data::~Data()
{

}


SpriteBase::SpriteBase()
	: super()
{

}


SpriteBase::~SpriteBase()
{

}

//
//int SpriteBase::Init()
//{
//	m_data = new Data();
//}
//
//
//void SpriteBase::SetColor( const glm::ivec4& color )
//{
//	m_data->m_color = color;
//}
//
//
