#include "stdafx.h"
#include "FolderAnimation.h"
#include "Engine/Utils/Utils.h"


namespace fs = std::experimental::filesystem::v1;


FolderAnimation::FolderAnimation()
	: super()

	, m_folderPath("")
{

}


FolderAnimation::~FolderAnimation()
{

}


void FolderAnimation::LoadFolder( const std::string& path )
{
	for ( fs::directory_iterator it( path ), end; it != end; ++it )
	{
		SDL_Surface* s = IMG_Load( Wstr2Str( std::wstring(it->path().c_str()) ).c_str() );
		if ( s )
		{
			Data* d = new Data();
			d->m_size = glm::dvec3( s->w, s->h, 0 );
			d->m_path = Wstr2Str( std::wstring( it->path().c_str() ) );
			d->m_offset = glm::dvec3();
			d->m_color = glm::ivec4(0, 0, 0, 0);

			AddCadre( d );

			SDL_FreeSurface( s );
		}
	}
}


int FolderAnimation::Init()
{
	return super::Init();
}


void FolderAnimation::Tick( Uint32 diff )
{

}


void FolderAnimation::Render()
{

}




