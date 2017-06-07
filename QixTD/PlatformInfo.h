#pragma once
#include "Rect.h"
#include "Entity.h"


class PlatformInfo: public Entity
{
public:
	PlatformInfo();
	virtual ~PlatformInfo() override;


	virtual int Init() override;
	virtual void Render() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Clear() override;

	std::vector<Rect>			m_platforms;
	SDL_Texture*				m_platformTex;
};

