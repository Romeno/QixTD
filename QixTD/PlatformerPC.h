#pragma once
#include "Defines.h"

#ifdef PLATFORMER_GAME_TYPE

#include "Singleton.h"
#include "PlayerController.h"
#include "CoordinateSystem.h"
#include "glm/glm.hpp"
#include "Rect.h"


struct JumpInfo
{
	bool jumping = false;
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::nanoseconds jumpDuration = std::chrono::nanoseconds(1500000000);
	
	//Uint32 startTime = 0;
	//Uint32 elapsedTime = 0;
	//Uint32 jumpDuration = 1500;
	double jumpSpeed = 3.0;
};


enum Direction {
	DIR_TOP = 1,
	DIR_RIGHT = 2,
	DIR_BOTTOM = 4,
	DIR_LEFT = 8,
};


class PlatformerPC : public PlayerController
{
public:
	PlatformerPC();
	virtual ~PlatformerPC();

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

	int RequestJump();

	//SDL_Point GetSPos() { return { (int)round(W2Sx(m_rpos.x)), (int)round(W2Sy(m_rpos.y)) }; }
	void SetWPos(glm::dvec3 plrWPos, Pivot pivot);
	glm::dvec3 GetWPos() { return m_wPos; }

	int			m_imageWidth;
	int			m_imageHeight;

	Rect		m_collider;

	int			m_moveSpeed;

private:

	//SDL_Point m_pos;
	//double m_precisePosY;
	//bool facesLeft = true;

	// tick callback data
	SDL_TimerID		m_timerId;
	Uint32			m_timerInterval;

	// math model data
	glm::dvec3		m_wPos;
	bool			m_tryingToMove;
	bool			m_moving;
	Uint32			m_facing;

	JumpInfo		m_jumpInfo;

	SDL_Texture	   *m_plrTex;
};

#endif