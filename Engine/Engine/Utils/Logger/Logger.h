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


class Trace
{
public:
	Trace();
	~Trace();

	void SetTraceName( const std::wstring& name );

	/* Untested */
	void RegisterThreadName( const std::wstring& name, tUINT32 threadId = 0 );
	/* Untested */
	void UnregisterThreadName( tUINT32 threadId = 0 );

	Sink*				m_sink;

	IP7_Client*			m_client;
	IP7_Trace::hModule	m_defaultModule;
	IP7_Trace*			m_trace;
	std::wstring		m_traceName;

	std::vector<tUINT32>						m_registeredThreads;
	std::map<std::wstring, IP7_Trace::hModule>  m_modules;
};


class LoggerManager
{
public:
	LoggerManager();
	~LoggerManager();

	// should not be called once Init is done
	void AddSink( const std::string& loggerName, Sink* sink );

	// should be called after Init
	void AddModule(const std::wstring& moduleName);

	int Init();

	void Log( eP7Trace_Level verbosity, const std::string& loggerName, const std::wstring& moduleName, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt... );
	void LogError( eP7Trace_Level verbosity, const std::string& loggerName, const std::wstring& moduleName, ErrorType eType, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt... );

	std::map<std::string, std::vector<Trace*> >	m_loggers;
	std::vector<Trace*>							m_traces;

	bool	m_inited;
};

extern LoggerManager* loggerManager;


void simple_printf( const wchar_t* fmt... );