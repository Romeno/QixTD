#include "stdafx.h"
#include "Mouse.h"
#include "Engine/CoordinateSystem.h"
#include "Engine/Utils/Utils.h"


extern Mouse* mouse = nullptr;


Mouse::Mouse()
	: m_x( new int )
	, m_y( new int )
	, m_state( )

	, m_lmbClick( false )
	, m_mmbClick( false )
	, m_rmbClick( false )

	, m_lmbDblClick( false )
	, m_mmbDblClick( false )
	, m_rmbDblClick( false )

	, m_lmbDown( false )
	, m_mmbDown( false )
	, m_rmbDown( false )

	, m_wheelDelta( 0 )

	, m_cursors()
{

}


Mouse::~Mouse()
{

}


void Mouse::Init()
{

}


void Mouse::Tick( Uint32 diff )
{
	m_state = SDL_GetMouseState( m_x, m_y );

	// debug consistency check
	if ( (isLMBPressed() && !m_lmbDown) || (isMMBPressed() && !m_mmbDown) || (isRMBPressed() && !m_rmbDown) )
	{
		ERROR( "INCONSISTENT MOUSE STATE for button(s) %s", MouseState2Str(m_state).c_str() );
	}

	INFO( "MOUSE: %f, %f", mouse->GetPos().x, mouse->GetPos().y );

	//INFO( "MOUSE STATE d %d", state );
	//INFO( "LMOUSE %d", (int) (bool) (m_state & SDL_BUTTON_LMASK) );
	//INFO( "MMOUSE %d", (int) (bool) (m_state & SDL_BUTTON_MMASK) );
	//INFO( "RMOUSE %d", (int) (bool) (m_state & SDL_BUTTON_RMASK) );
}


void Mouse::PostTick( Uint32 diff )
{

}


glm::dvec3 Mouse::GetPos()
{
	return glm::dvec3( S2Rx( *m_x ), S2Ry( *m_y ), 0);
}


void Mouse::SetPos( glm::dvec3 rPos )
{
	SDL_WarpMouseInWindow( WIN, R2Sx( rPos.x ), R2Sy( rPos.y ) );
}


bool Mouse::isLMBPressed()
{
	return m_lmbDown;
	//return m_state & SDL_BUTTON_LMASK;
}


bool Mouse::isMMBPressed()
{
	return m_mmbDown;
	//return m_state & SDL_BUTTON_MMASK;
}


bool Mouse::isRMBPressed()
{
	return m_rmbDown;
	//return m_state & SDL_BUTTON_RMASK;
}


std::string Mouse::MouseState2Str( Uint32 state )
{
	std::string res = "";
	if ( state & SDL_BUTTON_LMASK )
	{
		res += " & LEFT";
	}

	if ( state & SDL_BUTTON_MMASK )
	{
		res += " & MIDDLE";
	}

	if ( state & SDL_BUTTON_RMASK )
	{
		res += " & RIGHT";
	}

	if ( state & SDL_BUTTON_X1MASK )
	{
		res += " & X1";
	}

	if ( state & SDL_BUTTON_X2MASK )
	{
		res += " & X2";
	}

	if ( !res.empty() ) {
		res = res.substr( 3 );
	}
	else
	{
		res = "none";
	}

	return res;
}


std::string Mouse::WheelDirection2Str( Uint32 direction )
{
	std::string res;

	if ( direction == SDL_MOUSEWHEEL_NORMAL )
	{
		res = "SDL_MOUSEWHEEL_NORMAL";
	}
	else if ( direction == SDL_MOUSEWHEEL_FLIPPED )
	{
		res = "SDL_MOUSEWHEEL_FLIPPED";
	}
	else
	{
		res = "UNKNOWN_MOUSEWHEEL_DIRECTION";
	}

	return res;
}


void Mouse::SetCursor( int id )
{
	auto it = m_cursors.find( id );

	if ( it != m_cursors.end() )
	{
		m_cursors[id]->Enable();
	}
}


void Mouse::PreTick( Uint32 diff )
{
	m_lmbClick = false;
	m_mmbClick = false;
	m_rmbClick = false;

	m_lmbDblClick = false;
	m_mmbDblClick = false;
	m_rmbDblClick = false;

	m_wheelDelta = 0;
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

	mouse->m_cursors[id] = cur;

	return cur;
}
