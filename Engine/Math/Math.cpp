#include "stdafx.h"
#include "Math.h"
#include "Engine/Utils/Utils.h"


void FindPointsOnDistFromPointOnLine(double angle, 
	const glm::dvec3& center,
	double distance,
	glm::dvec3& p1, 
	glm::dvec3& p2)
{
	double tana = tan(angle);

	if (distance < MY_DISTANCE_EPSILON)
	{
		p1 = p2 = center;
	}
	else
	{
		if (abs(angle - M_PI / 2) < MY_ANGLE_EPSILON) {
			p1 = { center.x, center.y + distance, 0 };
			p2 = { center.x, center.y - distance, 0 };
			//p1->x = round(xfrom);
			//p1->y = round(yfrom + distance);

			//p2->x = round(xfrom);
			//p2->y = round(yfrom - distance);
		}
		else
		{
			double bb = center.y - tana * center.x;
			double a = 1.0 + tana * tana;
			double b = 2.0 * bb * tana - 2.0 * center.x - 2.0 * tana * center.y;
			double c = center.x * center.x + bb * bb - 2.0 * bb * center.y + center.y * center.y - distance * distance;
			double x = 0;

			x = (-b + sqrt(b * b - 4.0 * a * c)) / 2.0 / a;
			p1 = { x, tana * x + bb, 0 };
			//p1.x = round(x);
			//p1.y = round(tana * x + bb);

			x = (-b - sqrt(b * b - 4.0 * a * c)) / 2.0 / a;
			p2 = { x, tana * x + bb, 0 };
			//p2.x = round(x);
			//p2.y = round(tana * x + bb);
		}
	}

	return;
}


void FindPointsOnDistFromPointOnLine2( float angle, float xfrom, float yfrom, float distance, float viewportLength,
	Pointf* p1, Pointf* p2 )
{
	float tana = tan( angle );

	if ( distance < MY_DISTANCE_EPSILON )
	{
		p1->x = xfrom;
		p1->y = yfrom;

		p2->x = xfrom;
		p2->y = yfrom;
	}
	else
	{
		if ( abs( abs( angle ) - M_PI / 2 ) < MY_ANGLE_EPSILON ) {
			p1->x = xfrom;
			p1->y = yfrom + distance;

			p2->x = xfrom;
			p2->y = yfrom - distance;
		}
		else
		{
			yfrom /= viewportLength;
			xfrom /= viewportLength;
			distance /= viewportLength;

			float bb = yfrom - tana * xfrom;
			float a = 1 + tana*tana;
			float p = bb / a * 2 * tana - xfrom / a * 2 - tana / a * 2 * yfrom;
			float q = xfrom / a * xfrom + bb / a * bb - bb / a * 2 * yfrom + yfrom / a * yfrom - distance / a * distance;
			float x = -p / 2 + sqrt( (p / 2) * (p / 2) - q );

			p1->x = x * viewportLength;
			p1->y = (tana * x + bb) * viewportLength;

			x = -p / 2 - sqrt( (p / 2) * (p / 2) - q );
			p2->x = x * viewportLength;
			p2->y = (tana * x + bb) * viewportLength;
		}
	}

	return;
}


glm::dvec3 GetRectCenter( glm::dvec3 topLeft, glm::dvec3 size )
{
	return GetRectCenter( topLeft, size.x, size.y );
}


glm::dvec3 GetRectCenter( glm::dvec3 topLeft, double width, double height )
{
	glm::dvec3 center;

	center.x = topLeft.x + width / 2;
	center.y = topLeft.y - height / 2;
	center.z = topLeft.z;

	return center;
}


glm::dvec3 GetRectTopLeft( glm::dvec3 center, glm::dvec3 size )
{
	return GetRectTopLeft( center, size.x, size.y );
}


glm::dvec3 GetRectTopLeft( glm::dvec3 center, double width, double height )
{
	glm::dvec3 topLeft;

	topLeft.x = center.x - width / 2;
	topLeft.y = center.y + height / 2;
	topLeft.z = center.z;

	return topLeft;
}


bool IsPointInRect( glm::dvec3 point, glm::dvec3 center, glm::dvec3 size )
{
	return	point.x > center.x - size.x / 2 &&
		point.y > center.y - size.y / 2 &&
		point.x < center.x + size.x / 2 &&
		point.y < center.y + size.y / 2;
}


