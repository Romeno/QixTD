#pragma once
#ifndef __SYSTEM_INFO__H__
#include "Engine/Utils/Utils.h"


void LogInfo(SDL_Window* win, SDL_Renderer* ren, const char* logger = DEFAULT_LOGGER, const wchar_t* loggerModule = MODULE_GENERIC_INFO );

void LogCustomInfo( const char* logger, const wchar_t* loggerModule );
void LogFilesystemH( const char* logger, const wchar_t* loggerModule );
void LogAvailableRenderers( const char* logger, const wchar_t* loggerModule );
void LogVideoH(SDL_Window* win, const char* logger, const wchar_t* loggerModule );
void LogRenderH(SDL_Window* win, SDL_Renderer* ren, const char* logger, const wchar_t* loggerModule );
void LogAudioH( const char* logger, const wchar_t* loggerModule );
void LogKeyboardH(SDL_Window* win, const char* logger, const wchar_t* loggerModule );
void ListenKeyboardH( SDL_Window* win, const char* logger, const wchar_t* loggerModule );
void LogMouseH( const char* logger, const wchar_t* loggerModule );
void LogTouchH( const char* logger, const wchar_t* loggerModule );
void LogTimerH( const char* logger, const wchar_t* loggerModule );
void LogEventsH( const char* logger, const wchar_t* loggerModule );
void LogCpuinfoH( const char* logger, const wchar_t* loggerModule );
void LogPowerH( const char* logger, const wchar_t* loggerModule );
void LogSystemH( const char* logger, const wchar_t* loggerModule );
void LogClipboardH( const char* logger, const wchar_t* loggerModule );
void LogPlatformH( const char* logger, const wchar_t* loggerModule );
void LogTTFH( const std::string& fontPath, const char* logger, const wchar_t* loggerModule );

void LogKeyboardEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule );
void LogTextEditingEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule );
void LogTextInputEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule );
void LogMouseButtonEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule );
void LogMouseWheelEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule );
void LogMouseMotionEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule );
void LogGenericEvent( SDL_Event* e, const char* logger, const wchar_t* loggerModule );
void LogWindowEvent( SDL_Event* e, const char* logger, const wchar_t* loggerModule );

//void LogEventType(Uint32 eventType, const char* logger, const wchar_t* loggerModule);
//void LogWindowEventType( SDL_WindowEventID windowEventId, const char* logger, const wchar_t* loggerModule );

void LogDisplayModeInfo(SDL_DisplayMode& mode, const char* logger, const wchar_t* loggerModule );
void LogPixelFormatInfo(Uint32 pixelFormat, const char* logger, const wchar_t* loggerModule );
void LogWindowFlags(Uint32 flags, const char* logger, const wchar_t* loggerModule );
void LogRendererInfo(SDL_RendererInfo* info, const char* logger, const wchar_t* loggerModule );

void LogSDLTtfVersion( const char* logger, const wchar_t* loggerModule );

std::string AudioStatus2Str( SDL_AudioStatus s );
std::string PowerState2Str( SDL_PowerState s );
std::string EventType2Str( SDL_EventType eventType );
std::string WindowEventType2Str( SDL_WindowEventID windowEventId );
std::string FontStyle2Str( int style );
std::string FontHintning2Str( int hinting );

std::string SDLVersion2Str( const SDL_version* ver );

#endif // __SYSTEM_INFO__H__