#pragma once
#include "Engine/ScreenController.h"


class QixSC : public ScreenController
{
public:
	QixSC();
	virtual ~QixSC();

	virtual void Tick(Uint32 diff);

	int m_scrollWidth;
	int m_scrollSpeed;
};

