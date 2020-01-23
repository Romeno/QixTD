#pragma once
#include "Engine/Config/Config.h"
#include "Math/Math.h"


class ArenaConfig :	public Config
{
public:
	typedef ArenaConfig thisT;
	typedef Config super;

	ArenaConfig();
	virtual ~ArenaConfig();

	static std::string				m_arenaDimensionsKey;
	static std::string				m_bgImageKey;
	static std::string				m_objectIdsKey;
	static std::string				m_objectPosKey;
	static std::string				m_objectDirsKey;
};

