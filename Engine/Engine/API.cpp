#include "stdafx.h"
#include "API.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Game.h"
#include "Engine/Entity.h"
#include "Engine/Components/Drawing/Sprite.h"
#include "Engine/Components/Controlling/Playable.h"
#include "Engine/Components/UI/UIButton.h"
#include "Engine/Components/Physics/SimplePhysicsComponent.h"
#include "Engine/Cache/FontCache.h"


#define GAME (GameManager::Inst()->m_game)


DEFINE_SINGLETON( API )


API::API()
{

}


API::~API()
{

}


Entity* API::CreateEntity()
{
	return GAME->CreateEntity();
}


void API::DeleteEntity(Entity* e)
{
	GAME->DeleteEntity(e);
}


//void API::Play(Entity* e)
//{
//	Playable* p = new Playable();
//
//	e->AddComponent(p);
//
//	p->Init();
//}


Entity* API::CreateSprite(const std::string& path, glm::dvec3 wpos, glm::dvec3 size, Direction dir)
{
	Entity* e = CreateEntity();

	Sprite* malui = new Sprite();
	malui->SetImage(path);
	e->AddComponent(malui);

	SimplePhysicsComponent* real = new SimplePhysicsComponent();
	real->SetSize( size );
	real->SetWPos( wpos );
	real->SetDirection( dir );
	e->AddComponent( real );

	e->Init();

	return e;
}


Entity* API::CreateColoredRect(glm::ivec4 color, glm::dvec3 wpos, glm::dvec3 size)
{
	Entity* e = CreateEntity();

	Sprite* malui = new Sprite();
	malui->SetColor( color );
	e->AddComponent(malui);

	SimplePhysicsComponent* real = new SimplePhysicsComponent();
	real->SetSize( size );
	real->SetWPos( wpos );
	e->AddComponent( real );

	e->Init();

	return e;
}


Entity* API::CreateButton(glm::dvec3 wpos, glm::dvec3 size, const std::string& text)
{
	Entity* e = CreateEntity();

	SimplePhysicsComponent* real = new SimplePhysicsComponent();
	real->SetSize( size );
	real->SetWPos( wpos );
	e->AddComponent( real );

	//Drawable* malui = new Sprite();
	//e->AddComponent(malui);

	//UIButton* button = new UIButton();
	//button->SetText(text);
	//e->AddComponent(button);

	//e->SetSize(size);
	//e->SetWPos(wpos);
	//e->m_absolutePosition = true;

	return e;
}


void API::DrawTextBlock( glm::dvec3 pos, glm::dvec3 size, const std::string& fontPath, const std::string& str, int pointSize, SDL_Color color )
{
	TTF_Font* font = FontCache::Inst()->GetFont(GetResourcePath() + fontPath, pointSize);

	//TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24); //this opens a font style and sets a size

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, str.c_str(), color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* Message = SDL_CreateTextureFromSurface(REN, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = pos.x;  //controls the rect's x coordinate 
	Message_rect.y = pos.y; // controls the rect's y coordinte
	Message_rect.w = size.x; // controls the width of the rect
	Message_rect.h = size.y; // controls the height of the rect

						  //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

						  //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

	SDL_RenderCopy(REN, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

													   //Don't forget too free your surface and texture
}






