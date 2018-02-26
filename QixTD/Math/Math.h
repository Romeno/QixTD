#pragma once
#include "glm/fwd.hpp"
#include "Engine/CoordinateSystem.h"


const float MY_ANGLE_EPSILON = 1.0 / 180.0 * M_PI;
const float MY_DISTANCE_EPSILON = 1;


typedef struct Pointf
{
	float x;
	float y;
};


// RECT

glm::dvec3 GetRectCenter( glm::dvec3 topLeft, glm::dvec3 size );
glm::dvec3 GetRectCenter( glm::dvec3 topLeft, double width, double height );
glm::dvec3 GetRectTopLeft( glm::dvec3 center, glm::dvec3 size );
glm::dvec3 GetRectTopLeft( glm::dvec3 center, double width, double height );

bool IsPointInRect( glm::dvec3 pos, glm::dvec3 center, glm::dvec3 size );

glm::dvec3 GetRectShootPos( glm::dvec3 center, glm::dvec3 size, Direction dir );

namespace glm 
{
	class drect
	{
	public:
		glm::dvec3 m_topLeft;
		glm::dvec3 m_size;

		glm::dvec3 GetCenter() { return GetRectCenter( m_topLeft, m_size ); }
		glm::dvec3 GetTopLeft() { return m_topLeft; }
		glm::dvec3 GetTopRight() { return glm::dvec3( m_topLeft.x + m_size.x, m_topLeft.y, 0 ); }
		glm::dvec3 GetBottomLeft() { return glm::dvec3( m_topLeft.x, m_topLeft.y + m_size.y, 0 ); }
		glm::dvec3 GetBottomRight() { return glm::dvec3( m_topLeft.x + m_size.x, m_topLeft.y + m_size.y, 0 ); }
		glm::dvec3 GetTopMiddle() { return glm::dvec3( m_topLeft.x + m_size.x / 2.0, m_topLeft.y, 0 ); }
	};
}

// DISTANCE

float DistanceFromLineSegmentToPoint( glm::dvec3 v, glm::dvec3 w, glm::dvec3 p );

void FindPointsOnDistFromPointOnLine(double angle,
	const glm::dvec3& center,
	double distance,
	glm::dvec3& p1, 
	glm::dvec3& p2);

void FindPointsOnDistFromPointOnLine2(float angle, float xfrom, float yfrom, float distance, float viewportLength,
	Pointf* p1, Pointf* p2);

// RANDOM

template <typename T>
T Random(T min2, T max2) {
	static auto& w = std::cout << "init" << std::endl;
	static std::random_device rd;
	static T max1 = rd.max();
	static T min1 = rd.min();
	static T diff = abs(max1 - min1);

	T q = min2 + (abs(max2 - min2) / diff * (T)rd());
	return q;
}
glm::dvec3 GetRandomDirection();

