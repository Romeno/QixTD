#pragma once
#include "Drawable.h"


class LineCascade : public Drawable
{
public:
	LineCascade(const std::string& name);
	~LineCascade();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Clear() override;
	virtual void Render() override;

	void AddLine(glm::dvec3 wPos1, glm::dvec3 wPos2);

	typedef std::pair<glm::dvec3, glm::dvec3> Line;

	std::vector<Line>	m_lines;
	glm::ivec4			m_color;

	const int		m_borderZ;
	void Moved(glm::dvec3 to);
};

