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

	virtual int RequestShoot() override;

	virtual void StartNewBorder() override;

};

