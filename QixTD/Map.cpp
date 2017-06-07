#include "stdafx.h"
#include "Map.h"


Map::Map()
	: Config("map1")
{

}


Map::~Map()
{

}


void Map::Parse(std::ifstream& strm)
{
	std::vector<std::string> parts;
	std::string s;
	char line[255];
	while (!strm.eof()) {
		strm.getline(line, 255);
		s = line;
		parts[0] = pys::strip(parts[0]);
		pys::split(s, parts, "=", 1);

		//if (parts[0] == m_windowTitleKey) {
		//	parts[1] = pys::strip(parts[1]);
		//	m_windowTitle = parts[1];
		//}
	}
}
