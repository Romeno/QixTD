#include "stdafx.h"
#include "PlayerConfig.h"
#include "Engine/Utils/Utils.h"


PlayerConfig::PlayerConfig()
	: super()

	//, m_playerVelocity(0.)
	//, m_playerVelocityKey("velocity")
{

}


PlayerConfig::~PlayerConfig()
{

}


//void PlayerConfig::Parse(std::ifstream& strm)
//{
//	std::vector<std::string> parts;
//	std::string s;
//	char line[255];
//	while (!strm.eof()) {
//		strm.getline(line, 255);
//		s = line;
//		s = pys::strip(s);
//
//		if ( s.empty() )
//			continue;
//
//		pys::split(s, parts, "=", 1);
//
//		parts[0] = pys::strip(parts[0]);
//		//if (parts[0] == m_playerVelocityKey) {
//		//	parts[1] = pys::strip(parts[1]);
//
//  //          m_playerVelocity = ParseDouble(parts[1]);
//		//} 
//		//else
//		//{
//          // TODO: add error handling
//          ELOG( ERR_TYPE_VALUE_ERROR, "Parse error." );
//		//}
//	}
//}
