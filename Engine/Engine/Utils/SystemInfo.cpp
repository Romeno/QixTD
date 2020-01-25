#include "stdafx.h"
#include "SystemInfo.h"
#include "Engine/Input/Mouse.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;

#define LTO(fmt, ...) ILOGTOM( logger, loggerModule, fmt, __VA_ARGS__ )


void LogInfo( SDL_Window* win, SDL_Renderer* ren, const char* logger, const wchar_t* loggerModule )
{
	LogCustomInfo( logger, loggerModule );
	LogFilesystemH( logger, loggerModule );
	//LogVideoH( win, logger, loggerModule );
	LogRenderH( win, ren, logger, loggerModule );
	LogAudioH( logger, loggerModule );
	LogKeyboardH( win, logger, loggerModule );
	LogMouseH( logger, loggerModule );
	LogTouchH( logger, loggerModule );
	LogTimerH( logger, loggerModule );
	LogEventsH( logger, loggerModule );
	LogCpuinfoH( logger, loggerModule );
	LogPowerH( logger, loggerModule );
	LogSystemH( logger, loggerModule );
	LogClipboardH( logger, loggerModule );
	LogPlatformH( logger, loggerModule );
	//LogTTFH( "i:\\Romeno\\Projects\\VisualStudio\\AllGames\\Debug\\res\\fonts\\SNAP.ttf", logger, loggerModule );
}


void LogCustomInfo( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     CUSTOM INFO     -------------" );

	string resPath = GetResourcePath();

	LTO( "Resource path is: %s", Str2Wstr( resPath ).c_str() );
}


void LogFilesystemH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     FILESYSTEM     -------------" );
	LTO( "SDL_GetBasePath: %s", Str2Wstr( SDL_GetBasePath() ).c_str() );
	LTO( "SDL_GetPrefPath(\"RomenoCo\", \"SDL\"): %s", Str2Wstr( SDL_GetPrefPath( "RomenoCo", "SDL" ) ).c_str() );
}


