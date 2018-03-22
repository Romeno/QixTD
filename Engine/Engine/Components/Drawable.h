#pragma once
#include "Engine/Entity.h"
#include "Engine/Component.h"
#include "Engine/CoordinateSystem.h"
#include "Math/Math.h"


class Drawable : public Component
{
public:
	typedef Component super;

	Drawable();
	Drawable(const Drawable& other);
	Drawable& operator=(const Drawable& other);
	virtual ~Drawable() override;

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Render() = 0;	

	virtual glm::drect GetVisualAABB() = 0;
};

