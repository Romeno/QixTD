#pragma once



#define REN GameManager::Inst()->ren
#define WIN GameManager::Inst()->win
#define VP_HEIGHT GameManager::Inst()->vpHeight
#define VP_WIDTH GameManager::Inst()->vpWidth


#define __ic__(call) s_res = call; if (s_res) return s_res;















std::string GetResourcePath(const std::string &subDir = "");






