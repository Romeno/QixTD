// SDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "GameManager.h"

#undef main

using std::cout;
using std::endl;
using std::cin;
using std::string;


int main()
{
	int ret = GameManager::Inst()->Init();
	if (ret)
	{
		return ret;
	}

	GameManager::Inst()->MainLoop();

	GameManager::Inst()->Clean();

	return 0;
}