void LogVideoH(SDL_Window* win, const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     VIDEO     -------------" );

	int numVideoDrivers = SDL_GetNumVideoDrivers();
	LTO( "SDL_GetNumVideoDrivers(): %d", numVideoDrivers );
	for (int i = 0; i < numVideoDrivers; ++i) 
	{
		LTO( "SDL_GetVideoDriver(%d)", SDL_GetVideoDriver( i ) );
	}
	//SDL_VideoInit
	//SDL_VideoQuit
	LTO( "SDL_GetCurrentVideoDriver(): %s", Str2Wstr( SDL_GetCurrentVideoDriver() ).c_str() );

	int numDisplays = SDL_GetNumVideoDisplays();
	LTO( "SDL_GetNumVideoDisplays(): %d", numDisplays );

	LTO( " " );
	for (size_t d = 0; d < numDisplays; d++)
	{
		LTO( "SDL_GetDisplayName(%d): %s", d, Str2Wstr( SDL_GetDisplayName( d ) ).c_str() );
	}

	LTO( " " );
	SDL_Rect r;
	for (size_t d = 0; d < numDisplays; d++) 
	{
		SDL_GetDisplayBounds(d, &r);
		LTO( "SDL_GetDisplayBounds(%d): (x, y, w, h): %d, %d, %d, %d", d, r.x, r.y, r.w, r.h );
	}

	LTO( " " );
	float ddpi, hdpi, vdpi;
	for (size_t d = 0; d < numDisplays; d++) 
	{
		SDL_GetDisplayDPI(d, &ddpi, &hdpi, &vdpi);
		LTO( "SDL_GetDisplayDPI(%d): (ddpi, hdpi, vdpi): %f, %f, %f", d, ddpi, hdpi, vdpi );
	}

	LTO( " " );
	for (size_t d = 0; d < numDisplays; d++) 
	{
		SDL_GetDisplayUsableBounds(d, &r);
		LTO( "SDL_GetDisplayUsableBounds(%d): (x, y, w, h): %d, %d, %d, %d" , d, r.x, r.y, r.w, r.h );
	}

	LTO( " " );
	SDL_DisplayMode mode;
	int numDisplayModes;
	for (int d = 0; d < numDisplays; d++) 
	{
		numDisplayModes = SDL_GetNumDisplayModes(d);
		LTO( "SDL_GetNumDisplayModes(%d): %d", d, numDisplayModes );

		for (int dm = 0; dm < numDisplayModes; ++dm) 
		{
			SDL_GetDisplayMode(d, dm, &mode);
			LTO( "Display %d mode %d info:", d, dm );
			LogDisplayModeInfo( mode, logger, loggerModule);
			LTO( " " );
		}
	}

	LTO( " " );
	for (size_t d = 0; d < numDisplays; d++)
	{
		SDL_GetDesktopDisplayMode(d, &mode);
		LTO( "SDL_GetDesktopDisplayMode(%d):", d );
		LogDisplayModeInfo( mode, logger, loggerModule );
		LTO( " " );
	}


	LTO( " " );
	for (size_t d = 0; d < numDisplays; d++)
	{
		SDL_GetCurrentDisplayMode(d, &mode);
		LTO( "SDL_GetCurrentDisplayMode(%d):", d );
		LogDisplayModeInfo( mode, logger, loggerModule );
		LTO( " " );
	}

	LTO( " " );
	//SDL_GetClosestDisplayMode
	LTO( "SDL_GetWindowDisplayIndex(): %d", SDL_GetWindowDisplayIndex( win ) );
	//SDL_SetWindowDisplayMode

	LTO( " " );
	SDL_GetWindowDisplayMode(win, &mode);
	LTO( "SDL_GetWindowDisplayMode(): " );
	LogDisplayModeInfo( mode, logger, loggerModule );

	LTO( " " );
	Uint32 pixelFormat = SDL_GetWindowPixelFormat(win);
	LTO( "SDL_GetWindowPixelFormat(): " );
	LogPixelFormatInfo( pixelFormat, logger, loggerModule );

	//SDL_CreateWindow
	//SDL_CreateWindowFrom

	LTO( " " );
	Uint32 windowId = SDL_GetWindowID(win);
	LTO( "SDL_GetWindowID(): %d", windowId );

	LTO( " " );
	SDL_Window* w = SDL_GetWindowFromID(windowId);
	LTO( "SDL_GetWindowFromID(%d): ", windowId, w );
	LTO( "win = ", win );

	LTO( " " );
	Uint32 flags = SDL_GetWindowFlags(win);
	LogWindowFlags( flags, logger, loggerModule );

	LTO( " " );
	LTO( "SDL_GetWindowTitle(): %s", Str2Wstr( SDL_GetWindowTitle( win ) ).c_str() );
	SDL_SetWindowTitle(win, "Test1");
	LTO( "SDL_GetWindowTitle(): %s", Str2Wstr( SDL_GetWindowTitle( win ) ).c_str() );

	//SDL_SetWindowData
	//SDL_GetWindowData
	//SDL_SetWindowPosition
	//SDL_GetWindowPosition
	//SDL_SetWindowSize
	//SDL_GetWindowSize

	LTO( " " );
	int top, left, bottom, right;
	SDL_GetWindowBordersSize(win, &top, &left, &bottom, &right);
	LTO( "SDL_GetWindowBordersSize(): (top, right, bottom ,left): %d, %d, %d, %d", top, right, bottom, left );

	LTO( " " );
	int width, height;
	SDL_GetWindowMinimumSize(win, &width, &height);
	LTO( "SDL_GetWindowMinimumSize(): (w, h): %d, %d", width, height );

	//SDL_SetWindowMaximumSize
	SDL_GetWindowMaximumSize(win, &width, &height);
	LTO( "SDL_GetWindowMaximumSize(): (w, h): %d, %d", width, height );

	//SDL_SetWindowBordered
	//SDL_SetWindowResizable
	//SDL_ShowWindow
	//SDL_HideWindow
	//SDL_RaiseWindow
	//SDL_MaximizeWindow
	//SDL_MinimizeWindow
	//SDL_RestoreWindow
	//SDL_SetWindowFullscreen
}


void LogAvailableRenderers( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     AVAILABLE RENDERERS     -------------" );

	int numRenderDrivers = SDL_GetNumRenderDrivers();
	LTO( "SDL_GetNumRenderDrivers(): %d", numRenderDrivers );

	SDL_RendererInfo rdrinfo;
	for ( size_t rdr = 0; rdr < numRenderDrivers; rdr++ )
	{
		LTO( " " );
		SDL_GetRenderDriverInfo( rdr, &rdrinfo );
		LTO( "SDL_GetRenderDriverInfo(%d)", rdr );
		LogRendererInfo( &rdrinfo, logger, loggerModule );
	}
}


