#pragma once
#include "Engine/Utils/Singleton.h"


class DebugOutputManager : public Singleton<DebugOutputManager>
{
public:
	DebugOutputManager();
	~DebugOutputManager();

	std::string fontPath;
	std::string fontSize;
	

};

