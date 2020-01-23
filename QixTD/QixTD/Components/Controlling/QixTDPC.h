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


	virtual int OrderStop() override;

	virtual int OrderStartMoveLeft() override;
	virtual int OrderStartMoveRight() override;
	virtual int OrderStartMoveUp() override;
	virtual int OrderStartMoveDown() override;

	virtual int OrderShoot() override;


	bool IsOnOwnTerritory( glm::dvec3 pos );

	virtual void CompleteBorders();
	//bool CheckIfPointOnBorderSimple( const glm::dvec3& point );

	virtual void StartNewBorder(glm::dvec3 point1, glm::dvec3 point2);
	//virtual glm::dvec3 PredictFuturePos( double velocity, Direction dir );

	bool	m_onOwnTerritory;
	bool	m_haveBeenOnOwnTerritoryOnce;
	bool	m_drawingBorder;
	bool    m_startedBorder;
};

