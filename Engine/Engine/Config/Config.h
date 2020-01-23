#pragma once


enum ConfigError
{
	CONFIG_ERROR_OK = 0,
	CONFIG_ERROR_FAIL,
	CONFIG_ERROR_MAX,
};


class Config
{
public:
	Config();
	virtual ~Config();

	//virtual void Parse(std::ifstream& strm);

    static glm::dvec3 ParseVector2(const std::string& str);
	static std::string ParseString(const std::string& str);
	static int ParseInt(const std::string& str);
	static double ParseDouble( const std::string& str );
	static bool ParseBool( const std::string& str );

	static glm::dvec3 JsonListParseVector2( const std::string& str );

	//std::string		m_filename;
};


std::vector<double> GlmVec2StdVec( glm::dvec3 v );
glm::dvec3 StdVec2GlmVec( std::vector<double> v );