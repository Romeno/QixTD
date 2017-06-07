#pragma once
#include <string>


class Entity
{
public:
	Entity(const std::string& name);
	virtual ~Entity();

	virtual int Init();
	virtual void Render();
	virtual void Tick(Uint32 diff);
	virtual void Clear();

	std::string			m_name;
};

