#pragma once
#include <string>


class Entity
{
public:
	Entity(const std::string& name);
	Entity(const Entity& other);
	Entity& operator=(const Entity& other);
	virtual ~Entity();

	virtual int Init() = 0;
	virtual void Tick(Uint32 diff) = 0;
	virtual void Remove();
	//virtual void Clear();

	std::string			m_name;

	int					m_id;

	bool				m_removed;
};