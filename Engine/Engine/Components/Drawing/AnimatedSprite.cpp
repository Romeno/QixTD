#include "stdafx.h"
#include "AnimatedSprite.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Cache/TextureCache.h"


AnimatedSprite::AnimatedSprite()
	: super()
	, m_cadreData()
	, m_cadrePS(60)
	, m_startTime(0)
{

}


AnimatedSprite::~AnimatedSprite()
{

}


int AnimatedSprite::Init()
{
	for ( auto it = m_cadreData.begin(); it != m_cadreData.end(); it++ )
	{
		if ( (*it)->m_path != "" )
		{
			std::string imagePath = GetResourcePath() + (*it)->m_path;

			(*it)->m_texture = TextureCache::Inst()->GetTexture( imagePath );
			if ( !(*it)->m_texture )
			{
				return 1;
			}
		}
	}

	m_startTime = SDL_GetTicks();

	return super::Init();
}


void AnimatedSprite::Tick( Uint32 diff )
{

}


void AnimatedSprite::Render()
{
	if ( m_cadreData.empty() ) 
	{
		return;
	}
	
	Uint32 diff = SDL_GetTicks() - m_startTime;
	size_t cadre = (diff / 1000 * m_cadrePS) % m_cadreData.size();
	Data* d = m_cadreData[cadre];

	SDL_Rect dstrect = {
		W2Sx( m_object->m_real->GetWPos().x ),
		W2Sy( m_object->m_real->GetWPos().y ),
		m_object->m_real->GetSize().x,
		m_object->m_real->GetSize().y
	};

	if ( d->m_texture )
	{
		SDL_RenderCopy( REN, d->m_texture, NULL, &dstrect );
	}
	else
	{
		SDL_SetRenderDrawColor( REN, d->m_color.r, d->m_color.g, d->m_color.b, d->m_color.a );
		SDL_RenderFillRect( REN, &dstrect );
	}
}


void AnimatedSprite::SetColor( const glm::ivec4& color )
{
	for (auto it = m_cadreData.begin(); it != m_cadreData.end(); it++ )
	{
		(*it)->m_color = color;
	}
}


void AnimatedSprite::AddCadre( Data* data )
{
	m_cadreData.push_back( data );
}
