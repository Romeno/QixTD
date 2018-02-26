#pragma once


class Entity
{
public:
	Entity();
	Entity(const Entity& other);
	Entity& operator=(const Entity& other);
	virtual ~Entity();

	virtual int Init() = 0;
	virtual void Tick(Uint32 diff) = 0;
	virtual void Remove();
	//virtual void Clear();

	virtual void SetWPos(glm::dvec3 wPos, Pivot pivot = PIVOT_CENTER);

	virtual void SetDirection(glm::dvec3 dir);									
	virtual void SetDirection(Direction dir);
	virtual void SetMoveSpeed(double ms);

	virtual void SetTimeToLive(Uint32 seconds);

	glm::dvec3			m_wPos; // position of top left corner in World coordinates
	glm::dvec3			m_direction;

	glm::dvec3			m_size;

	Uint32				m_startTime;
	Uint32				m_timeToLive;

	double				m_moveSpeed;

	std::string			m_name;

	int					m_id;

	bool				m_removed;

	std::string			m_imagePath;

	SDL_Texture			*m_texture;

	std::string			m_text;
	std::string			m_font;
	int					m_fontSize;

private:
	bool RemoveIfElapsed();
	void Move();

};