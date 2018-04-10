// QixTDMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Engine/GameManager.h"
#include "Mechanics/Qix/Qix.h"
#include "QixTD/QixTD.h"
#include "conio.h"
#include <limits>

#undef main


using std::cout;
using std::endl;
using std::cin;
using std::string;


int main()
{
	gameManager = new GameManager();
	int ret = gameManager->Init( new QixTD() );
	if ( ret )
	{
		return ret;
	}

	gameManager->MainLoop();

	return 0;
}