void LogRenderH(SDL_Window* win, SDL_Renderer* ren, const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     RENDER     -------------" );

	int numRenderDrivers = SDL_GetNumRenderDrivers();
	LTO( "SDL_GetNumRenderDrivers(): %d", numRenderDrivers );

	SDL_RendererInfo rdrinfo;
	//SDL_CreateWindowAndRenderer
	//SDL_CreateRenderer
	//SDL_CreateSoftwareRenderer

	LTO( " " );
	SDL_Renderer* r = SDL_GetRenderer(win);
	LTO( "SDL_GetRenderer(): %p", r );
	LTO( "ren = %p", ren );

	LTO( " " );
	SDL_GetRendererInfo(r, &rdrinfo);
	LTO( "SDL_GetRendererInfo():" );
	LogRendererInfo( &rdrinfo, logger, loggerModule );

	LTO( " " );
	int w, h;
	SDL_GetRendererOutputSize(ren, &w, &h);
	LTO( "SDL_GetRendererOutputSize(): (w, h): %d, %d", w, h );

	//SDL_CreateTexture
	//SDL_CreateTextureFromSurface
	//SDL_QueryTexture
	//SDL_SetTextureColorMod
	//SDL_GetTextureColorMod
	//SDL_SetTextureAlphaMod
	//SDL_GetTextureAlphaMod
	//SDL_SetTextureBlendMode
	//SDL_GetTextureBlendMode
	//SDL_UpdateTexture
	//SDL_UpdateYUVTexture
	//SDL_LockTexture
	//SDL_UnlockTexture
	//SDL_RenderTargetSupported
	//SDL_SetRenderTarget

	LTO( " " );
	LTO( "SDL_GetRenderTarget(): %p", SDL_GetRenderTarget( ren ) );

	//SDL_RenderSetLogicalSize

	LTO( " " );
	SDL_RenderGetLogicalSize(ren, &w, &h);
	LTO( "SDL_RenderGetLogicalSize(): (w, h): %d, %d", w, h );

	//SDL_RenderSetIntegerScale
	//SDL_RenderGetIntegerScale
	//SDL_RenderSetViewport
	//SDL_RenderGetViewport
	//SDL_RenderSetClipRect
	//SDL_RenderGetClipRect
	//SDL_RenderIsClipEnabled
	//SDL_RenderSetScale
	//SDL_RenderGetScale
	//SDL_SetRenderDrawColor
	//SDL_GetRenderDrawColor
	//SDL_SetRenderDrawBlendMode
	//SDL_GetRenderDrawBlendMode
	//SDL_RenderClear
	//SDL_RenderDrawPoint
	//SDL_RenderDrawPoints
	//SDL_RenderDrawLine
	//SDL_RenderDrawLines
	//SDL_RenderDrawRect
	//SDL_RenderDrawRects
	//SDL_RenderFillRect
	//SDL_RenderFillRects
	//SDL_RenderCopy
	//SDL_RenderCopyEx
	//SDL_RenderReadPixels
	//SDL_RenderPresent
	//SDL_DestroyTexture
	//SDL_DestroyRenderer
	//SDL_GL_BindTexture
	//SDL_GL_UnbindTexture
}


void LogAudioH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     AUDIO     -------------" );
	int numAudioDrivers = SDL_GetNumAudioDrivers();
	LTO( "SDL_GetNumAudioDrivers(): %d", SDL_GetNumAudioDrivers() );

	for (size_t a = 0; a < numAudioDrivers; a++)
	{
		LTO( "SDL_GetAudioDriver(%d): %s", a, Str2Wstr( SDL_GetAudioDriver( a ) ).c_str() );
	}

	//SDL_AudioInit
	//SDL_AudioQuit
	LTO( " " );
	const char* currentAudioDriver = SDL_GetCurrentAudioDriver();
	LTO( "SDL_GetCurrentAudioDriver(): %s", Str2Wstr( currentAudioDriver ).c_str() );

	LTO( " " );
	int numAudioDevices0 = SDL_GetNumAudioDevices(0);
	LTO( "SDL_GetNumAudioDevices(0): %d", numAudioDevices0 );

	int numAudioDevices1 = SDL_GetNumAudioDevices(1);
	LTO( "SDL_GetNumAudioDevices(1): %d", numAudioDevices1 );

	for (size_t a = 0; a < numAudioDevices0; a++)
	{
		LTO( "SDL_GetAudioDeviceName(%d): %s", a, Str2Wstr( SDL_GetAudioDeviceName( a, 0 ) ).c_str() );
	}

	for (size_t a = 0; a < numAudioDevices1; a++)
	{
		LTO( "SDL_GetAudioDeviceName(%d, 1)", a, Str2Wstr( SDL_GetAudioDeviceName( a, 1 ) ).c_str() );
	}

	//SDL_OpenAudioDevice

	LTO( " " );
	SDL_AudioStatus s = SDL_GetAudioStatus();
	LTO( "SDL_GetAudioStatus(): %s", Str2Wstr( AudioStatus2Str( s ) ).c_str() );

	//SDL_GetAudioDeviceStatus
	//SDL_PauseAudio
	//SDL_PauseAudioDevice
	//SDL_LoadWAV_RW
	//SDL_FreeWAV
	//SDL_BuildAudioCVT
	//SDL_ConvertAudio
	//SDL_MixAudio
	//SDL_QueueAudio
	//SDL_DequeueAudio
	//SDL_GetQueuedAudioSize
	//SDL_ClearQueuedAudio
	//SDL_LockAudio
	//SDL_LockAudioDevice
	//SDL_UnlockAudio
	//SDL_UnlockAudioDevice
	//SDL_CloseAudio
	//SDL_CloseAudioDevice
}


void LogKeyboardH(SDL_Window* win, const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     KEYBOARD     -------------" );
	SDL_Window* w = SDL_GetKeyboardFocus();
	LTO( "SDL_GetKeyboardFocus(): %p", w );

	LTO( "SDL_HasScreenKeyboardSupport(): %d", SDL_HasScreenKeyboardSupport() );
	LTO( "SDL_IsScreenKeyboardShown(): %d", SDL_IsScreenKeyboardShown( win ) );
}


