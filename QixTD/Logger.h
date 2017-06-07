#pragma once
#include "GTypes.h"

enum ErrorType 
{
	ERR_TYPE_PROGRAMMING_ERROR = 0,
	ERR_TYPE_VALUE_ERROR,
	ERR_TYPE_SDL_ERROR,
	ERR_TYPE_ENGINE_ERROR,
	ERR_TYPE_MAX_ERR_TYPES
};

int InitLogger();

#define ERR(ERR_TYPE, fmt, ...) ERR_F(ERR_TYPE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__)
#define INFO(fmt, ...) INFO_F(__LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__)

void ERR_F(ErrorType eType, tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...);
void INFO_F(tUINT16 line, const char *i_pFile, const char *i_pFunction, const wchar_t* fmt...);


//#include "P7_Trace.h"
//class IP7_Trace;
//
//IP7_Trace* GetLogger();
//IP7_Trace::hModule GetModule();