// HeroesPC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Engine/GameManager.h"
#include "Heroes/Heroes.h"
#include "conio.h"

#undef main


using std::cout;
using std::endl;
using std::cin;
using std::string;


int main()
{
	gameManager = new GameManager();
	int ret = gameManager->Init( new Heroes() );
	if ( ret )
	{
		return ret;
	}

	gameManager->MainLoop();

	return 0;
}