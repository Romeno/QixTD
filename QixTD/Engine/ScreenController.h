#pragma once


class ScreenController
{
public:
	ScreenController();
	virtual ~ScreenController();

	virtual void Init(glm::dvec3 worldPos);
	virtual void Tick(Uint32 diff);

	glm::dvec3 GetWPos();

protected:
	glm::dvec3 m_screenWPos;
};

