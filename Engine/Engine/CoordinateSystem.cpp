#include "stdafx.h"
#include "CoordinateSystem.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Camera.h"
#include "Engine/Game.h"
#include "Math/Math.h"


// SDL
//
// (0, 0)
//   ┌──────────────────┐────> 
//   |					|	  x
//   |					|
//   |					|
//	 |					|	
//   └──────────────────┘ 
//   |					(screenWidth, 
//	 |					 screenHeight)
//   ↓ y


// Romeno
//					 
// (-screenWidth / 2 * worldScale,			        ↑ y
//	 screenHeight / 2 * worldScale)       ┌─────────┼─────────┐
// 	                                      |         |         |	  
//                                        |         |         |
//                                      ──┼─────────┼─────────┼────> 
//                                        |         |(0, 0)   |	 x
//                                        |         |         |	
//                                        └─────────┼─────────┘ 
//                                                  |         ( screenWidth  / 2 * worldScale, 
//		                                                       -screenHeight / 2 * worldScale)
//

static double s_worldScale = 1.;

void SetWorldScale( double worldScale )
{
	s_worldScale = worldScale;
}


double GetWorldScale()
{
	return s_worldScale;
}


int R2SSize(double size)
{
	return round( size / s_worldScale );
}


double S2RSize( int size )
{
	return size * s_worldScale;
}


double S2Rx(int x)
{
	return (x - VP_WIDTH / 2) * s_worldScale;
}


double S2Ry(int y)
{
	return (VP_HEIGHT / 2 - y) * s_worldScale;
}


glm::dvec3 S2R(SDL_Point& sdlPoint)
{
	return { 
		S2Rx(sdlPoint.x),
		S2Ry(sdlPoint.y),
		0
	};
}


int R2Sx(double x)
{
	return (int)round(x / s_worldScale) + VP_WIDTH / 2;
}


int R2Sy(double y)
{
	return VP_HEIGHT / 2 - (int)round(y / s_worldScale );
}


SDL_Point R2S(glm::dvec3& romenoPoint)
{
	return { 
		R2Sx(romenoPoint.x), 
		R2Sy(romenoPoint.y) 
	};
}


// World
//
// (-levelWidth  / 2
//   levelHeight / 2 )                       ↑ y
//          ┌────────────────────────────────┼────────────────────────────────┐
//          |                                |                                |
//          |           (screenWPos.x,       |                                |
//          |            screenWPos.y )      |                                |
//          |                  ┌─────────────┼───────────────────┐            |
//          |                  | (screenWPos.x + vpWidth  / 2,   |            |
//          |                  |  screenWPos.y - vpHeight / 2 )  |            |
//          |                  |             |  *                |            |
//        ──┼──────────────────┼─────────────┼───────────────────┼────────────┼───→
//          |                  |             | (0, 0)            |            |    x
//          |                  └─────────────┼───────────────────┘            |
//          |                                |      (screenPos.x + vpWidth,   |
//          |                                |       screenPos.y - vpHeight ) |
//          |                                |                                |
//          |                                |                                |
//          └────────────────────────────────┼────────────────────────────────┘
//                                           |                          (levelWidth  / 2, 
//                                                                       levelHeight / 2 )


double S2Wx(int x)
{
	return CAMERA->S2Wx( x );
}


double S2Wy(int y) 
{
	return CAMERA->S2Wy( y );
}


glm::dvec3 S2W(SDL_Point& sdlPoint) 
{
	return CAMERA->S2W( sdlPoint );
}


int W2Sx(double x) 
{
	return CAMERA->W2Sx( x );
}


int W2Sy(double y) 
{
	return CAMERA->W2Sy( y );
}


SDL_Point W2S(glm::dvec3& worldPoint) 
{
	return CAMERA->W2S( worldPoint );
}


// Romeno <-> World

double R2Wx(double x)
{
	return CAMERA->R2Wx( x );
}


double R2Wy(double y)
{
	return CAMERA->R2Wy( y );
}


glm::dvec3 R2W(glm::dvec3& romenoPoint)
{
	return CAMERA->R2W( romenoPoint );
}


double W2Rx(double x)
{
	return CAMERA->W2Rx( x );
}


double W2Ry(double y)
{
	return CAMERA->W2Ry( y );
}


glm::dvec3 W2R(glm::dvec3& worldPoint)
{
	return CAMERA->W2R( worldPoint );
}


SDL_Rect ToSDLRect(glm::dvec3 center, glm::dvec3 size)
{
	glm::dvec3 topLeft = GetRectTopLeft(center, size);
	return { W2Sx(topLeft.x),
			 W2Sy(topLeft.y),
 			 int(size.x),
			 int(size.y) };
}


glm::dvec3 Dir2Vec( Direction dir )
{
	switch ( dir )
	{
	case DIR_TOP:
		return glm::dvec3( 0, 1, 0 );
		break;
	case DIR_RIGHT:
		return glm::dvec3( 1, 0, 0 );
		break;
	case DIR_BOTTOM:
		return glm::dvec3( 0, -1, 0 );
		break;
	case DIR_LEFT:
		return glm::dvec3( -1, 0, 0 );
		break;
	case DIR_UNKNOWN:
		return glm::dvec3( 0, 0, 0 );
		break;
	default:
		return glm::dvec3( 0, 0, 0 );
		break;
	}
}


Direction Vec2Dir( glm::dvec3 vec )
{
	if ( vec.x < std::numeric_limits<double>::epsilon() && vec.y > 0 )
	{
		return DIR_TOP;
	}
	else if ( vec.x < std::numeric_limits<double>::epsilon() && vec.y < 0 )
	{
		return DIR_BOTTOM;
	}
	else if ( vec.x > 0 && vec.y < std::numeric_limits<double>::epsilon() )
	{
		return DIR_RIGHT;
	}
	else if ( vec.x < 0 && vec.y < std::numeric_limits<double>::epsilon() )
	{
		return DIR_LEFT;
	}
	else
	{
		return DIR_UNKNOWN;
	}
}
