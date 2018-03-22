#include "stdafx.h"
#include "MapConfigStub.h"


MapConfigStub::MapConfigStub(const std::string& id)
    : super(id)

    , m_mapDimensionsKey("MapDimensions")
    , m_mapDimensions(0, 0, 0)

    , m_playerStartPosKey("PlayerStartPos")
    , m_playerStartPos(0, 0, 0)
{

}


MapConfigStub::~MapConfigStub()
{

}

void MapConfigStub::Parse(std::ifstream& strm)
{
    std::vector<std::string> parts;
    std::string s;
    char line[255];
    while (!strm.eof()) {
        strm.getline(line, 255);
        s = line;
        s = pys::strip(s);

		if ( s.empty() )
			continue;

        pys::split(s, parts, "=", 1);

		parts[0] = pys::strip(parts[0]);
        if (parts[0] == m_mapDimensionsKey) {
        	parts[1] = pys::strip(parts[1]);

            m_mapDimensions = ParseVector2(parts[1]);
        }
        else if (parts[0] == m_playerStartPosKey) {
            parts[1] = pys::strip(parts[1]);

            m_playerStartPos = ParseVector2(parts[1]);
        }
		else
		{
			throw "shit";
		}
    }
}