#pragma once


class BattleSideInfo
{
public:
	BattleSideInfo();
	virtual ~BattleSideInfo();

	std::vector<int>		m_unitIds;
	std::vector<int>		m_unitCounts;
	std::vector<glm::dvec3>	m_unitPos;
	std::vector<glm::dvec3> m_unitDirs;
	int						m_sideId;
};

