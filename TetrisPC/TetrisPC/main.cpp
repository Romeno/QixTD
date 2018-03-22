// TetrisPC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Engine/GameManager.h"
#include "Mechanics/Qix/Qix.h"
#include "Tetris/Tetris.h"
#include "conio.h"

#undef main


using std::cout;
using std::endl;
using std::cin;
using std::string;


int main()
{
	int ret = GameManager::Inst()->Init( new Tetris() );
	if ( ret )
	{
		return ret;
	}

	GameManager::Inst()->MainLoop();

	return 0;
}