#include "stdafx.h"
#include "Logger.h"


static Logger* s_logger = nullptr;
void ShareLogger( Logger* logger )
{
	s_logger = logger;
}


void ERR_F(ErrorType eType, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...)
{
	if ( !s_logger )
	{
		std::cout << "Logger is not shared" << std::endl;
	}

	va_list args;
	va_start(args, fmt);

	const wchar_t* errHeader = nullptr;
	
	if (eType == ERR_TYPE_PROGRAMMING_ERROR) 
	{
		errHeader = L"ProgrammingError:";
	} 
	else if (eType == ERR_TYPE_VALUE_ERROR) 
	{
		errHeader = L"ValueError:";
	}
	else if (eType == ERR_TYPE_SDL_ERROR)
	{
		errHeader = L"SDLError:";
	}
	else if (eType == ERR_TYPE_ENGINE_ERROR)
	{
		errHeader = L"EngineError:";
	}
	else 
	{
		errHeader = L"UnknownErrType:";
	}

	for ( auto it = s_logger->m_loggers.begin(); it != s_logger->m_loggers.end(); it++ )
	{
		(*it)->m_trace->Trace_Embedded( 0, EP7TRACE_LEVEL_ERROR, (*it)->m_defaultModule, line, i_pFile, i_pFunction, &errHeader );
		(*it)->m_trace->Trace_Embedded( 0, EP7TRACE_LEVEL_ERROR, (*it)->m_defaultModule, line, i_pFile, i_pFunction, &fmt, &args );
	}

	va_end(args);
}


void INFO_F(tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...)
{
	if ( !s_logger )
	{
		std::cout << "Logger is not shared" << std::endl;
	}

	va_list args;
	va_start(args, fmt);

	for ( auto it = s_logger->m_loggers.begin(); it != s_logger->m_loggers.end(); it++ )
	{
		(*it)->m_trace->Trace_Embedded( 0, EP7TRACE_LEVEL_INFO, (*it)->m_defaultModule, line, i_pFile, i_pFunction, &fmt, &args );
	}
	
	va_end(args);
}


Logger::Logger()
	: m_sinks()
	, m_loggers()
{

}


Logger::~Logger()
{

}


void Logger::AddSink( Sink* sink )
{
	m_sinks.push_back( sink );
}


void Logger::RegisterThreadName( const std::wstring& name, tUINT32 threadId )
{
	for ( auto it = m_loggers.begin(); it != m_loggers.end(); it++ )
	{
		(*it)->m_trace->Register_Thread( name.c_str(), threadId );
	}
}


void Logger::UnregisterThreadName( tUINT32 threadId )
{
	for ( auto it = m_loggers.begin(); it != m_loggers.end(); it++ )
	{
		(*it)->m_trace->Unregister_Thread( threadId );
	}
}


int Logger::Init()
{
	P7_Set_Crash_Handler();

	for ( auto it = m_sinks.begin(); it != m_sinks.end(); it++ )
	{
		std::wstring initString = (*it)->GetP7InitString();

		LoggerData* ld = new LoggerData();
		ld->m_client = P7_Create_Client( initString.c_str() );
		if ( NULL == ld->m_client )
		{
			return 1;
		}

		ld->m_trace = P7_Create_Trace( ld->m_client, (*it)->m_traceName.c_str() );
		if ( NULL == ld->m_trace )
		{
			ld->m_client->Release();
			ld->m_client = NULL;
			return 1;
		}

		ld->m_trace->Register_Thread( TM( "Application" ), 0 );
		ld->m_trace->Register_Module( TM( "Main" ), &ld->m_defaultModule );

		m_loggers.push_back( ld );


		//IP7_Client        *l_pClient = NULL;

		////create P7 client object
		//l_pClient = P7_Create_Client( TM( "/P7.Pool=32768 /P7.Sink=Console /P7.Format=\"%ix: %td: %lv: %ms\"" ) );
		//if ( NULL == l_pClient )
		//{
		//	return 1;
		//}

		//tUINT8             l_bTID1 = 0;
		//tUINT8             l_bTID2 = 0;
		//tUINT32            l_dwIdx = 0;

		////create P7 trace object 1
		//logger = P7_Create_Trace( l_pClient, TM( "Trace channel 1" ) );
		//if ( NULL == logger )
		//{
		//	l_pClient->Release();
		//	l_pClient = NULL;
		//	return 1;
		//}

		//logger->Register_Thread( TM( "Application" ), 0 );
		//logger->Register_Module( TM( "Main" ), &l_hModule );

		//logger->Share(L"Standard");
	}
	
	return 0;
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