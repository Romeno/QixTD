#pragma once
#include "Defines.h"

#if POINT_SPLASH_GAME_TYPE == 1 || LINE_CASCADE_GAME_TYPE == 1

#include "ScreenController.h"

class PointSplashSC : public ScreenController
{
public:
	PointSplashSC();
	virtual ~PointSplashSC();

	virtual void Tick(Uint32 diff);

	int m_scrollWidth;
	int m_scrollSpeed;
};

#endif