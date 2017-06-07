#pragma once
#include "Defines.h"

#ifdef LINE_CASCADE_GAME_TYPE

#include "Singleton.h"
#include "PlayerController.h"


class LineCascadePC : public PlayerController
{
public:
	LineCascadePC();
	~LineCascadePC();

	void Tick(Uint32 diff);
	void Render();
	void DrawLines();
	void ClearLines();
	void AddLine();
	void AddLineOnDistFromCenter();

	std::vector<glm::dvec3>		m_wpStart;
	std::vector<glm::dvec3>		m_wpEnd;

	int							m_primitivecount;

	float						m_maxLineLength;
	float						m_maxDistanceFromCenter;

	glm::dvec3					m_wPos;
};


#endif