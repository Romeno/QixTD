﻿#pragma once


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

double S2Rx(int x);
double S2Ry(int y);
glm::dvec3 S2R(SDL_Point& sdlPoint);

int R2Sx(double x);
int R2Sy(double y);
SDL_Point R2S(glm::dvec3& romenoPoint);

// World
//
// (-levelWidth / 2
//  -levelHeight / 2)                        ↑ y
//          ┌────────────────────────────────┼────────────────────────────────┐
//          |                                |                                |
//          |                   ( -screenWidth / 2,                           |
//          |                     -screenHeight / 2)                          |
//          |                               ┌┼──────────────────┐             |
//          |                               ||                  |             |
//          |                               ||                  |             |
//          |                               ||                  |             |
//        ──┼───────────────────────────────┼┼──────────────────┼─────────────┼───→
//          |                               || (0, 0)           |             |    x
//          |                               └┼──────────────────┘             |
//          |                                |           ( screenWidth / 2,   |
//          |                                |             screenHeight / 2)  |
//          |                                |                                |
//          |                                |                                |
//          └────────────────────────────────┼────────────────────────────────┘
//                                           |                                (levelWidth / 2, levelHeight / 2)

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