void ListenKeyboardH( SDL_Window* win, const char* logger, const wchar_t* loggerModule )
{
	const Uint8* keyboardKeys;
	int numkeys;
	keyboardKeys = SDL_GetKeyboardState( &numkeys );
	for ( size_t i = 0; i < numkeys; i++ )
	{
		if ( keyboardKeys[i] )
		{
			SDL_Scancode scancode = (SDL_Scancode) i;

			LTO( "Scancode: %d", (int)scancode );

			const char* name = SDL_GetScancodeName( scancode );
			LTO( "Scancode name: %s", Str2Wstr( name ).c_str() );
			
			SDL_Keycode keyCode = SDL_GetKeyFromScancode( scancode );
			LTO( "Keycode: %d", (int)keyCode );

			const char* keyCodeName = SDL_GetKeyName( keyCode );
			LTO( "Keycode name: %s", Str2Wstr( keyCodeName ).c_str() );
		}
	}

	SDL_Keymod mods = SDL_GetModState();
	if ( mods & KMOD_LSHIFT == KMOD_LSHIFT )
	{
		LTO( "LSHIFT pressed" );
	}
}


void LogMouseH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     MOUSE     -------------" );

	SDL_Window* w = SDL_GetMouseFocus();
	LTO( "SDL_GetMouseFocus(): %p", w );

	//SDL_GetMouseState
	//SDL_GetGlobalMouseState
	//SDL_GetRelativeMouseState
	//SDL_WarpMouseInWindow
	//SDL_WarpMouseGlobal
	//SDL_SetRelativeMouseMode
	//SDL_CaptureMouse

	LTO( "SDL_GetRelativeMouseMode(): %d", SDL_GetRelativeMouseMode() );

	//SDL_CreateCursor
	//SDL_CreateColorCursor
	//SDL_CreateSystemCursor
	//SDL_SetCursor
	//SDL_GetCursor
	//SDL_GetDefaultCursor
	//SDL_FreeCursor
	//SDL_ShowCursor
}


void LogTouchH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     TOUCH     -------------" );

	int numTouchDevices = SDL_GetNumTouchDevices();
	LTO( "SDL_GetNumTouchDevices(): %d", numTouchDevices );

	SDL_TouchID touchDeviceId;
	for (size_t t = 0; t < numTouchDevices; t++)
	{
		touchDeviceId = SDL_GetTouchDevice(t);
		LTO( "SDL_GetTouchDevice(%d): %d", t, touchDeviceId );
		LTO( "SDL_GetNumTouchFingers(%d): %d", touchDeviceId, SDL_GetNumTouchFingers( touchDeviceId ) );
	}

	//SDL_GetTouchFinger
}


void LogTimerH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     TIMER     -------------" );

	//SDL_GetTicks
	//SDL_GetPerformanceCounter
	//SDL_GetPerformanceFrequency
	//SDL_Delay
	//SDL_AddTimer
	//SDL_RemoveTimer
}


void LogEventsH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     EVENTS     -------------" );

	//SDL_PeepEvents
	//SDL_HasEvent
	//SDL_HasEvents
	//SDL_FlushEvent
	//SDL_FlushEvents
	//SDL_PollEvent
	//SDL_WaitEvent
	//SDL_WaitEventTimeout
	//SDL_PushEvent
	//SDL_SetEventFilter
	//SDL_GetEventFilter
	//SDL_AddEventWatch
	//SDL_DelEventWatch
	//SDL_FilterEvents
	//SDL_EventState
	//SDL_RegisterEvents
}


void LogCpuinfoH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     CPU INFO     -------------" );

	LTO( "SDL_GetCPUCount(): %d", SDL_GetCPUCount() );
	LTO( "SDL_GetCPUCacheLineSize(): %d", SDL_GetCPUCacheLineSize() );
	LTO( "SDL_HasRDTSC(): %d", SDL_HasRDTSC() );
	LTO( "SDL_HasAltiVec(): %d", SDL_HasAltiVec() );
	LTO( "SDL_HasMMX(): %d", SDL_HasMMX() );
	LTO( "SDL_Has3DNow(): %d", SDL_Has3DNow() );
	LTO( "SDL_HasSSE(): %d", SDL_HasSSE() );
	LTO( "SDL_HasSSE2(): %d", SDL_HasSSE2() );
	LTO( "SDL_HasSSE3(): %d", SDL_HasSSE3() );
	LTO( "SDL_HasSSE41(): %d", SDL_HasSSE41() );
	LTO( "SDL_HasSSE42(): %d", SDL_HasSSE42() );
	LTO( "SDL_HasAVX(): %d", SDL_HasAVX() );
	LTO( "SDL_HasAVX2(): %d", SDL_HasAVX2() );
	LTO( "SDL_GetSystemRAM(): %d", SDL_GetSystemRAM() );
}


