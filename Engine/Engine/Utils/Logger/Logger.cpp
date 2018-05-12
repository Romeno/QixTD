#include "stdafx.h"
#include "Logger.h"
#include "Engine/Utils/Utils.h"


extern LoggerManager* loggerManager = nullptr;


LoggerManager::LoggerManager()
	: m_loggers()
	, m_traces()

	, m_inited(false)
{

}


LoggerManager::~LoggerManager()
{

}


void LoggerManager::AddSink( const std::string& loggerName, Sink* sink )
{
	if ( m_loggers.find( loggerName ) == m_loggers.end() )
	{
		m_loggers[loggerName] = std::vector<Trace*>();
	}

	Trace* trace = nullptr;
	auto itTrace = std::find_if( m_traces.begin(), m_traces.end(), [sink]( auto pTrace ) { return pTrace->m_sink == sink; } );
	if (itTrace != m_traces.end() )
	{
		trace = *itTrace;
	}
	else
	{
		trace = new Trace();
		trace->m_sink = sink;
		m_traces.push_back( trace );
	}
	
	m_loggers[loggerName].push_back( trace );
}


void LoggerManager::AddModule( const std::wstring& moduleName )
{
	if ( !m_inited )
	{
		std::cout << "LOGGER ERROR: AddModule should be called after Init" << std::endl;
	}

	for ( auto it = m_traces.begin(); it != m_traces.end(); it++ )
	{
		Trace* trace = (*it);

		trace->m_modules[moduleName] = nullptr;
		trace->m_trace->Register_Module( moduleName.c_str(), &(trace->m_modules[moduleName]) );
	}
}


int LoggerManager::Init()
{
	P7_Set_Crash_Handler();

	for ( auto it = m_traces.begin(); it != m_traces.end(); it++ )
	{
		Trace* trace = (*it);
		std::wstring initString = trace->m_sink->GetP7InitString();

		trace->m_client = P7_Create_Client( initString.c_str() );
		if ( NULL == trace->m_client )
		{
			return 1;
		}

		trace->m_trace = P7_Create_Trace( trace->m_client, trace->m_traceName.c_str() );
		if ( NULL == trace->m_trace )
		{
			trace->m_client->Release();
			trace->m_client = NULL;
			return 1;
		}

		trace->m_trace->Register_Thread( TM( "Application" ), 0 );
	}

	m_inited = true;

	AddModule( TM( "MAIN" ) );

	return 0;
}


void LoggerManager::Log( eP7Trace_Level verbosity, const std::string& loggerName, const std::wstring& moduleName, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt... )
{
	if ( !m_inited )
	{
		std::cout << "LOGGER ERROR: LoggerManager is not Initialized!" << std::endl;
	}

	va_list args;
	va_start( args, fmt );

	std::vector<Trace*>& traces = m_loggers[loggerName];
	for ( auto it = traces.begin(); it != traces.end(); it++ )
	{
		Trace* trace = (*it);

		auto itModule = trace->m_modules.find( moduleName );
		if ( itModule == trace->m_modules.end() )
		{
			std::cout << "LOGGER ERROR: module name " << Wstr2Str( moduleName ) << " is unknown!" << std::endl;
		}

		if ( trace->m_sink->GetUseCout() )
		{
			vwprintf( fmt, args );
			printf( "\n" );
		}
		else
		{
			trace->m_trace->Trace_Embedded( 0, verbosity, itModule->second, line, i_pFile, i_pFunction, &fmt, &args );
		}
	}

	va_end( args );
}


void LoggerManager::LogError( eP7Trace_Level verbosity, const std::string& loggerName, const std::wstring& moduleName, ErrorType eType, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt... )
{
	if ( !m_inited )
	{
		std::cout << "LOGGER ERROR: LoggerManager is not Initialized!" << std::endl;
	}

	va_list args;
	va_start( args, fmt );

	const wchar_t* errHeader = nullptr;

	if ( eType == ERR_TYPE_PROGRAMMING_ERROR )
	{
		errHeader = L"ProgrammingError:";
	}
	else if ( eType == ERR_TYPE_VALUE_ERROR )
	{
		errHeader = L"ValueError:";
	}
	else if ( eType == ERR_TYPE_SDL_ERROR )
	{
		errHeader = L"SDLError:";
	}
	else if ( eType == ERR_TYPE_ENGINE_ERROR )
	{
		errHeader = L"EngineError:";
	}
	else
	{
		errHeader = L"UnknownErrType:";
	}

	std::vector<Trace*>& traces = m_loggers[loggerName];
	for ( auto it = traces.begin(); it != traces.end(); it++ )
	{
		Trace* trace = (*it);

		auto itModule = trace->m_modules.find( moduleName );
		if ( itModule == trace->m_modules.end() )
		{
			std::cout << "LOGGER ERROR: module name " << Wstr2Str( moduleName ) << " is unknown!" << std::endl;
		}

		if ( trace->m_sink->GetUseCout() )
		{
			wprintf( errHeader );
			printf( "\n" );
			vwprintf( fmt, args );
			printf( "\n" );
		}
		else
		{
			trace->m_trace->Trace_Embedded( 0, EP7TRACE_LEVEL_ERROR, itModule->second, line, i_pFile, i_pFunction, &errHeader );
			trace->m_trace->Trace_Embedded( 0, EP7TRACE_LEVEL_ERROR, itModule->second, line, i_pFile, i_pFunction, &fmt, &args );
		}
	}

	va_end( args );
}


Trace::Trace()
	: m_sink(nullptr)

	, m_client(nullptr)
	, m_defaultModule(nullptr)
	, m_trace(nullptr)
	, m_traceName( TM("GAME") )

	, m_registeredThreads()
{

}


Trace::~Trace()
{

}


void Trace::SetTraceName( const std::wstring& name )
{
	m_traceName = name;
}


void Trace::RegisterThreadName( const std::wstring& name, tUINT32 threadId /*= 0 */ )
{
	if ( std::find( m_registeredThreads.begin(), m_registeredThreads.end(), threadId ) == m_registeredThreads.end() )
	{
		m_trace->Register_Thread( name.c_str(), threadId );
		m_registeredThreads.push_back( threadId );
	}
}


void Trace::UnregisterThreadName( tUINT32 threadId /*= 0 */ )
{
	if ( std::find( m_registeredThreads.begin(), m_registeredThreads.end(), threadId ) != m_registeredThreads.end() )
	{
		m_trace->Unregister_Thread( threadId );
		m_registeredThreads.erase( std::remove( m_registeredThreads.begin(), m_registeredThreads.end(), threadId ), m_registeredThreads.end() );
	}
}


void simple_printf( const wchar_t* fmt... )
{
	va_list args;
	va_start( args, fmt );

	while ( *fmt != '\0' ) {
		if ( *fmt == 'd' ) {
			int i = va_arg( args, int );
			std::cout << i << '\n';
		}
		else if ( *fmt == 'c' ) {
			// note automatic conversion to integral type
			int c = va_arg( args, int );
			std::cout << static_cast<char>(c) << '\n';
		}
		else if ( *fmt == 'f' ) {
			double d = va_arg( args, double );
			std::cout << d << '\n';
		}
		++fmt;
	}

	va_end( args );
}

