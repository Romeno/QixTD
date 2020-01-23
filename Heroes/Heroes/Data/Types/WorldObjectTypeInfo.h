#pragma once


class WorldObjectTypeInfo
{
public:
	WorldObjectTypeInfo();
	virtual ~WorldObjectTypeInfo();

	int						m_id;
	std::string				m_name;
	std::string				m_description;

	std::string				m_image;
	glm::dvec3				m_size;


};

