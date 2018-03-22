#include "stdafx.h"
#include "Entity.h"
#include "Engine/GameManager.h"


static int ID_COUNTER = 0;


Entity::Entity()
	: m_wPos(0, 0, 0)
	, m_direction(0, 0, 0)

	, m_startTime(0)
	, m_timeToLive(0)

	, m_moveSpeed(0.)
	
	, m_name()

	, m_id(ID_COUNTER++)

	, m_removed(false)

	, m_size(0, 0, 0)
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


int Entity::Init()
{
	return 0;
}


void Entity::Tick(Uint32 diff)
{

}


void Entity::Remove()
{
	m_removed = true;
}


void Entity::SetDirection(glm::dvec3 dir)
{
	m_direction = glm::normalize(dir);
}


void Entity::SetDirection(Direction dir)
{
	m_direction = DirToVec(dir);
}


void Entity::SetMoveSpeed(double ms)
{
	m_moveSpeed = ms;
}


void Entity::SetTimeToLive(Uint32 seconds)
{
	m_startTime = SDL_GetTicks();

	m_timeToLive = seconds * 1000;
}


void Entity::Move()
{
	m_wPos += m_direction * m_moveSpeed;
}


bool Entity::RemoveIfElapsed()
{
	if (m_removed)
		return m_removed;

	if (m_timeToLive && (m_timeToLive + m_startTime < SDL_GetTicks()))
	{
		m_removed = true;
		return true;
	}

	return false;
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
