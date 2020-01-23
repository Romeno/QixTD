#pragma once


class WorldViewObjectInfo
{
public:
	WorldViewObjectInfo();
	virtual ~WorldViewObjectInfo();

	int						m_type;
	int						m_owner;
	glm::dvec3				m_pos;

};

