#pragma once
#include "Engine/CoordinateSystem.h"
#include "Engine/Components/PhysicsComponent.h"


#define REALP if (m_real) m_real
#define MALUI if (m_malui) m_malui
#define NADPIS if (m_nadpis) m_nadpis
#define ROZUM if (m_rozum) m_rozum
#define UI if (m_ui) m_ui
#define MIAJA if (m_miaja) m_miaja


class Drawable;
class TextComponent;
class Controllable;
class UIComponent;
class Collidable;


class Entity
{
public:
	Entity();
	Entity(const Entity& other);
	Entity& operator=(const Entity& other);
	virtual ~Entity();

	virtual int Init();
#pragma region Init
	int Init_Real();
	int Init_Malui();
	int Init_Nadpis();
	int Init_Kirui();
	int Init_Ui();
	int Init_Miaja();
#pragma endregion

	virtual void Tick(Uint32 diff);
	virtual void Remove();
	//virtual void Clear();

	virtual void SetTimeToLive(Uint32 seconds);

	glm::dvec3 GetShootPos();

	template <class T>
	void AddComponent(T* component);

	Entity*				m_parent;

	Uint32				m_startTime;
	Uint32				m_timeToLive;

	std::string			m_name;

	int					m_id;

	bool				m_removed;

	bool				m_absolutePosition;

	PhysicsComponent*	m_real;
	Drawable*			m_malui;
	TextComponent*		m_nadpis;
	Controllable*		m_rozum;
	UIComponent*		m_ui;
	Collidable*			m_miaja;

private:
	bool RemoveIfElapsed();
	void Move();

};

