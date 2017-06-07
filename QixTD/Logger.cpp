#include "stdafx.h"
#include "Logger.h"
#include "P7_Trace.h"


IP7_Trace::hModule	l_hModule = NULL;
IP7_Trace*			logger = NULL;


int InitLogger()
{
	IP7_Client        *l_pClient = NULL;

	tUINT8             l_bTID1 = 0;
	tUINT8             l_bTID2 = 0;
	tUINT32            l_dwIdx = 0;

	P7_Set_Crash_Handler();

	//create P7 client object
	l_pClient = P7_Create_Client(TM("/P7.Pool=32768 /P7.Sink=Console /P7.Format=\"%ix: %td: %lv: %ms\""));
	if (NULL == l_pClient)
	{
		return 1;
	}

	//create P7 trace object 1
	logger = P7_Create_Trace(l_pClient, TM("Trace channel 1"));
	if (NULL == logger)
	{
		l_pClient->Release();
		l_pClient = NULL;
		return 1;
	}

	logger->Register_Thread(TM("Application"), 0);
	logger->Register_Module(TM("Main"), &l_hModule);

	//logger->Share(L"Standard");

	return 0;
}


void ERR_F(ErrorType eType, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...)
{
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

	logger->Trace_Embedded(0, EP7TRACE_LEVEL_ERROR, l_hModule, line, i_pFile, i_pFunction, &errHeader);
	logger->Trace_Embedded(0, EP7TRACE_LEVEL_ERROR, l_hModule, line, i_pFile, i_pFunction, &fmt, &args);

	va_end(args);
}


void INFO_F(tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...)
{
	va_list args;
	va_start(args, fmt);

	logger->Trace_Embedded(0, EP7TRACE_LEVEL_INFO, l_hModule, line, i_pFile, i_pFunction, &fmt, &args);

	va_end(args);
}


















IP7_Trace* GetLogger()
{
	return logger;
}


IP7_Trace::hModule GetModule()
{
	return l_hModule;
}


void simple_printf(const wchar_t* fmt...)
{
	va_list args;
	va_start(args, fmt);

	while (*fmt != '\0') {
		if (*fmt == 'd') {
			int i = va_arg(args, int);
			std::cout << i << '\n';
		}
		else if (*fmt == 'c') {
			// note automatic conversion to integral type
			int c = va_arg(args, int);
			std::cout << static_cast<char>(c) << '\n';
		}
		else if (*fmt == 'f') {
			double d = va_arg(args, double);
			std::cout << d << '\n';
		}
		++fmt;
	}

	va_end(args);
}