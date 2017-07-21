#pragma once
#include "DrawableController.h"


class AIController : public DrawableController
{
public:
	AIController(const std::string& name);
	virtual ~AIController();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
};

