#pragma once
#include "Engine/Components/Controlling/Playable.h"
#include "Engine/CoordinateSystem.h"


class QixPC : public Playable
{
public:
	typedef Playable super;

	QixPC();
	virtual ~QixPC();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Clear();

	virtual int OrderStop();

	virtual int OrderStartMoveLeft();
	virtual int OrderStartMoveRight();
	virtual int OrderStartMoveUp();
	virtual int OrderStartMoveDown();

	virtual int OrderShoot();

// 	bool			m_tryingToMove;
// 	Uint32			m_facing;

    //Sprite         *m_sprite;
//	glm::dvec3		m_lastTurnPos;

// 	const std::string	m_playerImagePath;
// 	const std::string	m_playerShootImagePath;
};

