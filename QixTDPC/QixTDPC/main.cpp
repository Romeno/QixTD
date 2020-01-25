// QixTDMain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Engine/GameManager.h"
#include "Mechanics/Qix/Qix.h"
#include "QixTD/QixTD.h"
#include "conio.h"
#include "Engine/Utils/Utils.h"
#include "Tests/TestLogger.h"



#undef main


using std::cout;
using std::endl;
using std::cin;
using std::string;


void runTests();
int runGame();


int main()
{
	//runTests();

	return runGame();
}


int runGame()
{
	gameManager = new GameManager();
	int ret = gameManager->Init( new QixTD() );
	if ( ret )
	{
		ELOG(ERR_TYPE_ENGINE_ERROR, "Error initing GameManager: %d", ret);
		return ret;
	}

	gameManager->MainLoop();

	return 0;
}


void runTests()
{
	testLogger();
}








