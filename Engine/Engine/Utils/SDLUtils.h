#pragma once


/*
* Recurse through the list of arguments to clean up, cleaning up
* the first one in the list each iteration.
*/
template<typename T, typename... Args>
void RemoveSDLObj(T *t, Args&&... args) {
	//Cleanup the first item in the list
	RemoveSDLObj(t);
	//Recurse to clean up the remaining arguments
	RemoveSDLObj(std::forward<Args>(args)...);
}


/*
* These specializations serve to free the passed argument and also provide the
* base cases for the recursive call above, eg. when args is only a single item
* one of the specializations below will be called by
* cleanup(std::forward<Args>(args)...), ending the recursion
* We also make it safe to pass nullptrs to handle situations where we
* don't want to bother finding out which values failed to load (and thus are null)
* but rather just want to clean everything up and let cleanup sort it out
*/
template<>
inline void RemoveSDLObj<SDL_Window>(SDL_Window *win) {
	if (!win) {
		return;
	}
	SDL_DestroyWindow(win);
}


template<>
inline void RemoveSDLObj<SDL_Renderer>(SDL_Renderer *ren) {
	if (!ren) {
		return;
	}
	SDL_DestroyRenderer(ren);
}


template<>
inline void RemoveSDLObj<SDL_Texture>(SDL_Texture *tex) {
	if (!tex) {
		return;
	}
	SDL_DestroyTexture(tex);
}


template<>
inline void RemoveSDLObj<SDL_Surface>(SDL_Surface *surf) {
	if (!surf) {
		return;
	}
	SDL_FreeSurface(surf);
}


template<>
inline void RemoveSDLObj<TTF_Font>(TTF_Font* font) {
	if (!font) {
		return;
	}
	TTF_CloseFont(font);
}


std::string GetSDLVersionString(const SDL_version& version);