void LogPowerH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     POWER     -------------" );

	int sec, percent;
	SDL_PowerState state = SDL_GetPowerInfo(&sec, &percent);
	LTO( "SDL_GetPowerInfo(): (PowerState, secondsLeft, percentLeft): %s, %d, %d", Str2Wstr( PowerState2Str( state ) ).c_str(), sec, percent );
}


void LogSystemH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     SYSTEM     -------------" );

	//SDL_SetWindowsMessageHook

	LTO( "SDL_Direct3D9GetAdapterIndex(0): %d", SDL_Direct3D9GetAdapterIndex( 0 ) );
	LTO( "SDL_Direct3D9GetAdapterIndex(1): %d", SDL_Direct3D9GetAdapterIndex( 1 ) );

	//SDL_RenderGetD3D9Device
	//SDL_DXGIGetOutputInfo

	//SDL_iPhoneSetAnimationCallback
	//SDL_iPhoneSetEventPump

	//SDL_AndroidGetJNIEnv
	//SDL_AndroidGetActivity
	//SDL_AndroidGetInternalStoragePath
	//SDL_AndroidGetExternalStorageState
	//SDL_AndroidGetExternalStoragePath

	//SDL_WinRTGetFSPathUNICODE
	//SDL_WinRTGetFSPathUTF8
}


void LogClipboardH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     CLIPBOARD     -------------" );

	//SDL_SetClipboardText
	LTO( "SDL_GetClipboardText(): %s", Str2Wstr( SDL_GetClipboardText() ).c_str() );
	LTO( "SDL_HasClipboardText(): %d", SDL_HasClipboardText() );
}


void LogPlatformH( const char* logger, const wchar_t* loggerModule )
{
	LTO( " " );
	LTO( "-------------     PALTFORM     -------------" );

	LTO( "SDL_GetPlatform(): %s", Str2Wstr( SDL_GetPlatform() ).c_str() );
}


void LogDisplayModeInfo(SDL_DisplayMode& mode, const char* logger, const wchar_t* loggerModule )
{
	LTO( "Pixel format: %d", mode.format );
	LTO( "Width: %d", mode.w );
	LTO( "Height: %d", mode.h );
	LTO( "Refresh rate: %d", mode.refresh_rate );
	LTO( "Driver data: ", mode.driverdata );
}


void LogPixelFormatInfo(Uint32 pixelFormat, const char* logger, const wchar_t* loggerModule )
{
	LTO( "Raw pixel format: %d", pixelFormat );
}


void LogWindowFlags(Uint32 flags, const char* logger, const wchar_t* loggerModule )
{
	LTO( "Raw window flags: %d", flags );
}


void LogRendererInfo(SDL_RendererInfo* info, const char* logger, const wchar_t* loggerModule )
{
	LTO( "	name: %s", Str2Wstr( info->name ).c_str() );
	LTO( "	flags: %d", info->flags );
	LTO( "	num_texture_formats: %d", info->num_texture_formats );
	LTO( "	max_texture_height: %d", info->max_texture_height );
	LTO( "	max_texture_width: %d", info->max_texture_width );
}


void LogSDLTtfVersion( const char* logger, const wchar_t* loggerModule )
{
	LTO("SDL_ttf version: %d.%d.%d", SDL_TTF_MAJOR_VERSION, SDL_TTF_MINOR_VERSION, SDL_TTF_PATCHLEVEL);
}


void LogKeyboardEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule )
{
	LTO( "%s", Str2Wstr( EventType2Str( (SDL_EventType) e->type ) ).c_str() );
	LTO( " " );
	LTO( "   timestamp: %d", e->common.timestamp );
	LTO( "   windowId: %d", e->key.windowID );
	LTO( "   state: %s", (e->key.state == SDL_PRESSED ? L"PRESSED" : L"RELEASED") );
	LTO( "   repeat: %s", (e->key.repeat ? L"yes" : L"no") );
	LTO( "   symbol: ", Str2Wstr( SDL_GetScancodeName( e->key.keysym.scancode ) ).c_str() );
	LTO( " " );
}

void LogTextEditingEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule )
{
	LTO( "%s", Str2Wstr( EventType2Str( (SDL_EventType) e->type ) ).c_str() );
	LTO( "   timestamp: %d", e->common.timestamp );
	LTO( "   windowId: %d", e->edit.windowID );
	LTO( "   text: %s", e->edit.text );
	LTO( "   start: %d", e->edit.start );
	LTO( "   length: %d", e->edit.length );
	LTO( " " );
}


void LogTextInputEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule )
{
	LTO( "%s", Str2Wstr( EventType2Str( (SDL_EventType) e->type ) ).c_str() );
	LTO( " " );
	LTO( "   timestamp: %d", e->common.timestamp );
	LTO( "   windowId: %d", e->text.windowID );
	LTO( "   text: %s", e->text.text );
	LTO( " " );
}


void LogMouseButtonEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule )
{
	LTO( "%s", Str2Wstr( EventType2Str( (SDL_EventType) e->type ) ).c_str() );
	LTO( " " );

	LTO( "   timestamp: %d", e->common.timestamp );
	LTO( "   windowId:  %d", e->button.windowID );
	if (e->button.which == SDL_TOUCH_MOUSEID) 
	{
		LTO( "   which: touch input" );
	}
	else 
	{
		LTO( "   which: %d", e->button.which );
	}
	LTO( "   mouse button: %s", Str2Wstr( Mouse::MouseButtonNum2Str( e->button.button ) ).c_str() );
	LTO( "   is %s", (e->button.state == SDL_PRESSED ? L"PRESSED" : L"RELEASED") );
	LTO( "   clicks: %d", (int) e->button.clicks );
	LTO( "   x: ", (int) e->button.x );
	LTO( "   y: ", (int) e->button.y );
	LTO( " " );
}


void LogMouseMotionEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule )
{
	LTO( "%s", Str2Wstr( EventType2Str( (SDL_EventType) e->type ) ).c_str() );
	LTO( " " );
	LTO( "   timestamp: %d", e->common.timestamp );
	LTO( "   windowId: %d", e->motion.windowID );
	if (e->motion.which == SDL_TOUCH_MOUSEID) 
	{
		LTO( "   which: touch input");
	}
	else 
	{
		LTO( "   which: %d", e->motion.which );
	}
	LTO( "   mouse button(s) pressed: %s", Str2Wstr( Mouse::MouseState2Str( e->motion.state ) ) );
	LTO( " " );
	LTO( "   x: %d", (int) e->motion.x );
	LTO( "   y: %d", (int) e->motion.y );
	LTO( "   xrel: %d", (int) e->motion.xrel );
	LTO( "   yrel: %d", (int) e->motion.yrel );
	LTO( " " );
}


void LogMouseWheelEvent(SDL_Event* e, const char* logger, const wchar_t* loggerModule )
{
	LTO( "%s", Str2Wstr( EventType2Str( (SDL_EventType) e->type ) ).c_str() );
	LTO( " " );
	LTO( "   timestamp: %d", e->common.timestamp );
	LTO( "   windowId: %d", e->wheel.windowID );
	if (e->wheel.which == SDL_TOUCH_MOUSEID) 
	{
		LTO( "   which: touch input" );
	}
	else 
	{
		LTO( "   which: %d", e->wheel.which );
	}
	LTO( " " );
	LTO( "%s", Str2Wstr( Mouse::WheelDirection2Str( e->wheel.direction ) ).c_str() );
	LTO( " " );
	LTO( "   x: %d", (int) e->wheel.x );
	LTO( "   y: %d", (int) e->wheel.y );
	LTO( " " );
}


void LogGenericEvent( SDL_Event* e, const char* logger, const wchar_t* loggerModule )
{
	LTO( "%s", Str2Wstr( EventType2Str( (SDL_EventType) e->type ) ).c_str() );
	LTO( "   timestamp: %d", e->common.timestamp );
}


void LogWindowEvent( SDL_Event* e, const char* logger, const wchar_t* loggerModule )
{
	LogGenericEvent( e, logger, loggerModule );

	LTO( "   windowEvent: %s", Str2Wstr( WindowEventType2Str( (SDL_WindowEventID) e->window.event ) ).c_str() );
	LTO( "   data1: %d", e->window.data1 );
	LTO( "   data2: %d", e->window.data2 );
}


void LogTTFH( const std::string& fontPath, const char* logger, const wchar_t* loggerModule )
{
	const SDL_version* v = TTF_Linked_Version();
	LTO( "SDL_TTF version: %s", Str2Wstr( SDLVersion2Str( v ) ).c_str() );

	TTF_Font * font = TTF_OpenFont( fontPath.c_str(), 14 );
	if ( font )
	{
		LTO( "Opened font %s", Str2Wstr( fontPath ).c_str() );
	}

	int style = TTF_GetFontStyle( font );
	LTO( "Font style is %s", Str2Wstr( FontStyle2Str( style ) ).c_str() );

	int outline = TTF_GetFontOutline( font );
	LTO( "the font outline width is %d pixels", outline );

	int fontHinting = TTF_GetFontHinting( font );
	LTO( "FreeType hinter settings: %s", Str2Wstr( FontHintning2Str( fontHinting ) ).c_str() );

	int height = TTF_FontHeight( font );
	LTO( "Font height: %d", height );

	int ascent = TTF_FontAscent( font );
	LTO( "Font ascent: %d", ascent );

	int descent = TTF_FontDescent( font );
	LTO( "Font descent: %d", descent );

	int lineSkip = TTF_FontLineSkip( font );
	LTO( "Font recommended lineSkip: %d", lineSkip );

	int kerningAllowed = TTF_GetFontKerning( font );
	LTO( "Font kerning allowed: %d", kerningAllowed );

	long fontFaceNumber = TTF_FontFaces( font );
	LTO( "Number of fontFaces: %d", fontFaceNumber );

	int isFixedWidth = TTF_FontFaceIsFixedWidth( font );
	LTO( "Is fixed width: %d", isFixedWidth );

	char* fontFamily = TTF_FontFaceFamilyName( font );
	LTO( "Font family name: %s", Str2Wstr( fontFamily ).c_str() );

	char* fontFaceStyle = TTF_FontFaceStyleName( font );
	LTO( "Font face style: %s", Str2Wstr( fontFaceStyle ).c_str() );

	//int glyphIsProvided = TTF_GlyphIsProvided( font );
	//ILOGB( "Glyph is provided: %d", glyphIsProvided );

	//int res = TTF_GlyphMetrics( font );

	int w, h;
	int res = TTF_SizeText( font, "sample text", &w, &h );
	LTO( "If text 'sample text' is to be rendered it will occupy %d, %d pixels rectangle", w, h );
}


