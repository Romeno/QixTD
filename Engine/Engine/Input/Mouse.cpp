#include "stdafx.h"
#include "Mouse.h"
#include "Engine/CoordinateSystem.h"
#include "Engine/Utils/Utils.h"


Mouse::Mouse()
{

}


Mouse::~Mouse()
{

}


void Mouse::Tick( Uint32 diff )
{
	m_state = SDL_GetMouseState( m_x, m_y );

	//INFO( "MOUSE STATE %b", state );
	//INFO( "MOUSE STATE d %d", state );
	//INFO( "LMOUSE %d", (int) (bool) (m_state & SDL_BUTTON_LMASK) );
	//INFO( "MMOUSE %d", (int) (bool) (m_state & SDL_BUTTON_MMASK) );
	//INFO( "RMOUSE %d", (int) (bool) (m_state & SDL_BUTTON_RMASK) );
}


glm::dvec3 Mouse::GetPosition()
{
	return glm::dvec3( S2Rx( *m_x ), S2Ry( *m_y ), 0);
}


bool Mouse::isLMBPressed()
{
	return m_state & SDL_BUTTON_LMASK;
}


bool Mouse::isMMBPressed()
{
	return m_state & SDL_BUTTON_MMASK;
}


bool Mouse::isRMBPressed()
{
	return m_state & SDL_BUTTON_RMASK;
}


void Mouse::SetCursor( int id )
{
	auto it = m_cursors.find( id );

	if ( it != m_cursors.end() )
	{
		m_cursors[id]->Enable();
	}
}


Mouse::Cursor::Cursor()
{

}


Mouse::Cursor::~Cursor()
{
	
}


void Mouse::Cursor::Enable()
{
	SDL_SetCursor( cur );
}


Mouse::Cursor* Mouse::Cursor::Load( const std::string& path, int pointerX, int pointerY, int id )
{
	SDL_Surface *img = IMG_Load( path.c_str() );
	SDL_Cursor* c = SDL_CreateColorCursor( img, 6, 4 );
	RemoveSDLObj( img );

	Mouse::Cursor* cur = new Mouse::Cursor();
	cur->cur = c;

	Mouse::Inst()->m_cursors[id] = cur;

	return cur;
}
