#pragma once
#include "Engine/Camera.h"


class QixCamera : public Camera
{
public:
	typedef Camera super;

	QixCamera();
	virtual ~QixCamera();

	virtual void Tick(Uint32 diff);

	int m_scrollWidth;
	int m_scrollSpeed;
};

