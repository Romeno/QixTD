#pragma once
#include "Entity.h"


class DrawableRect;


class DrawableController : public Entity
{
public:
	DrawableController(const std::string& name);
	virtual ~DrawableController();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;

	virtual void Possess(DrawableRect* d);

	DrawableRect*		m_drawable;
};

