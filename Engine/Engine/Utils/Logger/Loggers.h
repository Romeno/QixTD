#pragma once
#include "Logger.h"

/*		LOGGERS	 	 */
#define LOGGER_CONSOLE "CONSOLE"
#define LOGGER_BAICAL "BAICAL"
#define LOGGER_FILE "FILE"
#define LOGGER_ALL "ALL"

#define DEFAULT_LOGGER LOGGER_CONSOLE

/* IF ADDING THIS ADD TO GameManager::InitLogger */
/*		MODULES	 	 */
#define MODULE_MAIN L"MAIN"
#define MODULE_MOUSE L"MOUSE"
#define MODULE_KEYBOARD L"KEYBOARD"
#define MODULE_GENERIC_INFO L"GENERIC INFO"
#define MODULE_WINDOW_EVENTS L"WINDOW EVENTS"
#define MODULE_TEXT L"TEXT"
#define MODULE_RENDER L"RENDER"


#define DEFAULT_MODULE MODULE_MAIN

/*     VERBOSITY     */
// will not log ERROR vebosity with LOG macro the same way as with ELOG* macros 
// if DEFAULT_VERBOSITY will be set to EP7TRACE_LEVEL_ERROR
#define DEFAULT_VERBOSITY EP7TRACE_LEVEL_INFO

/************************************************************************/
/*					       Using DEFAULT_MODULE                         */
/************************************************************************/

// KNOWN ISSUE: is that when you you same format message with different modules
// the module actually viewed on the server side will be the first module the server 
// has message acknowledged with such a format message
// E.g
// LOG("msg1 %s", str)
// LOGM(MODULE_MOUSE, "msg1 %s", str)
// the actual MODULE got output will be DEFAULT_MODULE because it was first
// As an effect of it ErrorType header for error messages will got output with the correct module
// This is the issue of P7 logging library


// using DEFAULT_LOGGER and DEFAULT_VERBOSITY 
#define LOG(fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, DEFAULT_LOGGER, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );

// using DEFAULT_LOGGER
#define ILOG(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, DEFAULT_LOGGER, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define WLOG(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, DEFAULT_LOGGER, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define ELOG(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, DEFAULT_LOGGER, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define CLOG(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, DEFAULT_LOGGER, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );

// using DEFAULT_VERBOSITY
#define LOGC(fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, LOGGER_CONSOLE, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define LOGB(fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, LOGGER_BAICAL, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define LOGF(fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, LOGGER_FILE, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define LOGA(fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, LOGGER_ALL, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );

// info verbosity
#define ILOGC(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, LOGGER_CONSOLE, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );     
#define ILOGB(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, LOGGER_BAICAL, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );      
#define ILOGF(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, LOGGER_FILE, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );        
#define ILOGA(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, LOGGER_ALL, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );         

// warning verbosity
#define WLOGC(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, LOGGER_CONSOLE, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );     
#define WLOGB(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, LOGGER_BAICAL, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );      
#define WLOGF(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, LOGGER_FILE, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );        
#define WLOGA(fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, LOGGER_ALL, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );         

// error verbosity
#define ELOGC(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, LOGGER_CONSOLE, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );     
#define ELOGB(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, LOGGER_BAICAL, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );      
#define ELOGF(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, LOGGER_FILE, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );        
#define ELOGA(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, LOGGER_ALL, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );         

// critical verbosity
#define CLOGC(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, LOGGER_CONSOLE, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );     
#define CLOGB(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, LOGGER_BAICAL, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );      
#define CLOGF(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, LOGGER_FILE, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );        
#define CLOGA(errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, LOGGER_ALL, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );         

// to specified logger
#define LOGTO(logger, fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, logger, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );

#define ILOGTO(logger, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, logger, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define WLOGTO(logger, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, logger, DEFAULT_MODULE, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define ELOGTO(errorType, logger, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, logger, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define CLOGTO(errorType, logger, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, logger, DEFAULT_MODULE, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );


/************************************************************************/
/*					       Using specific module                        */
/************************************************************************/

// KNOWN ISSUE: is that when you you same format message with different modules
// the module actually viewed on the server side will be the first module the server 
// has message acknowledged with such a format message
// E.g
// LOGM(MODULE_MOUSE, "msg1 %s", str)
// LOG("msg1 %s", str)
// the actual MODULE got output will be MODULE_MOUSE because it was first
// As an effect of it ErrorType header for error messages will got output with the correct module
// This is the issue of P7 logging library


// using DEFAULT_LOGGER and DEFAULT_VERBOSITY 
#define LOGM(module, fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, STRINGIZE(DEFAULT_LOGGER), module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );

// using DEFAULT_LOGGER
#define ILOGM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, DEFAULT_LOGGER, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );      
#define WLOGM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, DEFAULT_LOGGER, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );   
#define ELOGM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, DEFAULT_LOGGER, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );     
#define CLOGM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, DEFAULT_LOGGER, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );  

// using DEFAULT_VERBOSITY
#define LOGCM(module, fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, LOGGER_CONSOLE, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );       
#define LOGBM(module, fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, LOGGER_BAICAL, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );     
#define LOGFM(module, fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, LOGGER_FILE, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );         
#define LOGAM(module, fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, LOGGER_ALL, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );       

// info verbosity
#define ILOGCM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, LOGGER_CONSOLE, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );    
#define ILOGBM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, LOGGER_BAICAL, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );     
#define ILOGFM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, LOGGER_FILE, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );       
#define ILOGAM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, LOGGER_ALL, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );        

// warning verbosity
#define WLOGCM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, LOGGER_CONSOLE, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ ); 
#define WLOGBM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, LOGGER_BAICAL, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );  
#define WLOGFM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, LOGGER_FILE, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );    
#define WLOGAM(module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, LOGGER_ALL, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );     

// error verbosity
#define ELOGCM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, LOGGER_CONSOLE, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define ELOGBM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, LOGGER_BAICAL, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define ELOGFM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, LOGGER_FILE, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define ELOGAM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, LOGGER_ALL, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );

// critical verbosity
#define CLOGCM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, LOGGER_CONSOLE, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );  
#define CLOGBM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, LOGGER_BAICAL, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );   
#define CLOGFM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, LOGGER_FILE, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );     
#define CLOGAM(module, errorType, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, LOGGER_ALL, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );      

// to specified logger
#define LOGTOM(logger, module, fmt, ...) loggerManager->Log( DEFAULT_VERBOSITY, logger, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );

#define ILOGTOM(logger, module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_INFO, logger, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define WLOGTOM(logger, module, fmt, ...) loggerManager->Log( EP7TRACE_LEVEL_WARNING, logger, module, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define ELOGTOM(errorType, logger, module, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_ERROR, logger, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );
#define CLOGTOM(errorType, logger, module, fmt, ...) loggerManager->LogError( EP7TRACE_LEVEL_CRITICAL, logger, module, errorType, __LINE__, __FILE__, __FUNCTION__, L##fmt, __VA_ARGS__ );


