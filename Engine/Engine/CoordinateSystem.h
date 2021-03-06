﻿#pragma once


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

// returns old one
void SetWorldScale( double worldScale );
double GetWorldScale();

int R2SSize( double size );
double S2RSize( int size );

double S2Rx(int x);
double S2Ry(int y);
glm::dvec3 S2R(SDL_Point& sdlPoint);

int R2Sx(double x);
int R2Sy(double y);
SDL_Point R2S(glm::dvec3& romenoPoint);

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

// no need for size functions as size does not differ in Romeno and World

double S2Wx(int x);
double S2Wy(int y);
glm::dvec3 S2W(SDL_Point& sdlPoint);

int W2Sx(double x);
int W2Sy(double y);
SDL_Point W2S(glm::dvec3& worldPoint);

// Romeno <-> World

double R2Wx(double x);
double R2Wy(double y);
glm::dvec3 R2W(glm::dvec3& romenoPoint);

double W2Rx(double x);
double W2Ry(double y);
glm::dvec3 W2R(glm::dvec3& worldPoint);

SDL_Rect ToSDLRect(glm::dvec3 center, glm::dvec3 size);


enum Pivot {
    PIVOT_CENTER = 0,
    PIVOT_TOP_LEFT,
    PIVOT_BOTTOM_LEFT,
    PIVOT_TOP_RIGHT,
    PIVOT_BOTTOM_RIGHT,
    PIVOT_MAX_PIVOTS,
};



enum Direction {
	DIR_TOP = 1,
	DIR_RIGHT = 2,
	DIR_BOTTOM = 4,
	DIR_LEFT = 8,
	DIR_UNKNOWN = 16
};


glm::dvec3 Dir2Vec( Direction dir );
Direction Vec2Dir( glm::dvec3 vec );
