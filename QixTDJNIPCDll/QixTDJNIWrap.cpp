// JNIStub.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "JNI/com_romeno_QixTD.h"

#include "Engine/GameManager.h"
#include "Mechanics/Qix/Qix.h"
#include "QixTD/QixTD.h"


JNIEXPORT jint JNICALL Java_com_romeno_QixTD_Start( JNIEnv *, jclass )
{
	gameManager = new GameManager();
	jint ret = (jint) (gameManager->Init( new QixTD() ) );
	if ( ret )
	{
		return ret;
	}

	gameManager->MainLoop();

	return 0;
}

