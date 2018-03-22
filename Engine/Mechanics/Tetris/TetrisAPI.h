#pragma once
#include "Engine/API.h"
#include "Mechanics/Tetris/TetrisCommon.h"
#include "Mechanics/Tetris/Tetris.h"


class TetrisAPI : public API
{
public:
	typedef API super;

	DECLARE_SINGLETON( TetrisAPI )

	TetrisAPI();
	virtual ~TetrisAPI();

	void Init( Tetris* mech );

	virtual void Play( Entity* e );
	virtual void SpawnFigure( FigureType f, glm::dvec3 pos );
	virtual void SetFallSpeed( double fallSpeed );
	virtual void SetFallDirection( Direction dir );

	virtual void SetFieldSize( int width, int height );

	Tetris*			tetrisMech;

	double			m_fallSpeed;
	glm::dvec3		m_fallDir;

	int				field;
};

