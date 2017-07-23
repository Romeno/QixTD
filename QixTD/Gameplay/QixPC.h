#pragma once
#include "Gameplay/Defines.h"
#include "Engine/Controlling/PlayerController.h"
#include "Engine/Sprite.h"


class QixPC : public PlayerController
{
public:
	QixPC();
	virtual ~QixPC();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Clear() override;
    virtual void Possess(Sprite* sprite) override;
    virtual void Render() override;

    void SetWPos(glm::dvec3 wPos, Pivot pivot = PIVOT_CENTER);

	int RequestStartMoveLeft();
	int RequestStopMoveLeft();
	int RequestStartMoveRight();
	int RequestStopMoveRight();
	int RequestStartMoveUp();
	int RequestStopMoveUp();
	int RequestStartMoveDown();
	int RequestStopMoveDown();
	int RequestShoot();

	void StartNewBorder();
	glm::dvec3 GetShootPos();

	int				m_moveSpeed;

	bool			m_tryingToMove;
	bool			m_moving;
	Uint32			m_facing;

    Sprite         *m_sprite;
	glm::dvec3		m_lastTurnPos;

	const std::string	m_playerImagePath;
	const std::string	m_playerShootImagePath;
};

