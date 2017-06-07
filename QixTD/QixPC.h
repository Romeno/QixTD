#pragma once
#include "Defines.h"
#include "PlayerController.h"


enum Direction {
	DIR_TOP = 1,
	DIR_RIGHT = 2,
	DIR_BOTTOM = 4,
	DIR_LEFT = 8,
};


class QixPC : public PlayerController
{
public:
	QixPC();
	virtual ~QixPC();

	virtual int Init();
	virtual void Render();
	virtual void Tick(Uint32 diff);
	virtual void Clear();

	int RequestStartMoveLeft();
	int RequestStopMoveLeft();
	int RequestStartMoveRight();
	int RequestStopMoveRight();
	int RequestStartMoveUp();
	int RequestStopMoveUp();
	int RequestStartMoveDown();
	int RequestStopMoveDown();

	int				m_imageWidth;
	int				m_imageHeight;
	int				m_moveSpeed;

	glm::dvec3		m_wPos;
	bool			m_tryingToMove;
	bool			m_moving;
	Uint32			m_facing;

	SDL_Texture	   *m_plrTex;
};

