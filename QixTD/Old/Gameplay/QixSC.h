#pragma once
#include "Engine/Camera.h"


class QixSC : public Camera
{
public:
	QixSC();
	virtual ~QixSC();

	virtual void Tick(Uint32 diff);

	int m_scrollWidth;
	int m_scrollSpeed;
};

