#include "stdafx.h"
#include "Entity.h"
#include "Engine/GameManager.h"
#include "Engine/Components/Drawable.h"
#include "Engine/Components/TextComponent.h"
#include "Engine/Components/UIComponent.h"
#include "Engine/Components/Controlling/Playable.h"
#include "Engine/Components/Collidable.h"
#include "Engine/Components/PhysicsComponent.h"
#include "Engine/Utils/Utils.h"
#include "Math/Math.h"


static int ID_COUNTER = 0;

static int s_res = 0;


Entity::Entity()
	: m_parent(nullptr)

// 	, m_wPos(0, 0, 0)
// 	, m_size( 0, 0, 0 )
// 	, m_direction(0, 0, 0)
// 
// 	, m_velocity( 0. )

	, m_startTime(0)
	, m_timeToLive(0)
	
	, m_name()

	, m_id(ID_COUNTER++)

	, m_removed(false)

	, m_absolutePosition(false)

	, m_real(nullptr)
	, m_malui(nullptr)
	, m_nadpis(nullptr)
	, m_rozum(nullptr)
	, m_ui(nullptr)
	, m_miaja(nullptr)

	, m_firstTickHappened(false)
{

}


Entity::Entity(const Entity& other)
	: m_parent(other.m_parent)

// 	, m_wPos(other.m_wPos)
// 	, m_size( other.m_size )
// 	, m_direction(other.m_direction)
// 	, m_velocity( other.m_velocity )

	, m_startTime(other.m_startTime)
	, m_timeToLive(other.m_timeToLive)


	, m_name(other.m_name)

	, m_id(ID_COUNTER++)

	, m_removed(other.m_removed)

	, m_absolutePosition(other.m_absolutePosition)

	, m_real(other.m_real)
	, m_malui(other.m_malui)
	, m_nadpis(other.m_nadpis)
	, m_rozum(other.m_rozum)
	, m_ui(other.m_ui)
	, m_miaja(other.m_miaja)
{

}


Entity& Entity::operator=(const Entity& other)
{
	m_parent = other.m_parent;

// 	m_wPos = other.m_wPos;
// 	m_size = other.m_size;
// 	m_direction = other.m_direction;
// 	m_velocity = other.m_velocity;

	m_startTime = other.m_startTime;
	m_timeToLive = other.m_timeToLive;
       
	m_name = other.m_name;
       
	m_id = ID_COUNTER++;
       
	m_removed = other.m_removed;
       
	m_absolutePosition = other.m_absolutePosition;
    
	m_real = other.m_real;
	m_malui = other.m_malui;
	m_nadpis = other.m_nadpis;
	m_rozum = other.m_rozum;
	m_ui = other.m_ui;
	m_miaja = other.m_miaja;

	return (*this);
}


Entity::~Entity()
{
	del( m_real );
	del( m_malui );
	del( m_nadpis );
	del( m_rozum );
	del( m_ui );
	del( m_miaja );
}


int Entity::Init()
{
	if ( m_real )
	{
		__ic__( Init_Real() );
	}

	if ( m_malui )
	{
		__ic__( Init_Malui() );
	}

	if ( m_nadpis )
	{
		__ic__( Init_Nadpis() );
	}

	if ( m_rozum )
	{
		__ic__( Init_Kirui() );
	}

	if ( m_ui )
	{
		__ic__( Init_Ui() );
	}

	if ( m_miaja )
	{
		__ic__( Init_Miaja() );
	}

	return 0;
}


int Entity::Init_Real()
{
	__ic__( m_real->Init() );

	return 0;
}


int Entity::Init_Malui()
{
	__ic__( m_malui->Init() );

	return 0;
}


int Entity::Init_Nadpis()
{
	__ic__( m_nadpis->Init() );

	return 0;
}


int Entity::Init_Kirui()
{
	__ic__( m_rozum->Init() );

	return 0;
}


int Entity::Init_Ui()
{
	__ic__( m_ui->Init() );

	return 0;
}


int Entity::Init_Miaja()
{
	__ic__( m_miaja->Init() );

	return 0;
}


void Entity::PreTick( Uint32 diff )
{
	if ( RemoveIfElapsed() )
		return;

	ROZUM->PreTick( diff );

	UI->PreTick( diff );

	MIAJA->PreTick( diff );

	NADPIS->PreTick( diff );

	MALUI->PreTick( diff );
}


void Entity::Tick(Uint32 diff)
{
	m_firstTickHappened = true;

	if ( RemoveIfElapsed() )
		return;

	ROZUM->Tick( diff );

	UI->Tick( diff );

	MIAJA->Tick( diff );

	NADPIS->Tick( diff );

	MALUI->Tick( diff );
}


void Entity::PostTick( Uint32 diff )
{
	if ( RemoveIfElapsed() )
		return;

	ROZUM->PostTick( diff );

	UI->PostTick( diff );

	MIAJA->PostTick( diff );

	NADPIS->PostTick( diff );

	MALUI->PostTick( diff );
}


void Entity::Remove()
{
	m_removed = true;
}


void Entity::SetTimeToLive(Uint32 seconds)
{
	m_startTime = SDL_GetTicks();

	m_timeToLive = seconds * 1000;
}


bool Entity::RemoveIfElapsed()
{
	if (m_removed)
		return m_removed;

	if (m_timeToLive && (m_timeToLive + m_startTime < SDL_GetTicks()))
	{
		m_removed = true;
		return true;
	}

	return false;
}


//void Entity::Clear()
//{
//
//}

//
//bool Entity::lessThan(const Entity& other) const
//{
//	return m_id < other.m_id;
//}
//
//
//bool operator<(const Entity& one, const Entity& two)
//{
//	return one.lessThan(two);
//}


glm::dvec3 Entity::GetShootPos()
{
	return ::GetRectShootPos(m_real->GetPos(), m_real->GetPos(), Vec2Dir(m_real->GetDir()));
}


template <>
void Entity::AddComponent(Drawable* component)
{
	//SafeDelete( m_malui );

	m_malui = component;
	component->m_object = this;
}


template <>
void Entity::AddComponent(TextComponent* component)
{
	//SafeDelete( m_nadpis );

	m_nadpis = component;
	component->m_object = this;
}


template <>
void Entity::AddComponent(Controllable* component)
{
	//SafeDelete( m_rozum );

	m_rozum = component;
	component->m_object = this;
}


template <>
void Entity::AddComponent(Playable* component)
{
	//SafeDelete( m_rozum );

	m_rozum = component;
	component->m_object = this;
}


template <>
void Entity::AddComponent(UIComponent* component)
{
	//SafeDelete( m_ui );

	m_ui = component;
	component->m_object = this;
}


template <>
void Entity::AddComponent(Collidable* component)
{
	//SafeDelete( m_miaja );

	m_miaja = component;
	component->m_object = this;
}




