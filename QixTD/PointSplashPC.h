#pragma once
#include "Defines.h"

#ifdef POINT_SPLASH_GAME_TYPE

#include "Singleton.h"
#include "PlayerController.h"


class PointSplashPC : public PlayerController
{
public:
	PointSplashPC();
	~PointSplashPC();

	void Tick(Uint32 diff);
	void Render();
	void DrawPoints();
	void ClearPoints();
	void AddPoint();

	virtual void SetWPos(glm::dvec3 plrWPos, Pivot pivot);
	virtual glm::dvec3 GetWPos();

	std::vector<glm::dvec3>	m_wPoints;

	int						m_primitivecount;

	float					m_maxDistanceFromCenter;

	glm::dvec3				m_wPos;
};

#endif