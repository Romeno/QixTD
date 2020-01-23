#pragma once
#include "Math/Math.h"


class WorldRegionInfo
{
public:
	WorldRegionInfo();
	virtual ~WorldRegionInfo();

	glm::dvec3				m_worldDimensions;
	glm::drect				m_worldRect;

	std::string				m_worldName;

	std::vector<int>		m_worldObjectIds;

	std::vector<glm::dvec3> m_worldObjectPos;

	std::vector<glm::dvec3>	m_worldObjectDirs;
};

