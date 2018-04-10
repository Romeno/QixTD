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
#include "Engine/Components/UI/Sensors/MouseInputSensor.h"


#define GAME (gameManager->m_game)

extern Api* api = nullptr;

//DEFINE_SINGLETON( API )


Api::Api()
{

}


Api::~Api()
{

}


Entity* Api::CreateEntity()
{
	return GAME->CreateEntity();
}


void Api::DeleteEntity(Entity* e)
{
	GAME->DeleteEntity(e);
}


//void Api::Play(Entity* e)
//{
//	Playable* p = new Playable();
//
//	e->AddComponent(p);
//
//	p->Init();
//}


Entity* Api::CreateSprite(const std::string& path, glm::dvec3 wpos, glm::dvec3 size, Direction dir)
{
	Entity* e = CreateEntity();

	Sprite* malui = new Sprite();
	malui->SetImage(path);
	e->AddComponent(malui);
	malui->m_originalData->m_visualSize = size;

	SimplePhysicsComponent* real = new SimplePhysicsComponent();
	real->SetSize( size );
	real->SetPos( wpos );
	real->SetDir( dir );
	e->AddComponent( real );

	e->Init();

	return e;
}


Entity* Api::CreateColoredRect(glm::ivec4 color, glm::dvec3 wpos, glm::dvec3 size)
{
	Entity* e = CreateEntity();

	Sprite* malui = new Sprite();
	malui->SetColor( color );
	e->AddComponent(malui);

	SimplePhysicsComponent* real = new SimplePhysicsComponent();
	real->SetSize( size );
	real->SetPos( wpos );
	e->AddComponent( real );

	e->Init();

	return e;
}


Entity* Api::CreateButton(glm::dvec3 wpos, glm::dvec3 size, const std::string& text)
{
	Entity* e = CreateEntity();

	SimplePhysicsComponent* real = new SimplePhysicsComponent();
	real->SetAbsolutePosition( true );
	real->SetSize( size );
	real->SetPos( wpos );
	e->AddComponent( real );

	Sprite* malui = new Sprite();
	malui->SetImage("UI/Button.png");
	e->AddComponent(malui);
	malui->m_originalData->m_visualSize = size;

	UIButton* button = new UIButton();
	
	//button->SetText(text);
	e->AddComponent(button);
	button->SetSensor( new MouseInputSensor(button) );

	//e->SetSize(size);
	//e->SetWPos(wpos);
	//e->m_absolutePosition = true;

	e->Init();

	return e;
}


void Api::DrawTextBlock( glm::dvec3 pos, glm::dvec3 size, const std::string& fontPath, const std::string& str, int pointSize, SDL_Color color )
{
	TTF_Font* font = fontCache->GetFont(GetResourcePath() + fontPath, pointSize);

	SDL_Surface* surfaceMessage = TTF_RenderText_Shaded( font, str.c_str(), color, { 128, 128, 128 } ); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* message = SDL_CreateTextureFromSurface(REN, surfaceMessage); //now you can convert it into a texture

	int w, h;
	int res = TTF_SizeText( font, str.c_str(), &w, &h );

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = pos.x;  //controls the rect's x coordinate 
	Message_rect.y = pos.y; // controls the rect's y coordinte
	Message_rect.w = w; // controls the width of the rect
	Message_rect.h = h; // controls the height of the rect

						  //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

						  //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

	SDL_RenderCopy(REN, message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

													   //Don't forget too free your surface and texture
}






