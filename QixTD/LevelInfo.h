#pragma once
#include "Singleton.h"


class LevelInfo : public Singleton<LevelInfo>
{
public:
	LevelInfo();
	~LevelInfo();


	void Init(int length, int height);


	int m_levelLength;
	int m_levelHeight;
};

