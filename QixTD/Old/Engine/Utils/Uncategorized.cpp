#include "stdafx.h"
#include "Uncategorized.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Text/FontManager.h"


/*
* Get the resource path for resources located in res/subDir
* It's assumed the project directory is structured like:
* bin/
*  the executable
* res/
*  Lesson1/
*  Lesson2/
*
* Paths returned will be Lessons/res/subDir
*/
std::string GetResourcePath(const std::string &subDir) {
	//We need to choose the path separator properly based on which
	//platform we're running on, since Windows uses a different
	//separator than most systems
#ifdef _WIN32
	const char PATH_SEP = '\\';
#else
	const char PATH_SEP = '/';
#endif
	//This will hold the base resource path: Lessons/res/
	//We give it static lifetime so that we'll only need to call
	//SDL_GetBasePath once to get the executable path
	static std::string baseRes;
	if (baseRes.empty()) {
		//SDL_GetBasePath will return NULL if something went wrong in retrieving the path
		char *basePath = SDL_GetBasePath();
		if (basePath) {
			baseRes = basePath;
			SDL_free(basePath);
		}
		else {
			std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
			return "";
		}
		////We replace the last bin/ with res/ to get the the resource path
		//size_t pos = baseRes.rfind("bin");
		//baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
		baseRes = baseRes + "res" + PATH_SEP;
	}
	//If we want a specific subdirectory path in the resource directory
	//append it to the base path. This would be something like Lessons/res/Lesson0
	return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
}


void DrawTextBlock(const std::string& fontPath, const std::string& str, int pointSize, SDL_Color color)
{
	TTF_Font* font = FontCache::Inst()->GetFont(GetResourcePath() + fontPath, pointSize);

	//TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24); //this opens a font style and sets a size

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, str.c_str(), color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* Message = SDL_CreateTextureFromSurface(REN, surfaceMessage); //now you can convert it into a texture

	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = 0; // controls the rect's y coordinte
	Message_rect.w = 100; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect

						  //Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance

						  //Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes

	SDL_RenderCopy(REN, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

															//Don't forget too free your surface and texture
}


std::string GetSDLVersionString(const SDL_version& version)
{
	return std::to_string(version.major) + "." + std::to_string(version.minor) + "." + std::to_string(version.patch);
}
