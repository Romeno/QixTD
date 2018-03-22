#include "stdafx.h"
#include "Camera.h"
#include "Engine/Utils/Utils.h"
#include "Math/Math.h"


Camera::Camera()
	: m_wPos()
{

}


Camera::~Camera()
{

}


int Camera::Init()
{
	return 0;
}


void Camera::Tick(Uint32 diff)
{

}


void Camera::SetWPos( glm::dvec3 worldPos, Pivot pivot /*= PIVOT_CENTER*/ )
{
	if ( pivot == PIVOT_CENTER )
	{
		m_wPos = GetRectTopLeft( worldPos, VP_WIDTH, VP_HEIGHT );
	}
	else
	{
		throw "shit";
	}
}


glm::dvec3 Camera::GetWPos()
{
	return GetRectCenter( m_wPos, VP_WIDTH, VP_HEIGHT );
}


double Camera::S2Wx( int x )
{
	return S2Rx(x) + GetWPos().x;
}


double Camera::S2Wy( int y )
{
	return S2Ry(y) + GetWPos().y;
}


glm::dvec3 Camera::S2W( SDL_Point& sdlPoint )
{
	return{
		S2Wx( sdlPoint.x ),
		S2Wy( sdlPoint.y ),
		0
	};
}


int Camera::W2Sx( double x )
{
	return R2Sx(x - GetWPos().x);
}


int Camera::W2Sy( double y )
{
	return R2Sy(y - GetWPos().y);
}


SDL_Point Camera::W2S( glm::dvec3& worldPoint )
{
	return{
		W2Sx( worldPoint.x ),
		W2Sy( worldPoint.y )
	};
}


// Romeno <-> World

double Camera::R2Wx( double x )
{
	return x + GetWPos().x;
}


double Camera::R2Wy( double y )
{
	return y + GetWPos().y;
}


glm::dvec3 Camera::R2W( glm::dvec3& romenoPoint )
{
	return{
		R2Wx( romenoPoint.x ),
		R2Wy( romenoPoint.y ),
		0
	};
}


double Camera::W2Rx( double x )
{
	return x - GetWPos().x;
}


double Camera::W2Ry( double y )
{
	return y - GetWPos().y;
}


glm::dvec3 Camera::W2R( glm::dvec3& worldPoint )
{
	return{
		W2Sx( worldPoint.x ),
		W2Sy( worldPoint.y ),
		0
	};
}







