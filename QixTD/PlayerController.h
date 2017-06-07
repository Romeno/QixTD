#pragma once



enum Pivot {
	PIVOT_CENTER = 0,
	PIVOT_MAX_PIVOTS,
};


class PlayerController
{
public:
	PlayerController();
	virtual ~PlayerController();

	virtual int Init();
	virtual void Render();
	virtual void Tick(Uint32 diff);
	virtual void Clear();

	virtual void SetWPos(glm::dvec3 plrWPos, Pivot pivot);
	virtual glm::dvec3 GetWPos();
};

