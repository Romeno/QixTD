#pragma once


class Mechanics
{
public:
	Mechanics();
	virtual ~Mechanics();

	virtual int Init();
	virtual void Tick( Uint32 diff );
	virtual void Render();
};

