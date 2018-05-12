#include "stdafx.h"
#include "TestLogger.h"
#include "conio.h"
#include "Engine/Utils/Utils.h"


void testLogger()
{
	int ret;
	loggerManager = new LoggerManager();
	BaicalSink* baicalSink = new BaicalSink();
	ConsoleSink* consoleSink = new ConsoleSink();

	loggerManager->AddSink( "BAICAL", baicalSink );
	loggerManager->AddSink( "CONSOLE", consoleSink );
	loggerManager->AddSink( "ALL", baicalSink );
	loggerManager->AddSink( "ALL", consoleSink );

	ret = loggerManager->Init();

	loggerManager->AddModule( MODULE_MOUSE );

	/* DEFAULT LOGGER, DEFAULT MODULE*/
	LOG( "test message %d\ndfsfsfsfsdf\nsfsdfsdf\nasdasd\n", 111 );
	LOG( "test message %f", 111.111 );
	LOG( "test message %s", L"asdasdasdasd" );

	LOG( "test message %d %d", 111, 222 );
	LOG( "test message %f %f", 111.111, 222.222 );
	LOG( "test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOG( "test message %d", 111 );
	ILOG( "test message %f", 111.111 );
	ILOG( "test message %s", L"asdasdasdasd" );

	ILOG( "test message %d %d", 111, 222 );
	ILOG( "test message %f %f", 111.111, 222.222 );
	ILOG( "test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOG( "test message %d", 111 );
	WLOG( "test message %f", 111.111 );
	WLOG( "test message %s", L"asdasdasdasd" );

	WLOG( "test message %d %d", 111, 222 );
	WLOG( "test message %f %f", 111.111, 222.222 );
	WLOG( "test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOG( ERR_TYPE_PROGRAMMING_ERROR, "test message %d", 111 );
	ELOG( ERR_TYPE_PROGRAMMING_ERROR, "test message %f", 111.111 );
	ELOG( ERR_TYPE_PROGRAMMING_ERROR, "test message %s", L"asdasdasdasd" );

	ELOG( ERR_TYPE_PROGRAMMING_ERROR, "test message %d %d", 111, 222 );
	ELOG( ERR_TYPE_PROGRAMMING_ERROR, "test message %f %f", 111.111, 222.222 );
	ELOG( ERR_TYPE_PROGRAMMING_ERROR, "test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOG( "test message %d", 111 );
	CLOG( "test message %f", 111.111 );
	CLOG( "test message %s", L"asdasdasdasd" );

	CLOG( "test message %d %d", 111, 222 );
	CLOG( "test message %f %f", 111.111, 222.222 );
	CLOG( "test message %s %s", L"asdasdasdasd", L"eeeee" );

	/* DEFAULT LOGGER, specific module */

	LOGM( MODULE_MOUSE, "1test message %d", 111 );
	LOGM( MODULE_MOUSE, "1test message %f", 111.111 );
	LOGM( MODULE_MOUSE, "1test message %s", L"asdasdasdasd" );

	LOGM( MODULE_MOUSE, "1test message %d %d", 111, 222 );
	LOGM( MODULE_MOUSE, "1test message %f %f", 111.111, 222.222 );
	LOGM( MODULE_MOUSE, "1test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGM( MODULE_MOUSE, "1test message %d", 111 );
	ILOGM( MODULE_MOUSE, "1test message %f", 111.111 );
	ILOGM( MODULE_MOUSE, "1test message %s", L"asdasdasdasd" );

	ILOGM( MODULE_MOUSE, "1test message %d %d", 111, 222 );
	ILOGM( MODULE_MOUSE, "1test message %f %f", 111.111, 222.222 );
	ILOGM( MODULE_MOUSE, "1test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGM( MODULE_MOUSE, "1test message %d", 111 );
	WLOGM( MODULE_MOUSE, "1test message %f", 111.111 );
	WLOGM( MODULE_MOUSE, "1test message %s", L"asdasdasdasd" );

	WLOGM( MODULE_MOUSE, "1test message %d %d", 111, 222 );
	WLOGM( MODULE_MOUSE, "1test message %f %f", 111.111, 222.222 );
	WLOGM( MODULE_MOUSE, "1test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "1test message %d", 111 );
	ELOGM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "1test message %f", 111.111 );
	ELOGM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "1test message %s", L"asdasdasdasd" );

	ELOGM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "1test message %d %d", 111, 222 );
	ELOGM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "1test message %f %f", 111.111, 222.222 );
	ELOGM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "1test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGM( MODULE_MOUSE, "1test message %d", 111 );
	CLOGM( MODULE_MOUSE, "1test message %f", 111.111 );
	CLOGM( MODULE_MOUSE, "1test message %s", L"asdasdasdasd" );

	CLOGM( MODULE_MOUSE, "1test message %d %d", 111, 222 );
	CLOGM( MODULE_MOUSE, "1test message %f %f", 111.111, 222.222 );
	CLOGM( MODULE_MOUSE, "1test message %s %s", L"asdasdasdasd", L"eeeee" );

	/* Baical logger, DEFAULT MODULE */

	LOGB( "B test message %d", 111 );
	LOGB( "B test message %f", 111.111 );
	LOGB( "B test message %s", L"asdasdasdasd" );

	LOGB( "B test message %d %d", 111, 222 );
	LOGB( "B test message %f %f", 111.111, 222.222 );
	LOGB( "B test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGB( "B test message %d", 111 );
	ILOGB( "B test message %f", 111.111 );
	ILOGB( "B test message %s", L"asdasdasdasd" );

	ILOGB( "B test message %d %d", 111, 222 );
	ILOGB( "B test message %f %f", 111.111, 222.222 );
	ILOGB( "B test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGB( "B test message %d", 111 );
	WLOGB( "B test message %f", 111.111 );
	WLOGB( "B test message %s", L"asdasdasdasd" );

	WLOGB( "B test message %d %d", 111, 222 );
	WLOGB( "B test message %f %f", 111.111, 222.222 );
	WLOGB( "B test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGB( ERR_TYPE_PROGRAMMING_ERROR, "B test message %d", 111 );
	ELOGB( ERR_TYPE_PROGRAMMING_ERROR, "B test message %f", 111.111 );
	ELOGB( ERR_TYPE_PROGRAMMING_ERROR, "B test message %s", L"asdasdasdasd" );

	ELOGB( ERR_TYPE_PROGRAMMING_ERROR, "B test message %d %d", 111, 222 );
	ELOGB( ERR_TYPE_PROGRAMMING_ERROR, "B test message %f %f", 111.111, 222.222 );
	ELOGB( ERR_TYPE_PROGRAMMING_ERROR, "B test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGB( "B test message %d", 111 );
	CLOGB( "B test message %f", 111.111 );
	CLOGB( "B test message %s", L"asdasdasdasd" );

	CLOGB( "B test message %d %d", 111, 222 );
	CLOGB( "B test message %f %f", 111.111, 222.222 );
	CLOGB( "B test message %s %s", L"asdasdasdasd", L"eeeee" );

	/* Baical logger, specific module */

	LOGBM( MODULE_MOUSE, "BM test message %d", 111 );
	LOGBM( MODULE_MOUSE, "BM test message %f", 111.111 );
	LOGBM( MODULE_MOUSE, "BM test message %s", L"asdasdasdasd" );

	LOGBM( MODULE_MOUSE, "BM test message %d %d", 111, 222 );
	LOGBM( MODULE_MOUSE, "BM test message %f %f", 111.111, 222.222 );
	LOGBM( MODULE_MOUSE, "BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGBM( MODULE_MOUSE, "BM test message %d", 111 );
	ILOGBM( MODULE_MOUSE, "BM test message %f", 111.111 );
	ILOGBM( MODULE_MOUSE, "BM test message %s", L"asdasdasdasd" );

	ILOGBM( MODULE_MOUSE, "BM test message %d %d", 111, 222 );
	ILOGBM( MODULE_MOUSE, "BM test message %f %f", 111.111, 222.222 );
	ILOGBM( MODULE_MOUSE, "BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGBM( MODULE_MOUSE, "BM test message %d", 111 );
	WLOGBM( MODULE_MOUSE, "BM test message %f", 111.111 );
	WLOGBM( MODULE_MOUSE, "BM test message %s", L"asdasdasdasd" );

	WLOGBM( MODULE_MOUSE, "BM test message %d %d", 111, 222 );
	WLOGBM( MODULE_MOUSE, "BM test message %f %f", 111.111, 222.222 );
	WLOGBM( MODULE_MOUSE, "BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGBM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "BM test message %d", 111 );
	ELOGBM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "BM test message %f", 111.111 );
	ELOGBM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "BM test message %s", L"asdasdasdasd" );

	ELOGBM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "BM test message %d %d", 111, 222 );
	ELOGBM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "BM test message %f %f", 111.111, 222.222 );
	ELOGBM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGBM( MODULE_MOUSE, "BM test message %d", 111 );
	CLOGBM( MODULE_MOUSE, "BM test message %f", 111.111 );
	CLOGBM( MODULE_MOUSE, "BM test message %s", L"asdasdasdasd" );

	CLOGBM( MODULE_MOUSE, "BM test message %d %d", 111, 222 );
	CLOGBM( MODULE_MOUSE, "BM test message %f %f", 111.111, 222.222 );
	CLOGBM( MODULE_MOUSE, "BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	/* Console logger, DEFAULT_MODULE */

	LOGC( "C test message %d", 111 );
	LOGC( "C test message %f", 111.111 );
	LOGC( "C test message %s", L"asdasdasdasd" );

	LOGC( "C test message %d %d", 111, 222 );
	LOGC( "C test message %f %f", 111.111, 222.222 );
	LOGC( "C test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGC( "C test message %d", 111 );
	ILOGC( "C test message %f", 111.111 );
	ILOGC( "C test message %s", L"asdasdasdasd" );

	ILOGC( "C test message %d %d", 111, 222 );
	ILOGC( "C test message %f %f", 111.111, 222.222 );
	ILOGC( "C test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGC( "C test message %d", 111 );
	WLOGC( "C test message %f", 111.111 );
	WLOGC( "C test message %s", L"asdasdasdasd" );

	WLOGC( "C test message %d %d", 111, 222 );
	WLOGC( "C test message %f %f", 111.111, 222.222 );
	WLOGC( "C test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGC( ERR_TYPE_PROGRAMMING_ERROR, "C test message %d", 111 );
	ELOGC( ERR_TYPE_PROGRAMMING_ERROR, "C test message %f", 111.111 );
	ELOGC( ERR_TYPE_PROGRAMMING_ERROR, "C test message %s", L"asdasdasdasd" );

	ELOGC( ERR_TYPE_PROGRAMMING_ERROR, "C test message %d %d", 111, 222 );
	ELOGC( ERR_TYPE_PROGRAMMING_ERROR, "C test message %f %f", 111.111, 222.222 );
	ELOGC( ERR_TYPE_PROGRAMMING_ERROR, "C test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGC( "C test message %d", 111 );
	CLOGC( "C test message %f", 111.111 );
	CLOGC( "C test message %s", L"asdasdasdasd" );

	CLOGC( "C test message %d %d", 111, 222 );
	CLOGC( "C test message %f %f", 111.111, 222.222 );
	CLOGC( "C test message %s %s", L"asdasdasdasd", L"eeeee" );

	/* Console logger, specific module */

	LOGCM( MODULE_MOUSE, "CM test message %d", 111 );
	LOGCM( MODULE_MOUSE, "CM test message %f", 111.111 );
	LOGCM( MODULE_MOUSE, "CM test message %s", L"asdasdasdasd" );

	LOGCM( MODULE_MOUSE, "CM test message %d %d", 111, 222 );
	LOGCM( MODULE_MOUSE, "CM test message %f %f", 111.111, 222.222 );
	LOGCM( MODULE_MOUSE, "CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGCM( MODULE_MOUSE, "CM test message %d", 111 );
	ILOGCM( MODULE_MOUSE, "CM test message %f", 111.111 );
	ILOGCM( MODULE_MOUSE, "CM test message %s", L"asdasdasdasd" );

	ILOGCM( MODULE_MOUSE, "CM test message %d %d", 111, 222 );
	ILOGCM( MODULE_MOUSE, "CM test message %f %f", 111.111, 222.222 );
	ILOGCM( MODULE_MOUSE, "CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGCM( MODULE_MOUSE, "CM test message %d", 111 );
	WLOGCM( MODULE_MOUSE, "CM test message %f", 111.111 );
	WLOGCM( MODULE_MOUSE, "CM test message %s", L"asdasdasdasd" );

	WLOGCM( MODULE_MOUSE, "CM test message %d %d", 111, 222 );
	WLOGCM( MODULE_MOUSE, "CM test message %f %f", 111.111, 222.222 );
	WLOGCM( MODULE_MOUSE, "CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGCM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "CM test message %d", 111 );
	ELOGCM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "CM test message %f", 111.111 );
	ELOGCM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "CM test message %s", L"asdasdasdasd" );

	ELOGCM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "CM test message %d %d", 111, 222 );
	ELOGCM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "CM test message %f %f", 111.111, 222.222 );
	ELOGCM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGCM( MODULE_MOUSE, "CM test message %d", 111 );
	CLOGCM( MODULE_MOUSE, "CM test message %f", 111.111 );
	CLOGCM( MODULE_MOUSE, "CM test message %s", L"asdasdasdasd" );

	CLOGCM( MODULE_MOUSE, "CM test message %d %d", 111, 222 );
	CLOGCM( MODULE_MOUSE, "CM test message %f %f", 111.111, 222.222 );
	CLOGCM( MODULE_MOUSE, "CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	/* File loggers, specific module */

	// No testing for file loggers as logs can be exported on Baical server 


	/* File loggers, DEFAULT MODULE */

	// No testing for file loggers as logs can be exported on Baical server 


	/* All loggers, DEFAULT MODULE */

	LOGA( "A test message %d", 111 );
	LOGA( "A test message %f", 111.111 );
	LOGA( "A test message %s", L"asdasdasdasd" );

	LOGA( "A test message %d %d", 111, 222 );
	LOGA( "A test message %f %f", 111.111, 222.222 );
	LOGA( "A test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGA( "A test message %d", 111 );
	ILOGA( "A test message %f", 111.111 );
	ILOGA( "A test message %s", L"asdasdasdasd" );

	ILOGA( "A test message %d %d", 111, 222 );
	ILOGA( "A test message %f %f", 111.111, 222.222 );
	ILOGA( "A test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGA( "A test message %d", 111 );
	WLOGA( "A test message %f", 111.111 );
	WLOGA( "A test message %s", L"asdasdasdasd" );

	WLOGA( "A test message %d %d", 111, 222 );
	WLOGA( "A test message %f %f", 111.111, 222.222 );
	WLOGA( "A test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "A test message %d", 111 );
	ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "A test message %f", 111.111 );
	ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "A test message %s", L"asdasdasdasd" );

	ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "A test message %d %d", 111, 222 );
	ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "A test message %f %f", 111.111, 222.222 );
	ELOGA( ERR_TYPE_PROGRAMMING_ERROR, "A test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGA( "A test message %d", 111 );
	CLOGA( "A test message %f", 111.111 );
	CLOGA( "A test message %s", L"asdasdasdasd" );

	CLOGA( "A test message %d %d", 111, 222 );
	CLOGA( "A test message %f %f", 111.111, 222.222 );
	CLOGA( "A test message %s %s", L"asdasdasdasd", L"eeeee" );

	/* All loggers, specific module */

	LOGAM( MODULE_MOUSE, "AM test message %d", 111 );
	LOGAM( MODULE_MOUSE, "AM test message %f", 111.111 );
	LOGAM( MODULE_MOUSE, "AM test message %s", L"asdasdasdasd" );

	LOGAM( MODULE_MOUSE, "AM test message %d %d", 111, 222 );
	LOGAM( MODULE_MOUSE, "AM test message %f %f", 111.111, 222.222 );
	LOGAM( MODULE_MOUSE, "AM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGAM( MODULE_MOUSE, "AM test message %d", 111 );
	ILOGAM( MODULE_MOUSE, "AM test message %f", 111.111 );
	ILOGAM( MODULE_MOUSE, "AM test message %s", L"asdasdasdasd" );

	ILOGAM( MODULE_MOUSE, "AM test message %d %d", 111, 222 );
	ILOGAM( MODULE_MOUSE, "AM test message %f %f", 111.111, 222.222 );
	ILOGAM( MODULE_MOUSE, "AM test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGAM( MODULE_MOUSE, "AM test message %d", 111 );
	WLOGAM( MODULE_MOUSE, "AM test message %f", 111.111 );
	WLOGAM( MODULE_MOUSE, "AM test message %s", L"asdasdasdasd" );

	WLOGAM( MODULE_MOUSE, "AM test message %d %d", 111, 222 );
	WLOGAM( MODULE_MOUSE, "AM test message %f %f", 111.111, 222.222 );
	WLOGAM( MODULE_MOUSE, "AM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGAM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "AM test message %d", 111 );
	ELOGAM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "AM test message %f", 111.111 );
	ELOGAM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "AM test message %s", L"asdasdasdasd" );

	ELOGAM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "AM test message %d %d", 111, 222 );
	ELOGAM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "AM test message %f %f", 111.111, 222.222 );
	ELOGAM( MODULE_MOUSE, ERR_TYPE_PROGRAMMING_ERROR, "AM test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGAM( MODULE_MOUSE, "AM test message %d", 111 );
	CLOGAM( MODULE_MOUSE, "AM test message %f", 111.111 );
	CLOGAM( MODULE_MOUSE, "AM test message %s", L"asdasdasdasd" );

	CLOGAM( MODULE_MOUSE, "AM test message %d %d", 111, 222 );
	CLOGAM( MODULE_MOUSE, "AM test message %f %f", 111.111, 222.222 );
	CLOGAM( MODULE_MOUSE, "AM test message %s %s", L"asdasdasdasd", L"eeeee" );

	/* With logger parameter, DEFAULT MODULE */

	LOGTO( LOGGER_CONSOLE, "TO C test message %d", 111 );
	LOGTO( LOGGER_CONSOLE, "TO C test message %f", 111.111 );
	LOGTO( LOGGER_CONSOLE, "TO C test message %s", L"asdasdasdasd" );
	
	LOGTO( LOGGER_CONSOLE, "TO C test message %d %d", 111, 222 );
	LOGTO( LOGGER_CONSOLE, "TO C test message %f %f", 111.111, 222.222 );
	LOGTO( LOGGER_CONSOLE, "TO C test message %s %s", L"asdasdasdasd", L"eeeee" );

	LOGTO( LOGGER_BAICAL, "TO B test message %d", 111 );
	LOGTO( LOGGER_BAICAL, "TO B test message %f", 111.111 );
	LOGTO( LOGGER_BAICAL, "TO B test message %s", L"asdasdasdasd" );

	LOGTO( LOGGER_BAICAL, "TO B test message %d %d", 111, 222 );
	LOGTO( LOGGER_BAICAL, "TO B test message %f %f", 111.111, 222.222 );
	LOGTO( LOGGER_BAICAL, "TO B test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGTO( LOGGER_CONSOLE, "I TO C test message %d", 111 );
	ILOGTO( LOGGER_CONSOLE, "I TO C test message %f", 111.111 );
	ILOGTO( LOGGER_CONSOLE, "I TO C test message %s", L"asdasdasdasd" );

	ILOGTO( LOGGER_CONSOLE, "I TO C test message %d %d", 111, 222 );
	ILOGTO( LOGGER_CONSOLE, "I TO C test message %f %f", 111.111, 222.222 );
	ILOGTO( LOGGER_CONSOLE, "I TO C test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGTO( LOGGER_BAICAL, "I TO B test message %d", 111 );
	ILOGTO( LOGGER_BAICAL, "I TO B test message %f", 111.111 );
	ILOGTO( LOGGER_BAICAL, "I TO B test message %s", L"asdasdasdasd" );

	ILOGTO( LOGGER_BAICAL, "I TO B test message %d %d", 111, 222 );
	ILOGTO( LOGGER_BAICAL, "I TO B test message %f %f", 111.111, 222.222 );
	ILOGTO( LOGGER_BAICAL, "I TO B test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGTO( LOGGER_CONSOLE, "W TO C test message %d", 111 );
	WLOGTO( LOGGER_CONSOLE, "W TO C test message %f", 111.111 );
	WLOGTO( LOGGER_CONSOLE, "W TO C test message %s", L"asdasdasdasd" );

	WLOGTO( LOGGER_CONSOLE, "W TO C test message %d %d", 111, 222 );
	WLOGTO( LOGGER_CONSOLE, "W TO C test message %f %f", 111.111, 222.222 );
	WLOGTO( LOGGER_CONSOLE, "W TO C test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGTO( LOGGER_BAICAL, "W TO B test message %d", 111 );
	WLOGTO( LOGGER_BAICAL, "W TO B test message %f", 111.111 );
	WLOGTO( LOGGER_BAICAL, "W TO B test message %s", L"asdasdasdasd" );

	WLOGTO( LOGGER_BAICAL, "W TO B test message %d %d", 111, 222 );
	WLOGTO( LOGGER_BAICAL, "W TO B test message %f %f", 111.111, 222.222 );
	WLOGTO( LOGGER_BAICAL, "W TO B test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, "E TO C test message %d", 111 );
	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, "E TO C test message %f", 111.111 );
	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, "E TO C test message %s", L"asdasdasdasd" );

	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, "E TO C test message %d %d", 111, 222 );
	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, "E TO C test message %f %f", 111.111, 222.222 );
	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, "E TO C test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, "E TO B test message %d", 111 );
	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, "E TO B test message %f", 111.111 );
	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, "E TO B test message %s", L"asdasdasdasd" );

	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, "E TO B test message %d %d", 111, 222 );
	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, "E TO B test message %f %f", 111.111, 222.222 );
	ELOGTO( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, "E TO B test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGTO( LOGGER_CONSOLE, "C TO C test message %d", 111 );
	CLOGTO( LOGGER_CONSOLE, "C TO C test message %f", 111.111 );
	CLOGTO( LOGGER_CONSOLE, "C TO C test message %s", L"asdasdasdasd" );

	CLOGTO( LOGGER_CONSOLE, "C TO C test message %d %d", 111, 222 );
	CLOGTO( LOGGER_CONSOLE, "C TO C test message %f %f", 111.111, 222.222 );
	CLOGTO( LOGGER_CONSOLE, "C TO C test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGTO( LOGGER_BAICAL, "C TO B test message %d", 111 );
	CLOGTO( LOGGER_BAICAL, "C TO B test message %f", 111.111 );
	CLOGTO( LOGGER_BAICAL, "C TO B test message %s", L"asdasdasdasd" );

	CLOGTO( LOGGER_BAICAL, "C TO B test message %d %d", 111, 222 );
	CLOGTO( LOGGER_BAICAL, "C TO B test message %f %f", 111.111, 222.222 );
	CLOGTO( LOGGER_BAICAL, "C TO B test message %s %s", L"asdasdasdasd", L"eeeee" );

	/* With logger parameter, specific module */

	LOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "TO CM test message %d", 111 );
	LOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "TO CM test message %f", 111.111 );
	LOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "TO CM test message %s", L"asdasdasdasd" );

	LOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "TO CM test message %d %d", 111, 222 );
	LOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "TO CM test message %f %f", 111.111, 222.222 );
	LOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "TO CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	LOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "TO BM test message %d", 111 );
	LOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "TO BM test message %f", 111.111 );
	LOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "TO BM test message %s", L"asdasdasdasd" );

	LOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "TO BM test message %d %d", 111, 222 );
	LOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "TO BM test message %f %f", 111.111, 222.222 );
	LOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "TO BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "I TO CM test message %d", 111 );
	ILOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "I TO CM test message %f", 111.111 );
	ILOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "I TO CM test message %s", L"asdasdasdasd" );

	ILOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "I TO CM test message %d %d", 111, 222 );
	ILOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "I TO CM test message %f %f", 111.111, 222.222 );
	ILOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "I TO CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ILOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "I TO BM test message %d", 111 );
	ILOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "I TO BM test message %f", 111.111 );
	ILOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "I TO BM test message %s", L"asdasdasdasd" );

	ILOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "I TO BM test message %d %d", 111, 222 );
	ILOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "I TO BM test message %f %f", 111.111, 222.222 );
	ILOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "I TO BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "W TO CM test message %d", 111 );
	WLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "W TO CM test message %f", 111.111 );
	WLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "W TO CM test message %s", L"asdasdasdasd" );

	WLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "W TO CM test message %d %d", 111, 222 );
	WLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "W TO CM test message %f %f", 111.111, 222.222 );
	WLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "W TO CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	WLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "W TO BM test message %d", 111 );
	WLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "W TO BM test message %f", 111.111 );
	WLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "W TO BM test message %s", L"asdasdasdasd" );

	WLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "W TO BM test message %d %d", 111, 222 );
	WLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "W TO BM test message %f %f", 111.111, 222.222 );
	WLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "W TO BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, MODULE_MOUSE, "E TO CM test message %d", 111 );
	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, MODULE_MOUSE, "E TO CM test message %f", 111.111 );
	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, MODULE_MOUSE, "E TO CM test message %s", L"asdasdasdasd" );

	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, MODULE_MOUSE, "E TO CM test message %d %d", 111, 222 );
	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, MODULE_MOUSE, "E TO CM test message %f %f", 111.111, 222.222 );
	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_CONSOLE, MODULE_MOUSE, "E TO CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, MODULE_MOUSE, "E TO BM test message %d", 111 );
	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, MODULE_MOUSE, "E TO BM test message %f", 111.111 );
	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, MODULE_MOUSE, "E TO BM test message %s", L"asdasdasdasd" );

	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, MODULE_MOUSE, "E TO BM test message %d %d", 111, 222 );
	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, MODULE_MOUSE, "E TO BM test message %f %f", 111.111, 222.222 );
	ELOGTOM( ERR_TYPE_PROGRAMMING_ERROR, LOGGER_BAICAL, MODULE_MOUSE, "E TO BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "C TO CM test message %d", 111 );
	CLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "C TO CM test message %f", 111.111 );
	CLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "C TO CM test message %s", L"asdasdasdasd" );

	CLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "C TO CM test message %d %d", 111, 222 );
	CLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "C TO CM test message %f %f", 111.111, 222.222 );
	CLOGTOM( LOGGER_CONSOLE, MODULE_MOUSE, "C TO CM test message %s %s", L"asdasdasdasd", L"eeeee" );

	CLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "C TO BM test message %d", 111 );
	CLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "C TO BM test message %f", 111.111 );
	CLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "C TO BM test message %s", L"asdasdasdasd" );

	CLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "C TO BM test message %d %d", 111, 222 );
	CLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "C TO BM test message %f %f", 111.111, 222.222 );
	CLOGTOM( LOGGER_BAICAL, MODULE_MOUSE, "C TO BM test message %s %s", L"asdasdasdasd", L"eeeee" );

	_getch();
}
