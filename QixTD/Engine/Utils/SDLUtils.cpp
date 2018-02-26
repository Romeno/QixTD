#include "stdafx.h"
#include "SDLUtils.h"



std::string GetSDLVersionString(const SDL_version& version)
{
	return std::to_string(version.major) + "." + std::to_string(version.minor) + "." + std::to_string(version.patch);
}
