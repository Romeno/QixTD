#pragma once
#include "Engine/Components/Drawable.h"


class LineCascade : public Drawable
{
public:
	typedef Drawable super;

	LineCascade();
	//LineCascade(const LineCascade& other);
	////LineCascade(LineCascade&& other);
	//LineCascade& operator=(const LineCascade& other);
	virtual ~LineCascade();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Render() override;
	virtual glm::drect GetVisualAABB() override;
	virtual glm::drect GetSelectionRegion() override;

	void NotifyMovement(glm::dvec3 to);

	void AddLine(glm::dvec3 wPos1, glm::dvec3 wPos2);

	typedef std::pair<glm::dvec3, glm::dvec3> Line;

	std::vector<Line>	m_lines;
	glm::ivec4			m_color;

	const int		m_borderZ;
};

