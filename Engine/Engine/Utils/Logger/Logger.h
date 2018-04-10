#pragma once
#include "GTypes.h"
#include "Sink.h"
#include "P7_Trace.h"
#include "Engine/Utils/PreprocessorUtils.h"


enum ErrorType 
{
	ERR_TYPE_PROGRAMMING_ERROR = 0,
	ERR_TYPE_VALUE_ERROR,
	ERR_TYPE_SDL_ERROR,
	ERR_TYPE_ENGINE_ERROR,
	ERR_TYPE_MECHANICS_ERROR,
	ERR_TYPE_MAX_ERR_TYPES
};


#define DEFAULT_LOGGER BAICAL
#define DEFAULT_VERBOSITY EP7TRACE_LEVEL_INFO
#define DEFAULT_MODULE MAIN

/************************************************************************/
/*					       Using DEFAULT_MODULE                         */
/************************************************************************/

// using DEFAULT_LOGGER and DEFAULT_VERBOSITY 
#define LOG(fmt, ...) Log( DEFAULT_VERBOSITY, STRINGIZE(DEFAULT_LOGGER), STRINGIZE(DEFAULT_MODULE), __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );

// using DEFAULT_LOGGER
#define ILOG_ 2
#define WLOG_ 3
#define ELOG_ 4
#define CLOG_ 5

// using DEFAULT_VERBOSITY
#define _LOGC 6
#define _LOGB 7
#define _LOGF 8
#define _LOGA 9

// info verbosity
#define ILOGC 1
#define ILOGB 1
#define ILOGF 1
#define ILOGA 1

// warning verbosity
#define WLOGC 1
#define WLOGB 1
#define WLOGF 1
#define WLOGA 1

// error verbosity
#define ELOGC 1
#define ELOGB 1
#define ELOGF 1
#define ELOGA 1

// critical verbosity
#define CLOGC 1
#define CLOGB 1
#define CLOGF 1
#define CLOGA 1

/************************************************************************/
/*					       Using specific module                        */
/************************************************************************/

// using DEFAULT_LOGGER and DEFAULT_VERBOSITY 
#define _LOG_M 1

// using DEFAULT_LOGGER
#define ILOG_M 2
#define WLOG_M 3
#define ELOG_M 4
#define CLOG_M 5

// using DEFAULT_VERBOSITY
#define _LOGCM 6
#define _LOGBM 7
#define _LOGFM 8
#define _LOGAM 9

// info verbosity
#define ILOGCM 1
#define ILOGBM 1
#define ILOGFM 1
#define ILOGAM 1

// warning verbosity
#define WLOGCM 1
#define WLOGBM 1
#define WLOGFM 1
#define WLOGAM 1

// error verbosity
#define ELOGCM 1
#define ELOGBM 1
#define ELOGFM 1
#define ELOGAM 1

// critical verbosity
#define CLOGCM 1
#define CLOGBM 1
#define CLOGFM 1
#define CLOGAM 1

#define ERR(ERR_TYPE, fmt, ...) ERR_F(ERR_TYPE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__)
#define INFO(fmt, ...) INFO_F(__LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__)

void ERR_F(ErrorType eType, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...);
void INFO_F(tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...);

void Log( eP7Trace_Level verbosity, const std::string& loggerName, const std::string& moduleName, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt... );

class Logger
{
public:
	Logger();
	virtual ~Logger();

	struct LoggerData
	{
		IP7_Client*			m_client;
		IP7_Trace::hModule	m_defaultModule;
		IP7_Trace*			m_trace;
	};

	void AddSink(Sink* sink);
	void AddModuleName( const std::wstring& name ) { }
	void RegisterThreadName( const std::wstring& name, tUINT32 threadId = 0 );
	void UnregisterThreadName( tUINT32 threadId = 0 );

	int Init();

	std::vector<Sink*>			m_sinks;

	std::vector<LoggerData*>	m_loggers;

};

//extern LoggerManager* loggerManager;


void ShareLogger( Logger* logger );


void simple_printf( const wchar_t* fmt... );