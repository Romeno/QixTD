#include "stdafx.h"
#include "Game.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Components/Drawable.h"
#include "Engine/Components/Controlling/Playable.h"
#include "Engine/Components/TextComponent.h"
#include "Engine/InputHandler.h"
#include "Engine/Camera.h"


static int s_res = 0;


Game::Game()
	: m_quit(false)

	, m_entities()
{

}


Game::~Game()
{

}


int Game::Init()
{
	__ic__( Input()->Init() );

	__ic__( Camera_()->Init() );

	return 0;
}


void Game::PreTick( Uint32 diff )
{
	for ( auto it = m_entities.begin(); it != m_entities.end(); it++ )
	{
		(*it)->PreTick( diff );
	}
}


void Game::Tick(Uint32 diff)
{
	Input()->Tick(diff);

	for (auto it = m_entities.begin(); it != m_entities.end(); it++)
	{
		(*it)->Tick(diff);
	}

	Camera_()->Tick( diff );
}


void Game::PostTick( Uint32 diff )
{
	for ( auto it = m_entities.begin(); it != m_entities.end(); it++ )
	{
		(*it)->PostTick( diff );
	}
}


void Game::Render()
{

	//	//SDL_Point imagePos = { (vpWidth - imageLength) / 2, (vpHeight - imageHeight) / 2 };
	//
	//#ifdef PLATFORMER_GAME_TYPE
	//	LeafRain::Inst()->Render(true);
	//#endif
	//
	//
	//#ifdef PLATFORMER_GAME_TYPE
	//	LeafRain::Inst()->Render(false);
	//#endif



	std::sort(m_entities.begin(), m_entities.end(), 
		[](Entity* one, Entity* two) 
		{ 
			return (one->m_real->IsAbsolutePosition() ? one->m_real->GetPos().z + 100000 : one->m_real->GetPos().z) 
				< (two->m_real->IsAbsolutePosition() ? two->m_real->GetPos().z  + 100000 : two->m_real->GetPos().z);
		}
	);

	for (auto it = m_entities.begin(); it != m_entities.end(); it++)
	{
		if ((*it)->m_malui)
		{
			(*it)->m_malui->Render();
		}

		if ( (*it)->m_nadpis )
		{
			(*it)->m_nadpis->Render();
		}
	}

	// 	DrawTextBlock("fonts/Snap.ttf", "Hello World", 24);




	//renderTexture(image, renderer, x, y);

	//glClearColor(0.5, 1.0, 1.0, 0);
	//glClear(GL_COLOR_BUFFER_BIT);

	//GLuint shader = glCreateShader(GL_VERTEX_SHADER);
}


void Game::Quit()
{
	ILOGB( "Quit" );

	m_quit = true;
}


// std::vector<Collision*> Game::GetCollisions(Sprite* which)
// {
// 	std::vector<Collision*> ret;
// 
// 	//std::for_each(m_drawables.begin(), m_drawables.end(), [&ret](auto d) { if (d)  });
// 
// 	return ret;
// }


void Game::RemovePhase()
{
	auto start = std::remove_if(m_entities.begin(), m_entities.end(), [](auto d) { if (d->m_removed) { SafeDelete(d); } return d->m_removed; });
	if (start != m_entities.end())
	{
		//std::for_each(start + 1, m_drawables.end(), [](auto d) { SafeDelete(d); });
		m_entities.erase(start, m_entities.end());
	}
}


Entity* Game::CreateEntity()
{
	Entity* e = new Entity();
	m_entities.push_back(e);
	return e;
}


void Game::DeleteEntity(Entity* d)
{
	auto it = std::find_if(m_entities.begin(), m_entities.end(), [d](Entity* found) { return found->m_id == d->m_id; });
	m_entities.erase(it);

	//if (d->m_rozum && dynamic_cast<Playable*>(d->m_rozum) != nullptr)
	//{
	//	auto it = std::find_if(m_playerControlled.begin(), m_playerControlled.end(), [d](Entity* found) { return found->m_id == d->m_id; });
	//	m_playerControlled.erase(it);
	//}

	delete (*it);
}