#define ENUM2STR(enumType, funcName, ...)

bool InitSDL_AudioStatus2StrMap( std::map<SDL_AudioStatus, std::string>& map )
{
	MADD( SDL_AUDIO_STOPPED );
	MADD( SDL_AUDIO_PLAYING );
	MADD( SDL_AUDIO_PAUSED );

	return true;
}


std::string AudioStatus2Str( SDL_AudioStatus s )
{
	typedef SDL_AudioStatus keytype;
	static std::map<keytype, std::string> map;
	static bool inited = InitSDL_AudioStatus2StrMap( map );

	auto it = map.find( s );
	if ( it == map.end() )
	{
		ELOG( ERR_TYPE_PROGRAMMING_ERROR, "Unknown AudioStatus" );
		return std::string( "UNKNOWN_AUDIO_STATUS" );
	}
	else
	{
		return it->second;
	}
}


bool InitSDL_PowerState2StrMap( std::map<SDL_PowerState, std::string>& map )
{
	MADD( SDL_POWERSTATE_UNKNOWN );
	MADD( SDL_POWERSTATE_ON_BATTERY );
	MADD( SDL_POWERSTATE_NO_BATTERY );
	MADD( SDL_POWERSTATE_CHARGING );
	MADD( SDL_POWERSTATE_CHARGED );

	return true;
}


std::string PowerState2Str( SDL_PowerState s )
{
	typedef SDL_PowerState keytype;
	static std::map<keytype, std::string> map;
	static bool inited = InitSDL_PowerState2StrMap( map );

	auto it = map.find( s );
	if ( it == map.end() )
	{
		ELOG( ERR_TYPE_PROGRAMMING_ERROR, "Unknown PowerState" );
		return std::string( "UNKNOWN_POWER_STATE" );
	}
	else
	{
		return it->second;
	}
}


bool InitSDL_WindowEvent2StrMap( std::map<SDL_WindowEventID, std::string>& map)
{
	MADD( SDL_WINDOWEVENT_SHOWN );
	MADD( SDL_WINDOWEVENT_HIDDEN );
	MADD( SDL_WINDOWEVENT_EXPOSED );

	MADD( SDL_WINDOWEVENT_MOVED );
	MADD( SDL_WINDOWEVENT_RESIZED );
	MADD( SDL_WINDOWEVENT_SIZE_CHANGED );

	MADD( SDL_WINDOWEVENT_MINIMIZED );
	MADD( SDL_WINDOWEVENT_MAXIMIZED );
	MADD( SDL_WINDOWEVENT_RESTORED );

	MADD( SDL_WINDOWEVENT_ENTER );
	MADD( SDL_WINDOWEVENT_LEAVE );
	MADD( SDL_WINDOWEVENT_FOCUS_GAINED );
	MADD( SDL_WINDOWEVENT_FOCUS_LOST );
	MADD( SDL_WINDOWEVENT_TAKE_FOCUS );
	MADD( SDL_WINDOWEVENT_HIT_TEST );
	MADD( SDL_WINDOWEVENT_CLOSE );

	return true;
}


std::string WindowEventType2Str( SDL_WindowEventID windowEventId ) 
{
	typedef SDL_WindowEventID keytype;
	static std::map<keytype, std::string> map;
	static bool inited = InitSDL_WindowEvent2StrMap( map );

	auto it = map.find( windowEventId );
	if ( it == map.end() )
	{
		ELOG( ERR_TYPE_PROGRAMMING_ERROR, "Unknown Window Event Type" );
		return std::string("UNKNOWN_WINDOW_EVENT_TYPE");
	}
	else
	{
		return it->second;
	}
}


