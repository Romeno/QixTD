#pragma once

enum ConfigError {
	CONFIG_ERROR_OK = 0,
	CONFIG_ERROR_FAIL,
	CONFIG_ERROR_MAX,
};


class Config
{
public:
	Config(std::string filename);
	~Config();


	ConfigError Read();
	virtual void Parse(std::ifstream& strm);


	std::string		m_filename;
	int qq;
};

