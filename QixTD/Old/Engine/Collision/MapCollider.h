#pragma once
#include "Engine/Collision/RectCollider.h"


class MapCollider : public RectCollider
{
public:
	MapCollider();
	virtual ~MapCollider();

	std::string			m_filename;
};

