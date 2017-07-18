#include "stdafx.h"
#include "Drawable.h"
#include "GameManager.h"


Drawable::Drawable(const std::string& name)
	: Entity(name)

	, m_wPos(0, 0, 0)
	, m_direction(0, 0, 0)

	, m_startTime(0)
	, m_timeToLive(0)

	, m_moveSpeed(0.)
{

}


Drawable::Drawable(const Drawable& other)
	: Entity(other)

	, m_wPos(other.m_wPos)
	, m_direction(other.m_direction)

	, m_startTime(other.m_startTime)
	, m_timeToLive(other.m_timeToLive)

	, m_moveSpeed(other.m_moveSpeed)
{

}


Drawable& Drawable::operator=(const Drawable& other)
{
	m_wPos = other.m_wPos;
	m_direction = other.m_direction;

	m_startTime = other.m_startTime;
	m_timeToLive = other.m_timeToLive;

	m_moveSpeed = other.m_moveSpeed;

	return (*this);
}


Drawable::~Drawable()
{

}


void Drawable::Tick(Uint32 diff)
{
	if (RemoveIfElapsed())
		return;

	Move();

	Entity::Tick(diff);
}


bool Drawable::RemoveIfElapsed()
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


void Drawable::SetWPos(glm::dvec3 wPos, Pivot pivot)
{

}


void Drawable::SetDirection(glm::dvec3 dir)
{
	m_direction = glm::normalize(dir);
}


void Drawable::SetDirection(Direction dir)
{
	m_direction = DirToVec(dir);
}


void Drawable::SetMoveSpeed(double ms)
{
	m_moveSpeed = ms;
}


void Drawable::SetTimeToLive(Uint32 seconds)
{
	m_startTime = SDL_GetTicks();

	m_timeToLive = seconds * 1000;
}


void Drawable::Move()
{
	m_wPos += m_direction * m_moveSpeed;
}

