#pragma once
#include "Engine/Camera.h"


class TetrisCamera : public Camera
{
public:
	typedef Camera super;

	TetrisCamera();
	virtual ~TetrisCamera();

	virtual int Init();
};

