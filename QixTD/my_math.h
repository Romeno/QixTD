#pragma once
#include "glm/fwd.hpp"
#include "CoordinateSystem.h"

const float MY_ANGLE_EPSILON = 1.0 / 180.0 * M_PI;
const float MY_DISTANCE_EPSILON = 1;

typedef struct Pointf
{
	float x;
	float y;
};


void FindPointsOnDistFromPointOnLine(double angle,
	const glm::dvec3& center,
	double distance,
	glm::dvec3& p1, 
	glm::dvec3& p2);

void FindPointsOnDistFromPointOnLine2(float angle, float xfrom, float yfrom, float distance, float viewportLength,
	Pointf* p1, Pointf* p2);


glm::dvec3 GetRectCenter(glm::dvec3 topLeft, glm::dvec3 size);
glm::dvec3 GetRectTopLeft(glm::dvec3 center, glm::dvec3 size);

glm::dvec3 GetRectShootPos(glm::dvec3 center, glm::dvec3 size, Direction dir);