#pragma once


#define CAMERA GameManager::Inst()->m_game->Camera_()


class Camera;
class InputHandler;
class Entity;


class Game
{
public:
	Game();
	virtual ~Game();


	virtual int Init();
	virtual void Tick(Uint32 diff);
	virtual void Render();

	virtual InputHandler*	Input() = 0;
	virtual Camera*			Camera_() = 0;

// 	std::vector<Collision*> Game::GetCollisions(Sprite* which);

	Entity* CreateEntity();
	void DeleteEntity(Entity* d);

	virtual int LoadLevel(int num) = 0;
	void Quit();


	bool						m_quit;

	std::vector<Entity*>		m_entities;


protected:
	void RemovePhase();

};

