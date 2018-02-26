#pragma once
#ifndef __SYSTEM_INFO__H__


void PrintInfo(SDL_Window* win, SDL_Renderer* ren);

void PrintCustomInfo();
void PrintFilesystemH();
void PrintVideoH(SDL_Window* win);
void PrintRenderH(SDL_Window* win, SDL_Renderer* ren);
void PrintAudioH();
void PrintKeyboardH(SDL_Window* win);
void ListenKeyboardH( SDL_Window* win );
void PrintMouseH();
void PrintTouchH();
void PrintTimerH();
void PrintEventsH();
void PrintCpuinfoH();
void PrintPowerH();
void PrintSystemH();
void PrintClipboardH();
void PrintPlatformH();

void PrintKeyboardEvent(SDL_Event* e);
void PrintTextEditingEvent(SDL_Event* e);
void PrintTextInputEvent(SDL_Event* e);
void PrintMouseButtonEvent(SDL_Event* e);
void PrintMouseWheelEvent(SDL_Event* e);
void PrintMouseMotionEvent(SDL_Event* e);
void PrintGenericEvent( SDL_Event* e );
void PrintWindowEvent( SDL_Event* e );

void PrintMouseButtonNum(Uint8 mouseButton);
//void PrintEventType(Uint32 eventType);
//void PrintWindowEventType( SDL_WindowEventID windowEventId );
void PrintMouseWheelDirection(Uint32 mouseWheelDirection);
void PrintMouseButtonState(Uint32 state);

void PrintDisplayModeInfo(SDL_DisplayMode& mode);
void PrintPixelFormatInfo(Uint32 pixelFormat);
void PrintWindowFlags(Uint32 flags);
void PrintRendererInfo(SDL_RendererInfo* info);
void PrintAudioStatus(SDL_AudioStatus s);
void PrintPowerState(SDL_PowerState s);

void PrintSDLTtfVersion();

//char* GetEventTypeStr( Uint32 eventType );

#endif // __SYSTEM_INFO__H__