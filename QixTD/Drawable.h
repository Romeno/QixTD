#pragma once
#include "Entity.h"
#include "CoordinateSystem.h"


class Drawable : public Entity
{
public:
	Drawable(const std::string& name);
	Drawable(const Drawable& other);
	Drawable& operator=(const Drawable& other);
	virtual ~Drawable() override;

	virtual void Tick(Uint32 diff) override;
	virtual void Render() = 0;
 
	virtual void SetWPos(glm::dvec3 wPos, Pivot pivot = PIVOT_CENTER);
	virtual void SetDirection(glm::dvec3 dir);									virtual void SetDirection(Direction dir);
	virtual void SetMoveSpeed(double ms);
	virtual void SetTimeToLive(Uint32 seconds);

	glm::dvec3      m_wPos; // position of top left corner in World coordinates
	glm::dvec3		m_direction;

	Uint32			m_startTime;
	Uint32			m_timeToLive;

	double			m_moveSpeed;

private:
	bool RemoveIfElapsed();
	void Move();

};

