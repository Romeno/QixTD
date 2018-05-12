#pragma once
#include "Mechanics/Qix/Components/Controlling/QixPC.h"


class QixTDPC : public QixPC
{
public:
	typedef QixPC super;

	QixTDPC();
	virtual ~QixTDPC();
	
	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;
	virtual void Clear() override;


	virtual int RequestStartMoveLeft() override;
	virtual int RequestStopMoveLeft() override;
	virtual int RequestStartMoveRight() override;
	virtual int RequestStopMoveRight() override;
	virtual int RequestStartMoveUp() override;
	virtual int RequestStopMoveUp() override;
	virtual int RequestStartMoveDown() override;
	virtual int RequestStopMoveDown() override;

	virtual void CheckIfPointOnBorder( const glm::dvec3& point );
	bool CheckIfPointOnBorderSimple( const glm::dvec3& point );

	virtual int RequestShoot() override;

	virtual void StartNewBorder() override;
	virtual glm::dvec3 PredictFuturePos( double velocity, Direction dir );

	bool	m_onBorder;
	bool	m_haveBeenOnBorderOnce;
	bool	m_firstTick;
	bool	m_drawingBorder;
};