bool InitSDL_EventType2StrMap( std::map<SDL_EventType, std::string>& map )
{
	MADD( SDL_QUIT );

	/* iOS */
	MADD( SDL_APP_TERMINATING );
	MADD( SDL_APP_LOWMEMORY );
	MADD( SDL_APP_WILLENTERBACKGROUND );
	MADD( SDL_APP_DIDENTERBACKGROUND );
	MADD( SDL_APP_WILLENTERFOREGROUND );
	MADD( SDL_APP_DIDENTERFOREGROUND );
							
	/* Window events */
	MADD( SDL_WINDOWEVENT );
	MADD( SDL_SYSWMEVENT );
				
	/* Keyboard events */
	MADD( SDL_KEYDOWN );
	MADD( SDL_KEYUP );
	MADD( SDL_TEXTEDITING );
	MADD( SDL_TEXTINPUT );
	MADD( SDL_KEYMAPCHANGED );
			
	/* Mouse events */
	MADD( SDL_MOUSEMOTION );
	MADD( SDL_MOUSEBUTTONDOWN );
	MADD( SDL_MOUSEBUTTONUP );
	MADD( SDL_MOUSEWHEEL );
                         
	/* Joystick events */
	MADD( SDL_JOYAXISMOTION );
	MADD( SDL_JOYBALLMOTION );
	MADD( SDL_JOYHATMOTION );
	MADD( SDL_JOYBUTTONDOWN );
	MADD( SDL_JOYBUTTONUP );
	MADD( SDL_JOYDEVICEADDED );
	MADD( SDL_JOYDEVICEREMOVED );
                              
	/* Game controller events */
	MADD( SDL_CONTROLLERAXISMOTION );
	MADD( SDL_CONTROLLERBUTTONDOWN );
	MADD( SDL_CONTROLLERBUTTONUP );
	MADD( SDL_CONTROLLERDEVICEADDED );
	MADD( SDL_CONTROLLERDEVICEREMOVED );
	MADD( SDL_CONTROLLERDEVICEREMAPPED );
                 
	/* Touch events */
	MADD( SDL_FINGERDOWN );
	MADD( SDL_FINGERUP );
	MADD( SDL_FINGERMOTION );
                                     
	/* Gesture events */             
	MADD( SDL_DOLLARGESTURE );
	MADD( SDL_DOLLARRECORD );
	MADD( SDL_MULTIGESTURE );
                                     
	/* Clipboard events */           
	MADD( SDL_CLIPBOARDUPDATE );
                                     
	/* Drag and drop events */
	MADD( SDL_DROPFILE );
	MADD( SDL_DROPTEXT );
	MADD( SDL_DROPBEGIN );
	MADD( SDL_DROPCOMPLETE );
					
	/* Audio hotplug events */
	MADD( SDL_AUDIODEVICEADDED );
	MADD( SDL_AUDIODEVICEREMOVED );
                                     
	/* Render events */
	MADD( SDL_RENDER_TARGETS_RESET );
	MADD( SDL_RENDER_DEVICE_RESET );

	MADD( SDL_USEREVENT);

	return true;
}


std::string EventType2Str( SDL_EventType eventType ) 
{
	typedef SDL_EventType keytype;
	static std::map<keytype, std::string> map;
	static bool inited = InitSDL_EventType2StrMap( map );

	auto it = map.find( eventType );
	if ( it == map.end() )
	{
		ELOG( ERR_TYPE_PROGRAMMING_ERROR, "Unknown Event Type" );
		return std::string( "UNKNOWN_EVENT_TYPE" );
	}
	else
	{
		return it->second;
	}
}


std::string SDLVersion2Str(const SDL_version* ver)
{
	return std::to_string( ver->major ) + "." + std::to_string( ver->minor ) + "." + std::to_string( ver->patch );
}


bool InitFontStyle2StrMap( std::map<int, std::string>& map )
{
	MADD( TTF_STYLE_NORMAL );
	MADD( TTF_STYLE_BOLD );
	MADD( TTF_STYLE_ITALIC );
	MADD( TTF_STYLE_UNDERLINE );
	MADD( TTF_STYLE_STRIKETHROUGH );

	return true;
}


std::string FontStyle2Str( int style )
{
	typedef int keytype;
	static std::map<keytype, std::string> map;
	static bool inited = InitFontStyle2StrMap( map );

	auto it = map.find( style );
	if ( it == map.end() )
	{
		ELOG( ERR_TYPE_PROGRAMMING_ERROR, "Unknown font style" );
		return std::string( "UNKNOWN_FONT_STYLE" );
	}
	else
	{
		return it->second;
	}
}


bool InitFontHintning2StrMap( std::map<int, std::string>& map )
{
	MADD( TTF_HINTING_NORMAL );
	MADD( TTF_HINTING_LIGHT );
	MADD( TTF_HINTING_MONO );
	MADD( TTF_HINTING_NONE );

	return true;
}


std::string FontHintning2Str( int hinting )
{
	typedef int keytype;
	static std::map<keytype, std::string> map;
	static bool inited = InitFontHintning2StrMap( map );

	auto it = map.find( hinting );
	if ( it == map.end() )
	{
		ELOG( ERR_TYPE_PROGRAMMING_ERROR, "Unknown font hinting" );
		return std::string( "UNKNOWN_FONT_HINTING" );
	}
	else
	{
		return it->second;
	}
}