#pragma once
#include "Engine/Components/Drawable.h"


class LineDrawable : public Drawable
{
public:
	typedef Drawable super;
		
	LineDrawable();
	virtual ~LineDrawable();
	
	virtual int Init() override;
	virtual void Tick( Uint32 diff ) override;
	virtual void Render() override;

	virtual glm::drect GetVisualAABB() override;
	virtual glm::drect GetSelectionRegion() override;
};

