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
//	(-screenWidth  / 2,           ↑ y
//	  screenHeight / 2) ┌─────────┼─────────┐
//	                    |         |         |	  
//                      |         |         |
//                    ──┼─────────┼─────────┼────> 
//                      |         |(0, 0)   |	 x
//                      |         |         |	
//                      └─────────┼─────────┘ 
//                                |         ( screenWidth  / 2, 
//		                                     -screenHeight / 2)


double S2Rx(int x)
{
	return x - GameManager::Inst()->vpWidth / 2;
}


double S2Ry(int y)
{
	return GameManager::Inst()->vpHeight / 2 - y;
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
	return round(x + GameManager::Inst()->vpWidth / 2);
}


int R2Sy(double y)
{
	return round(GameManager::Inst()->vpHeight / 2 - y);
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


glm::dvec3 DirToVec(Direction dir)
{
	switch (dir)
	{
	case DIR_TOP:
		return glm::dvec3(0, 1, 0);
		break;
	case DIR_RIGHT:
		return glm::dvec3(1, 0, 0);
		break;
	case DIR_BOTTOM:
		return glm::dvec3(0, -1, 0);
		break;
	case DIR_LEFT:
		return glm::dvec3(-1, 0, 0);
		break;
	case DIR_UNKNOWN:
		return glm::dvec3(0, 0, 0);
		break;
	default:
		return glm::dvec3(0, 0, 0);
		break;
	}
}


Direction VecToDir(glm::dvec3 vec)
{
	return DIR_LEFT;
}

