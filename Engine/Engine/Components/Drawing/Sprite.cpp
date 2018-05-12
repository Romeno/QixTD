#include "stdafx.h"
#include "Sprite.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Cache/TextureCache.h"





Sprite::Sprite()
	: super()

	, m_originalData( new Data() )
	, m_data( new Data() )
{
	
}


Sprite::~Sprite()
{

}


int Sprite::Init()
{
	Data* d = m_originalData;

	if ( d->m_path != "" )
	{
		std::string imagePath = GetResourcePath() + d->m_path;

		d->m_texture = textureCache->GetTexture( imagePath );
		if ( !d->m_texture )
		{
			return 1;
		}
	}

	return super::Init();
}


void Sprite::Tick(Uint32 diff)
{
	super::Tick(diff);
}


void Sprite::Render()
{
	Data* d = (Data*) m_originalData;

	glm::dvec3 pos = m_object->m_real->GetPos();
	pos = GetRectTopLeft( pos, m_object->m_real->GetSize() );

	SDL_Rect dstrect;
	if ( m_object->m_real->IsAbsolutePosition() )
	{
		dstrect = {
			R2Sx( pos.x ),
			R2Sy( pos.y ),
			(int) m_object->m_real->GetSize().x,
			(int) m_object->m_real->GetSize().y
		};
	}
	else
	{
		dstrect = {
			W2Sx( pos.x ),
			W2Sy( pos.y ),
			(int) m_object->m_real->GetSize().x,
			(int) m_object->m_real->GetSize().y
		};
	}

	if (d->m_texture)
	{
		if ( prev_pos != pos )
		{
			ILOGBM( MODULE_RENDER, "pos: %f, %f", (float) W2Sx( pos.x ), (float) W2Sy( pos.y ) );
		}

		SDL_RenderCopy(REN, d->m_texture, NULL, &dstrect);
	}
	else
	{
		SDL_SetRenderDrawColor(REN, d->m_color.r, d->m_color.g, d->m_color.b, d->m_color.a);
		SDL_RenderFillRect(REN, &dstrect);
	}

	prev_pos = pos;
}


void Sprite::SetImage(const std::string& spriteData)
{
	Data* d = (Data*) m_originalData;

	d->m_path = spriteData;
}


void Sprite::SetColor( const glm::ivec4& color )
{
	Data* d = (Data*) m_originalData;

	d->m_color = color;
}


glm::drect Sprite::GetVisualAABB()
{
	glm::drect r = { GetRectTopLeft( GetBoundObject()->m_real->GetPos() + m_originalData->m_offset, m_originalData->m_visualSize), m_originalData->m_visualSize };

	return r;
}


glm::drect Sprite::GetSelectionRegion()
{
	glm::drect r = { GetRectTopLeft( GetBoundObject()->m_real->GetPos() + m_originalData->m_offset, m_originalData->m_visualSize ), m_originalData->m_visualSize };

	return r;
}


template <>
void Entity::AddComponent( Sprite* component )
{
	//SafeDelete( m_malui );

	m_malui = component;
	component->m_object = this;
}