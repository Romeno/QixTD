#include "stdafx.h"
#include "CoordinateSystem.h"
#include "Engine/GameManager.h"
#include "glm/glm.hpp"
#include "Math/Math.h"

#include "Gameplay/SC.h"

// SDL
//
// (0, 0)
//   ┌──────────────────┐----→ 
//   |					|	  x
//   |					|
//   |					|
//	 |					|	
//   └──────────────────┘ 
//   |					(width, height)
//   ↓ y

// Romeno
//					 
//	(- width / 2,            ↑ y
//	 - height / 2) ┌─────────┼─────────┐
//	               |         |         |	  
//                 |         |         |
//               ──┼─────────┼─────────┼────→ 
//                 |         |(0, 0)   |	 x
//                 |         |         |	
//                 └─────────┼─────────┘ 
//                           |         (width / 2, height / 2)

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
// (-levelWidth / 2
//  -levelHeight / 2)                        ↑ y
//          ┌────────────────────────────────┼────────────────────────────────┐
//          |                                |                                |
//          |                   ( screenPos.x,                                |
//          |                     screenPos.y )                               |
//          |                               ┌┼──────────────────┐             |
//          |                               ||                  |             |
//          |                               ||                  |             |
//          |                               ||                  |             |
//        ──┼───────────────────────────────┼┼──────────────────┼─────────────┼───→
//          |                               || (0, 0)           |             |    x
//          |                               └┼──────────────────┘             |
//          |                                |     ( screenPos.x + vpWidth,   |
//          |                                |       screenPos.x + vpHeight ) |
//          |                                |                                |
//          |                                |                                |
//          └────────────────────────────────┼────────────────────────────────┘
//                                           |                                (levelWidth / 2, levelHeight / 2)

double S2Wx(int x)
{
	return S2Rx(x) + SC()->GetWPos().x;
}


double S2Wy(int y) 
{
	return S2Ry(y) + SC()->GetWPos().y;
}


glm::dvec3 S2W(SDL_Point& sdlPoint) 
{
	return {
		S2Wx(sdlPoint.x),
		S2Wy(sdlPoint.y),
		0
	};
}


int W2Sx(double x) 
{
	return R2Sx(x - SC()->GetWPos().x);
}


int W2Sy(double y) 
{
	return R2Sy(y - SC()->GetWPos().y);
}


SDL_Point W2S(glm::dvec3& worldPoint) 
{
	return {
		W2Sx(worldPoint.x),
		W2Sy(worldPoint.y)
	};
}


// Romeno <-> World

double R2Wx(double x)
{
	return x + SC()->GetWPos().x;
}


double R2Wy(double y)
{
	return y + SC()->GetWPos().y;
}


glm::dvec3 R2W(glm::dvec3& romenoPoint)
{
	return{
		R2Wx(romenoPoint.x),
		R2Wy(romenoPoint.y),
		0
	};
}


double W2Rx(double x)
{
	return x - SC()->GetWPos().x;
}


double W2Ry(double y)
{
	return y - SC()->GetWPos().y;
}


glm::dvec3 W2R(glm::dvec3& worldPoint)
{
	return {
		W2Sx(worldPoint.x),
		W2Sy(worldPoint.y),
		0
	};
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

