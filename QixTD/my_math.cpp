#include "stdafx.h"
#include "my_math.h"
#include "glm/glm.hpp"


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


void FindPointsOnDistFromPointOnLine2(float angle, float xfrom, float yfrom, float distance, float viewportLength,
	Pointf* p1, Pointf* p2)
{
	float tana = tan(angle);

	if (distance < MY_DISTANCE_EPSILON)
	{
		p1->x = xfrom;
		p1->y = yfrom;

		p2->x = xfrom;
		p2->y = yfrom;
	}
	else
	{
		if (abs(abs(angle) - M_PI / 2) < MY_ANGLE_EPSILON) {
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
			float x = -p / 2 + sqrt((p / 2) * (p / 2) - q);

			p1->x = x * viewportLength;
			p1->y = (tana * x + bb) * viewportLength;

			x = -p / 2 - sqrt((p / 2) * (p / 2) - q);
			p2->x = x * viewportLength;
			p2->y = (tana * x + bb) * viewportLength;
		}
	}

	return;
}


glm::dvec3 GetRectCenter(glm::dvec3 topLeft, glm::dvec3 size)
{
	glm::dvec3 center;

	center.x = topLeft.x + size.x / 2;
	center.y = topLeft.y - size.y / 2;
	center.z = topLeft.z;

	return center;
}


glm::dvec3 GetRectTopLeft(glm::dvec3 center, glm::dvec3 size)
{
	glm::dvec3 topLeft;

	topLeft.x = center.x - size.x / 2;
	topLeft.y = center.y + size.y / 2;
	topLeft.z = center.z;

	return topLeft;
}
