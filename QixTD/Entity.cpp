#include "stdafx.h"
#include "Entity.h"


static int ID_COUNTER = 0;

Entity::Entity(const std::string& name)
	: m_name(name)

	, m_id(ID_COUNTER++)

	, m_removed(false)
{

}


Entity::Entity(const Entity& other)
	: m_name(other.m_name)

	, m_id(ID_COUNTER++)

	, m_removed(other.m_removed)
{

}


Entity& Entity::operator=(const Entity& other)
{
	m_name = other.m_name;
	m_id = ID_COUNTER++;
	m_removed = other.m_removed;

	return (*this);
}


Entity::~Entity()
{

}


void Entity::Remove()
{
	m_removed = true;
}


//void Entity::Clear()
//{
//
//}

//
//bool Entity::lessThan(const Entity& other) const
//{
//	return m_id < other.m_id;
//}
//
//
//bool operator<(const Entity& one, const Entity& two)
//{
//	return one.lessThan(two);
//}
