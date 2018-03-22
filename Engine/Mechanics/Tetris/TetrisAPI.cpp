#include "stdafx.h"
#include "TetrisAPI.h"
#include "Engine/CoordinateSystem.h"


TetrisAPI::TetrisAPI()
{

}


TetrisAPI::~TetrisAPI()
{

}


void TetrisAPI::Init( Tetris* mech )
{

}


void TetrisAPI::Play( Entity* e )
{

}


void TetrisAPI::SpawnFigure( FigureType f, glm::dvec3 pos )
{

}


void TetrisAPI::SetFallSpeed( double fallSpeed )
{
	m_fallSpeed = fallSpeed;
}


void TetrisAPI::SetFallDirection( Direction dir )
{
	m_fallDir = DirToVec( dir );
}


void TetrisAPI::SetFieldSize( int width, int height )
{

}
