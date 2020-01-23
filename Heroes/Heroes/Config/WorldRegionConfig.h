#pragma once
#include "Engine/Config/Config.h"
#include "Math/Math.h"


class WorldRegionConfig : public Config
{
public:
	typedef Config super;

	WorldRegionConfig( );
	virtual ~WorldRegionConfig();

	//virtual void Parse( std::ifstream& strm ) override;

	static std::string				m_regionDimensionsKey;
	static std::string				m_regionNameKey;
	static std::string				m_regionObjectIdsKey;
	static std::string				m_regionObjectPosKey;
	static std::string				m_regionObjectDirsKey;
};

