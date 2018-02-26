#pragma once
#include "GTypes.h"
#include "Sink.h"
#include "P7_Trace.h"


enum ErrorType 
{
	ERR_TYPE_PROGRAMMING_ERROR = 0,
	ERR_TYPE_VALUE_ERROR,
	ERR_TYPE_SDL_ERROR,
	ERR_TYPE_ENGINE_ERROR,
	ERR_TYPE_MECHANICS_ERROR,
	ERR_TYPE_MAX_ERR_TYPES
};


#define ERR(ERR_TYPE, fmt, ...) ERR_F(ERR_TYPE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__)
#define INFO(fmt, ...) INFO_F(__LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__)

void ERR_F(ErrorType eType, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...);
void INFO_F(tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...);


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


void ShareLogger( Logger* logger );


void simple_printf( const wchar_t* fmt... );