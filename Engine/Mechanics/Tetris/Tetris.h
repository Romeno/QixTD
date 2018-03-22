#pragma once
#include "Engine/Mechanics.h"


class Tetris : public Mechanics
{
public:
	Tetris();
	virtual ~Tetris();

	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;
	virtual void Render() override;


};

