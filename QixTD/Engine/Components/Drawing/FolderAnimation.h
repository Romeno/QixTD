#pragma once
#include "Engine/Components/Drawing/AnimatedSprite.h"


class FolderAnimation : public AnimatedSprite
{
public:
	typedef AnimatedSprite super;

	FolderAnimation();
	virtual ~FolderAnimation();

	virtual void LoadFolder( const std::string& path );

	virtual int Init() override;
	virtual void Render() override;
	virtual void Tick( Uint32 diff ) override;

	std::string							m_folderPath;
};

