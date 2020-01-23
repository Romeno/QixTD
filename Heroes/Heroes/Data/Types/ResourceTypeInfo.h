#pragma once


class ResourceTypeInfo
{
public:
	ResourceTypeInfo();
	virtual ~ResourceTypeInfo();

	int					m_id;
	std::string			m_name;
	std::string			m_description;
	std::string			m_image;
};

