#pragma once
#include "Engine/CoordinateSystem.h"


class Camera
{
public:
	Camera();
	virtual ~Camera();

	virtual int Init();
	virtual void Tick(Uint32 diff);

	virtual void SetWPos( glm::dvec3 worldPos, Pivot pivot = PIVOT_CENTER);
	glm::dvec3 GetWPos();


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

	double S2Wx( int x );
	double S2Wy( int y );
	glm::dvec3 S2W( SDL_Point& sdlPoint );


	int W2Sx( double x );
	int W2Sy( double y );
	SDL_Point W2S( glm::dvec3& worldPoint );


	// Romeno <-> World

	double R2Wx( double x );
	double R2Wy( double y );
	glm::dvec3 R2W( glm::dvec3& romenoPoint );


	double W2Rx( double x );
	double W2Ry( double y );
	glm::dvec3 W2R( glm::dvec3& worldPoint );


protected:
	glm::dvec3 m_wPos;					// position of top left corner in World coordinates

};