bool IsPointOnLine_VectorMath( glm::dvec3 first, glm::dvec3 last, glm::dvec3 point, double epsilon )
{
	glm::dvec3 cross = glm::cross( last - first, point - first );

	// compare versus epsilon for floating point values, or != 0 if using integers
	if ( glm::length(cross) < epsilon/* || glm::length( cross ) / glm::length( last - first ) / glm::length( point - first ) < epsilon*/ )
	{
		double dot = glm::dot( last - first, point - first );
		if ( dot < 0 )
		{
			return false;
		}

		if ( dot > glm::distance2( last, first ) )
		{
			return false;
		}

		return true;
	}
	else
	{
		return false;
	}
}

// this epsilon is perpendicular offset from edges of rectangle formed based on the line 
bool IsPointOnLine_Rectangle( glm::dvec3 first, glm::dvec3 last, glm::dvec3 point, double epsilon )
{
	//glm::dvec2 vline = last - first;

	//glm::perp(vline, )

	return true;
}


bool IsPointOn90DegreeAlignedLine( glm::dvec3 first, glm::dvec3 last, glm::dvec3 point, double epsilon )
{
	glm::dvec3 center = glm::mix( last, first, 0.5 );
	glm::dvec3 size;
	if ( abs(first.x - last.x) < std::numeric_limits<double>::epsilon() )
	{
		size.x = epsilon * 2;
		size.y = glm::length( last - first );
	}
	else 
	{
		size.y = epsilon * 2;
		size.x = glm::length( last - first );
	}

	return IsPointInRect( point, center, size );
}


glm::dvec3 GetRectShootPos(glm::dvec3 topLeft, glm::dvec3 size, Direction dir)
{
	switch (dir)
	{
	case DIR_TOP:
		return glm::dvec3(topLeft.x + size.x / 2, topLeft.y, topLeft.z);
		break;
	case DIR_RIGHT:
		return glm::dvec3(topLeft.x + size.x, topLeft.y - size.y / 2, topLeft.z);
		break;
	case DIR_BOTTOM:
		return glm::dvec3(topLeft.x + size.x / 2, topLeft.y - size.y, topLeft.z);
		break;
	case DIR_LEFT:
		return glm::dvec3(topLeft.x, topLeft.y - size.y / 2, topLeft.z);
		break;
	default:
		ELOGB(ERR_TYPE_PROGRAMMING_ERROR, "Unknown direction: %d", (int)dir);
		return topLeft;
		break;
	}
}


glm::dvec3 GetRandomDirection()
{
	return glm::normalize(glm::dvec3(Random(-10., 10.), Random(-10., 10.), 0.));
}


float DistanceFromLineSegmentToPoint( glm::dvec3 v, glm::dvec3 w, glm::dvec3 p )
{
	// Õ¿œ»—¿Õ¿ ƒÀﬂ  ¿ Œ√Œ-“Œ vec2

// 	// Return minimum distance between line segment vw and point p
// 	const float l2 = length_squared( v, w );  // i.e. |w-v|^2 -  avoid a sqrt
// 	if ( l2 == 0.0 ) return distance( p, v );   // v == w case
// 												// Consider the line extending the segment, parameterized as v + t (w - v).
// 												// We find projection of point p onto the line. 
// 												// It falls where t = [(p-v) . (w-v)] / |w-v|^2
// 	const float t = dot( p - v, w - v ) / l2;
// 	if ( t < 0.0 ) return distance( p, v );       // Beyond the 'v' end of the segment
// 	else if ( t > 1.0 ) return distance( p, w );  // Beyond the 'w' end of the segment
// 	const vec2 projection = v + t * (w - v);  // Projection falls on the segment
// 	return distance( p, projection );

	return 0;
}


bool glm::drect::ContainsPoint( const glm::dvec3& point )
{
	return IsPointInRect( point, GetCenter(), m_size );
}


bool glm::drect::ContainsRect( const glm::drect& another )
{
	return another.m_topLeft.x >= m_topLeft.x &&
		another.m_topLeft.y <= m_topLeft.y &&
		another.GetBottomRight().x <= GetBottomRight().x &&
		another.GetBottomRight().y >= GetBottomRight().y;
}


glm::drect glm::drect::ClosestRectOfSameSizeInsideThisRect( const glm::drect& another )
{
	glm::drect closest = another;

	if ( another.m_topLeft.x < m_topLeft.x )
	{
		closest.m_topLeft.x = m_topLeft.x;
	}

	if ( another.m_topLeft.y > m_topLeft.y )
	{
		closest.m_topLeft.y = m_topLeft.y;
	}

	if ( another.GetBottomRight().x > GetBottomRight().x )
	{
		closest.m_topLeft.x = GetBottomRight().x - another.m_size.x;
	}

	if ( another.GetBottomRight().y < GetBottomRight().y )
	{
		closest.m_topLeft.y = GetBottomRight().y + another.m_size.y;
	}

	return closest;
}

