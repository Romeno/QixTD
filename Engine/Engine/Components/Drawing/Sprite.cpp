#include "stdafx.h"
#include "Sprite.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Cache/TextureCache.h"





Sprite::Sprite()
	: super()

	, m_data(new Data())
{
	
}


Sprite::~Sprite()
{

}


int Sprite::Init()
{
	Data* d = m_data;

	if ( d->m_path != "" )
	{
		std::string imagePath = GetResourcePath() + d->m_path;

		d->m_texture = TextureCache::Inst()->GetTexture( imagePath );
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
	Data* d = (Data*) m_data;

	glm::dvec3 topLeft = m_object->m_real->GetWPos();
	topLeft = GetRectTopLeft( topLeft, m_object->m_real->GetSize() );

	SDL_Rect dstrect = {
		W2Sx( topLeft.x ),
		W2Sy( topLeft.y ),
		m_object->m_real->GetSize().x,
		m_object->m_real->GetSize().y
	};

	if (d->m_texture)
	{
		SDL_RenderCopy(REN, d->m_texture, NULL, &dstrect);
	}
	else
	{
		SDL_SetRenderDrawColor(REN, d->m_color.r, d->m_color.g, d->m_color.b, d->m_color.a);
		SDL_RenderFillRect(REN, &dstrect);
	}
}


void Sprite::SetImage(const std::string& spriteData)
{
	Data* d = (Data*) m_data;

	d->m_path = spriteData;
}


void Sprite::SetColor( const glm::ivec4& color )
{
	Data* d = (Data*) m_data;

	d->m_color = color;
}


glm::drect Sprite::GetVisualAABB()
{
	glm::drect r = { GetBoundObject()->m_real->GetWPos() + m_data->m_offset, m_data->m_size };

	return r;
}


template <>
void Entity::AddComponent( Sprite* component )
{
	m_malui = component;
	component->m_object = this;
}