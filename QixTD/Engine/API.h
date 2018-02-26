#pragma once
#include "Engine/Entity.h"
#include "Engine/Utils/Singleton.h"
#include "Engine/Utils/CppUtils.h"



class API
{
public:
	API();
	virtual ~API();

	DECLARE_SINGLETON(API)

	// Raw
	virtual Entity* CreateEntity();
	virtual void DeleteEntity(Entity* e);


	// Control
	//virtual void Play(Entity* e);


	// Objects
	virtual Entity* CreateSprite(const std::string& path, glm::dvec3 wpos, glm::dvec3 size, Direction dir);
	virtual Entity* CreateColoredRect(glm::ivec4 color, glm::dvec3 wpos, glm::dvec3 size);


	// UI
	virtual Entity* CreateButton(glm::dvec3 wpos, glm::dvec3 size, const std::string& text);



	virtual void DrawTextBlock( glm::dvec3 pos, glm::dvec3 size, const std::string& fontPath, const std::string& str, int pointSize, SDL_Color color = { 255, 255, 255 });
};





