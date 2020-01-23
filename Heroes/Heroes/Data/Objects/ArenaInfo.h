#pragma once
#include "Math/Math.h"


class ArenaInfo
{
public:
	ArenaInfo();
	virtual ~ArenaInfo();

	glm::dvec3				m_arenaDimensions;
	glm::drect				m_arenaRect;

	std::string				m_bgImage;

	std::vector<glm::dvec3>	m_objectIds;

	std::vector<glm::dvec3>	m_objectPos;

	std::vector<glm::dvec3>	m_objectDris;
};

