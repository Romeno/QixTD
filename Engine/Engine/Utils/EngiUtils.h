#pragma once



#define REN gameManager->ren
#define WIN gameManager->win
#define VP_HEIGHT gameManager->vpHeight
#define VP_WIDTH gameManager->vpWidth


#define __ic__(call) s_res = call; if (s_res) return s_res;


void DebugOutput( const std::string& text );












std::string GetResourcePath(const std::string &subDir = "");






