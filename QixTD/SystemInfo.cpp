#include "stdafx.h"
#include "SystemInfo.h"
#include "Utils.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;



void PrintInfo(SDL_Window* win, SDL_Renderer* ren) {

	PrintCustomInfo();
	PrintFilesystemH();
	//PrintVideoH(win);
	PrintRenderH(win, ren);
	PrintAudioH();
	PrintKeyboardH(win);
	PrintMouseH();
	PrintTouchH();
	PrintTimerH();
	PrintEventsH();
	PrintCpuinfoH();
	PrintPowerH();
	PrintSystemH();
	PrintClipboardH();
	PrintPlatformH();
}


void PrintCustomInfo() {
	cout << endl;
	cout << "-------------     CUSTOM INFO     -------------" << endl;

	string resPath = GetResourcePath();

	cout << "Resource path is: " << resPath << endl;
}


void PrintFilesystemH() {
	cout << endl;
	cout << "-------------     FILESYSTEM     -------------" << endl;
	cout << "SDL_GetBasePath: " << SDL_GetBasePath() << endl;
	cout << "SDL_GetPrefPath(\"RomenoCo\", \"SDL\"): " << SDL_GetPrefPath("RomenoCo", "SDL") << endl;
}


void PrintVideoH(SDL_Window* win) {
	cout << endl;
	cout << "-------------     VIDEO     -------------" << endl;

	int numVideoDrivers = SDL_GetNumVideoDrivers();
	cout << "SDL_GetNumVideoDrivers(): " << numVideoDrivers << endl;
	for (int i = 0; i < numVideoDrivers; ++i) {
		cout << "SDL_GetVideoDriver(" << i << "): " << SDL_GetVideoDriver(i) << endl;
	}
	//SDL_VideoInit
	//SDL_VideoQuit
	cout << "SDL_GetCurrentVideoDriver(): " << SDL_GetCurrentVideoDriver() << endl;

	int numDisplays = SDL_GetNumVideoDisplays();
	cout << "SDL_GetNumVideoDisplays(): " << numDisplays << endl;

	cout << endl;
	for (size_t d = 0; d < numDisplays; d++)
	{
		cout << "SDL_GetDisplayName(" << d << "): " << SDL_GetDisplayName(d) << endl;
	}

	cout << endl;
	SDL_Rect r;
	for (size_t d = 0; d < numDisplays; d++) {
		SDL_GetDisplayBounds(d, &r);
		cout << "SDL_GetDisplayBounds(" << d << "): (x, y, w, h): " << r.x << ", " << r.y << ", " << r.w << ", " << r.h << endl;
	}

	cout << endl;
	float ddpi, hdpi, vdpi;
	for (size_t d = 0; d < numDisplays; d++) {
		SDL_GetDisplayDPI(d, &ddpi, &hdpi, &vdpi);
		cout << "SDL_GetDisplayDPI(" << d << "): (ddpi, hdpi, vdpi): " << ddpi << ", " << hdpi << ", " << vdpi << endl;
	}

	cout << endl;
	for (size_t d = 0; d < numDisplays; d++) {
		SDL_GetDisplayUsableBounds(d, &r);
		cout << "SDL_GetDisplayUsableBounds(" << d << "): (x, y, w, h): " << r.x << ", " << r.y << ", " << r.w << ", " << r.h << endl;
	}

	cout << endl;
	SDL_DisplayMode mode;
	int numDisplayModes;
	for (int d = 0; d < numDisplays; d++) {
		numDisplayModes = SDL_GetNumDisplayModes(d);
		cout << "SDL_GetNumDisplayModes(" << d << "): " << numDisplayModes << endl;

		for (int dm = 0; dm < numDisplayModes; ++dm) {
			SDL_GetDisplayMode(d, dm, &mode);
			cout << "Display " << d << " mode " << dm << " info:" << endl;
			PrintDisplayModeInfo(mode);
			cout << endl;
		}
	}

	cout << endl;
	for (size_t d = 0; d < numDisplays; d++)
	{
		SDL_GetDesktopDisplayMode(d, &mode);
		cout << "SDL_GetDesktopDisplayMode(" << d << "): " << endl;
		PrintDisplayModeInfo(mode);
		cout << endl;
	}


	cout << endl;
	for (size_t d = 0; d < numDisplays; d++)
	{
		SDL_GetCurrentDisplayMode(d, &mode);
		cout << "SDL_GetCurrentDisplayMode(" << d << "): " << endl;
		PrintDisplayModeInfo(mode);
		cout << endl;
	}

	cout << endl;
	//SDL_GetClosestDisplayMode
	cout << "SDL_GetWindowDisplayIndex(): " << SDL_GetWindowDisplayIndex(win) << endl;
	//SDL_SetWindowDisplayMode

	cout << endl;
	SDL_GetWindowDisplayMode(win, &mode);
	cout << "SDL_GetWindowDisplayMode(): " << endl;
	PrintDisplayModeInfo(mode);

	cout << endl;
	Uint32 pixelFormat = SDL_GetWindowPixelFormat(win);
	cout << "SDL_GetWindowPixelFormat(): " << endl;
	PrintPixelFormatInfo(pixelFormat);

	//SDL_CreateWindow
	//SDL_CreateWindowFrom

	cout << endl;
	Uint32 windowId = SDL_GetWindowID(win);
	cout << "SDL_GetWindowID(): " << windowId << endl;

	cout << endl;
	SDL_Window* w = SDL_GetWindowFromID(windowId);
	cout << "SDL_GetWindowFromID(" << windowId << "): 0x" << std::hex << (Uint32)w << std::dec << endl;
	cout << "win = 0x" << std::hex << (Uint32)win << std::dec << endl;

	cout << endl;
	Uint32 flags = SDL_GetWindowFlags(win);
	PrintWindowFlags(flags);

	cout << endl;
	cout << "SDL_GetWindowTitle()" << SDL_GetWindowTitle(win) << endl;
	SDL_SetWindowTitle(win, "Test1");
	cout << "SDL_GetWindowTitle()" << SDL_GetWindowTitle(win) << endl;

	//SDL_SetWindowData
	//SDL_GetWindowData
	//SDL_SetWindowPosition
	//SDL_GetWindowPosition
	//SDL_SetWindowSize
	//SDL_GetWindowSize

	cout << endl;
	int top, left, bottom, right;
	SDL_GetWindowBordersSize(win, &top, &left, &bottom, &right);
	cout << "SDL_GetWindowBordersSize(): (top, right, bottom ,left): " << top << ", " << right << ", " << bottom << ", " << left << endl;

	cout << endl;
	int width, height;
	SDL_GetWindowMinimumSize(win, &width, &height);
	cout << "SDL_GetWindowMinimumSize(): (w, h): " << width << ", " << height << endl;

	//SDL_SetWindowMaximumSize
	SDL_GetWindowMaximumSize(win, &width, &height);
	cout << "SDL_GetWindowMaximumSize(): (w, h): " << width << ", " << height << endl;

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


void PrintRenderH(SDL_Window* win, SDL_Renderer* ren)
{
	cout << endl;
	cout << "-------------     RENDER     -------------" << endl;

	int numRenderDrivers = SDL_GetNumRenderDrivers();
	cout << "SDL_GetNumRenderDrivers(): " << numRenderDrivers << endl;

	SDL_RendererInfo rdrinfo;
	for (size_t rdr = 0; rdr < numRenderDrivers; rdr++)
	{
		cout << endl;
		SDL_GetRenderDriverInfo(rdr, &rdrinfo);
		cout << "SDL_GetRenderDriverInfo(" << rdr << "): " << endl;
		PrintRendererInfo(&rdrinfo);
	}

	//SDL_CreateWindowAndRenderer
	//SDL_CreateRenderer
	//SDL_CreateSoftwareRenderer

	cout << endl;
	SDL_Renderer* r = SDL_GetRenderer(win);
	cout << "SDL_GetRenderer(): 0x" << std::hex << (Uint32)r << std::dec << endl;
	cout << "ren = 0x" << std::hex << (Uint32)ren << std::dec << endl;

	cout << endl;
	SDL_GetRendererInfo(r, &rdrinfo);
	cout << "SDL_GetRendererInfo(): " << endl;
	PrintRendererInfo(&rdrinfo);

	cout << endl;
	int w, h;
	SDL_GetRendererOutputSize(ren, &w, &h);
	cout << "SDL_GetRendererOutputSize(): (w, h): " << w << ", " << h;

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

	cout << endl;
	cout << "SDL_GetRenderTarget(): " << SDL_GetRenderTarget(ren) << endl;

	//SDL_RenderSetLogicalSize

	cout << endl;
	SDL_RenderGetLogicalSize(ren, &w, &h);
	cout << "SDL_RenderGetLogicalSize(): (w, h)" << w << ", " << h << endl;

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


void PrintAudioH()
{
	cout << endl;
	cout << "-------------     AUDIO     -------------" << endl;
	int numAudioDrivers = SDL_GetNumAudioDrivers();
	cout << "SDL_GetNumAudioDrivers(): " << SDL_GetNumAudioDrivers() << endl;

	for (size_t a = 0; a < numAudioDrivers; a++)
	{
		cout << "SDL_GetAudioDriver(" << a << "): " << SDL_GetAudioDriver(a) << endl;
	}

	//SDL_AudioInit
	//SDL_AudioQuit
	cout << endl;
	cout << "SDL_GetCurrentAudioDriver(): " << SDL_GetCurrentAudioDriver() << endl;

	cout << endl;
	int numAudioDevices0 = SDL_GetNumAudioDevices(0);
	cout << "SDL_GetNumAudioDevices(0): " << numAudioDevices0 << endl;

	int numAudioDevices1 = SDL_GetNumAudioDevices(1);
	cout << "SDL_GetNumAudioDevices(1): " << numAudioDevices1 << endl;

	for (size_t a = 0; a < numAudioDevices0; a++)
	{
		cout << "SDL_GetAudioDeviceName(" << a << ", 0): " << SDL_GetAudioDeviceName(a, 0) << endl;
	}

	for (size_t a = 0; a < numAudioDevices1; a++)
	{
		cout << "SDL_GetAudioDeviceName(" << a << ", 1): " << SDL_GetAudioDeviceName(a, 1) << endl;
	}

	//SDL_OpenAudioDevice

	cout << endl;
	SDL_AudioStatus s = SDL_GetAudioStatus();
	cout << "SDL_GetAudioStatus(): ";
	PrintAudioStatus(s);

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


void PrintKeyboardH(SDL_Window* win) {
	cout << endl;
	cout << "-------------     KEYBOARD     -------------" << endl;
	SDL_Window* w = SDL_GetKeyboardFocus();
	cout << "SDL_GetKeyboardFocus(): 0x" << std::hex << (Uint32)w << std::dec << endl;

	//SDL_GetKeyboardState

	cout << endl;
	cout << "SDL_HasScreenKeyboardSupport(): " << SDL_HasScreenKeyboardSupport() << endl;
	cout << "SDL_IsScreenKeyboardShown(): " << SDL_IsScreenKeyboardShown(win) << endl;
}


void PrintMouseH() {
	cout << endl;
	cout << "-------------     MOUSE     -------------" << endl;

	SDL_Window* w = SDL_GetMouseFocus();
	cout << "SDL_GetMouseFocus(): 0x" << std::hex << (Uint32)w << std::dec << endl;
	//SDL_GetMouseState
	//SDL_GetGlobalMouseState
	//SDL_GetRelativeMouseState
	//SDL_WarpMouseInWindow
	//SDL_WarpMouseGlobal
	//SDL_SetRelativeMouseMode
	//SDL_CaptureMouse

	cout << "SDL_GetRelativeMouseMode(): " << SDL_GetRelativeMouseMode() << endl;

	//SDL_CreateCursor
	//SDL_CreateColorCursor
	//SDL_CreateSystemCursor
	//SDL_SetCursor
	//SDL_GetCursor
	//SDL_GetDefaultCursor
	//SDL_FreeCursor
	//SDL_ShowCursor
}


void PrintTouchH() {
	cout << endl;
	cout << "-------------     TOUCH     -------------" << endl;

	int numTouchDevices = SDL_GetNumTouchDevices();
	cout << "SDL_GetNumTouchDevices(): " << numTouchDevices << endl;

	SDL_TouchID touchDeviceId;
	for (size_t t = 0; t < numTouchDevices; t++)
	{
		touchDeviceId = SDL_GetTouchDevice(t);
		cout << "SDL_GetTouchDevice(" << t << "): " << touchDeviceId << endl;
		cout << "SDL_GetNumTouchFingers(" << touchDeviceId << "): " << SDL_GetNumTouchFingers(touchDeviceId) << endl;
	}

	//SDL_GetTouchFinger
}


void PrintTimerH()
{
	cout << endl;
	cout << "-------------     TIMER     -------------" << endl;

	//SDL_GetTicks
	//SDL_GetPerformanceCounter
	//SDL_GetPerformanceFrequency
	//SDL_Delay
	//SDL_AddTimer
	//SDL_RemoveTimer
}


void PrintEventsH() {
	cout << endl;
	cout << "-------------     EVENTS     -------------" << endl;

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


void PrintCpuinfoH() {
	cout << endl;
	cout << "-------------     CPU INFO     -------------" << endl;

	cout << "SDL_GetCPUCount(): " << SDL_GetCPUCount() << endl;
	cout << "SDL_GetCPUCacheLineSize(): " << SDL_GetCPUCacheLineSize() << endl;
	cout << "SDL_HasRDTSC(): " << SDL_HasRDTSC() << endl;
	cout << "SDL_HasAltiVec(): " << SDL_HasAltiVec() << endl;
	cout << "SDL_HasMMX(): " << SDL_HasMMX() << endl;
	cout << "SDL_Has3DNow(): " << SDL_Has3DNow() << endl;
	cout << "SDL_HasSSE(): " << SDL_HasSSE() << endl;
	cout << "SDL_HasSSE2(): " << SDL_HasSSE2() << endl;
	cout << "SDL_HasSSE3(): " << SDL_HasSSE3() << endl;
	cout << "SDL_HasSSE41(): " << SDL_HasSSE41() << endl;
	cout << "SDL_HasSSE42(): " << SDL_HasSSE42() << endl;
	cout << "SDL_HasAVX(): " << SDL_HasAVX() << endl;
	cout << "SDL_HasAVX2(): " << SDL_HasAVX2() << endl;
	cout << "SDL_GetSystemRAM(): " << SDL_GetSystemRAM() << endl;
}


void PrintPowerH()
{
	cout << endl;
	cout << "-------------     POWER     -------------" << endl;
	int sec, percent;
	SDL_PowerState state = SDL_GetPowerInfo(&sec, &percent);
	cout << "SDL_GetPowerInfo(): (PowerState, secondsLeft, percentLeft): ";
	PrintPowerState(state);
	cout << ", " << sec << ", " << percent << endl;
}


void PrintSystemH()
{
	cout << endl;
	cout << "-------------     SYSTEM     -------------" << endl;
	//SDL_SetWindowsMessageHook

	cout << "SDL_Direct3D9GetAdapterIndex(0): " << SDL_Direct3D9GetAdapterIndex(0) << endl;
	cout << "SDL_Direct3D9GetAdapterIndex(1): " << SDL_Direct3D9GetAdapterIndex(1) << endl;

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


void PrintClipboardH()
{
	cout << endl;
	cout << "-------------     CLIPBOARD     -------------" << endl;

	//SDL_SetClipboardText
	cout << "SDL_GetClipboardText(): " << SDL_GetClipboardText() << endl;
	cout << "SDL_HasClipboardText(): " << SDL_HasClipboardText() << endl;
}


void PrintPlatformH()
{
	cout << endl;
	cout << "-------------     PALTFORM     -------------" << endl;

	cout << "SDL_GetPlatform(): " << SDL_GetPlatform() << endl;
}


void PrintDisplayModeInfo(SDL_DisplayMode& mode)
{
	cout << "Pixel format: " << mode.format << endl;
	cout << "Width: " << mode.w << endl;
	cout << "Height: " << mode.h << endl;
	cout << "Refresh rate: " << mode.refresh_rate << endl;
	cout << "Driver data: " << std::hex << "0x" << mode.driverdata << std::dec << endl;
}


void PrintPixelFormatInfo(Uint32 pixelFormat)
{
	cout << "Raw pixel format: " << pixelFormat << endl;
}


void PrintWindowFlags(Uint32 flags)
{
	cout << "Raw window flags: " << flags << endl;
}


void PrintRendererInfo(SDL_RendererInfo* info)
{
	cout << "	name: " << info->name << endl;
	cout << "	flags: " << info->flags << endl;
	cout << "	num_texture_formats: " << info->num_texture_formats << endl;
	cout << "	max_texture_height: " << info->max_texture_height << endl;
	cout << "	max_texture_width: " << info->max_texture_width << endl;
}


void PrintAudioStatus(SDL_AudioStatus s) {
	char* res;
	if (s == SDL_AUDIO_STOPPED)
	{
		res = "SDL_AUDIO_STOPPED";
	}
	else if (s == SDL_AUDIO_PLAYING)
	{
		res = "SDL_AUDIO_PLAYING";
	}
	else if (s == SDL_AUDIO_PAUSED)
	{
		res = "SDL_AUDIO_PAUSED";
	}
	else {
		res = "UNKN0WN_AUDIO_STATUS";
	}
	cout << res << endl;
}


void PrintPowerState(SDL_PowerState s)
{
	char* res;
	if (s == SDL_POWERSTATE_UNKNOWN)
	{
		res = "SDL_POWERSTATE_UNKNOWN";
	}
	else if (s == SDL_POWERSTATE_ON_BATTERY)
	{
		res = "SDL_POWERSTATE_ON_BATTERY";
	}
	else if (s == SDL_POWERSTATE_NO_BATTERY)
	{
		res = "SDL_POWERSTATE_NO_BATTERY";
	}
	else if (s == SDL_POWERSTATE_CHARGING)
	{
		res = "SDL_POWERSTATE_CHARGING";
	}
	else if (s == SDL_POWERSTATE_CHARGED)
	{
		res = "SDL_POWERSTATE_CHARGED";
	}
	else
	{
		res = "UNKNOWN_POWER_STATE";
	}
	cout << res;
}


void PrintKeyboardEvent(SDL_Event* e) {

	PrintEventType(e->type);
	cout << endl;
	cout << "   timestamp: " << e->common.timestamp << endl;
	cout << "   windowId: " << e->key.windowID << endl;
	cout << "   state: " << (e->key.state == SDL_PRESSED ? "PRESSED" : "RELEASED") << endl;
	cout << "   repeat: " << (e->key.repeat ? "yes" : "no") << endl;
	cout << "   symbol: " << SDL_GetScancodeName(e->key.keysym.scancode) << endl;
	cout << endl;

}

void PrintTextEditingEvent(SDL_Event* e) {

	PrintEventType(e->type);
	cout << endl;
	cout << "   timestamp: " << e->common.timestamp << endl;
	cout << "   windowId: " << e->edit.windowID << endl;
	cout << "   text: " << e->edit.text << endl;
	cout << "   start: " << e->edit.start << endl;
	cout << "   length: " << e->edit.length << endl;
	cout << endl;

}


void PrintTextInputEvent(SDL_Event* e) {
	PrintEventType(e->type);
	cout << endl;
	cout << "   timestamp: " << e->common.timestamp << endl;
	cout << "   windowId: " << e->text.windowID << endl;
	cout << "   text: " << e->text.text << endl;
	cout << endl;

}


void PrintMouseButtonEvent(SDL_Event* e) {

	PrintEventType(e->type);
	cout << endl;
	cout << "   timestamp: " << e->common.timestamp << endl;
	cout << "   windowId: " << e->button.windowID << endl;
	if (e->button.which == SDL_TOUCH_MOUSEID) {
		cout << "   which: touch input" << endl;
	}
	else {
		cout << "   which: " << e->button.which << endl;
	}
	cout << "   mouse button: ";
	PrintMouseButtonNum(e->button.button);
	cout << " is " << (e->button.state == SDL_PRESSED ? "PRESSED" : "RELEASED") << endl;
	cout << "   clicks: " << (int)e->button.clicks << endl;
	cout << "   x: " << (int)e->button.x << endl;
	cout << "   y: " << (int)e->button.y << endl;
	cout << endl;

}


void PrintMouseMotionEvent(SDL_Event* e) {

	PrintEventType(e->type);
	cout << endl;
	cout << "   timestamp: " << e->common.timestamp << endl;
	cout << "   windowId: " << e->motion.windowID << endl;
	if (e->motion.which == SDL_TOUCH_MOUSEID) {
		cout << "   which: touch input" << endl;
	}
	else {
		cout << "   which: " << e->motion.which << endl;
	}
	cout << "   mouse button(s) pressed: ";
	PrintMouseButtonState(e->motion.state);
	cout << endl;
	cout << "   x: " << (int)e->motion.x << endl;
	cout << "   y: " << (int)e->motion.y << endl;
	cout << "   xrel: " << (int)e->motion.xrel << endl;
	cout << "   yrel: " << (int)e->motion.yrel << endl;
	cout << endl;

}


void PrintMouseWheelEvent(SDL_Event* e) {

	PrintEventType(e->type);
	cout << endl;
	cout << "   timestamp: " << e->common.timestamp << endl;
	cout << "   windowId: " << e->wheel.windowID << endl;
	if (e->wheel.which == SDL_TOUCH_MOUSEID) {
		cout << "   which: touch input" << endl;
	}
	else {
		cout << "   which: " << e->wheel.which << endl;
	}
	cout << "   ";
	PrintMouseWheelDirection(e->wheel.direction);
	cout << endl;
	cout << "   x: " << (int)e->wheel.x << endl;
	cout << "   y: " << (int)e->wheel.y << endl;
	cout << endl;

}


void PrintMouseWheelDirection(Uint32 mouseWheelDirection) {
	char* res;
	if (mouseWheelDirection == SDL_MOUSEWHEEL_NORMAL)
	{
		res = "SDL_MOUSEWHEEL_NORMAL";
	}
	else if (mouseWheelDirection == SDL_MOUSEWHEEL_FLIPPED)
	{
		res = "SDL_MOUSEWHEEL_FLIPPED";
	}
	else
	{
		res = "UNKNOWN_MOUSEWHEEL_DIRECTION";
	}
	cout << res;
}


void PrintMouseButtonState(Uint32 state) {
	string res = "";
	if (state & SDL_BUTTON_LMASK)
	{
		res += " & LEFT";
	}

	if (state & SDL_BUTTON_MMASK)
	{
		res += " & MIDDLE";
	}

	if (state & SDL_BUTTON_RMASK)
	{
		res += " & RIGHT";
	}

	if (state & SDL_BUTTON_X1MASK)
	{
		res += " & X1";
	}

	if (state & SDL_BUTTON_X2MASK)
	{
		res += " & X2";
	}

	if (!res.empty()) {
		res = res.substr(3);
	} 
	else 
	{
		res = "none";
	}

	cout << res;
}


void PrintMouseButtonNum(Uint8 mouseButton) {
	char* res;
	if (mouseButton == SDL_BUTTON_LEFT)
	{
		res = "LEFT";
	}
	else if (mouseButton == SDL_BUTTON_MIDDLE)
	{
		res = "MIDDLE";
	}

	else if (mouseButton == SDL_BUTTON_RIGHT)
	{
		res = "RIGHT";
	}
	else if (mouseButton == SDL_BUTTON_X1)
	{
		res = "X1";
	}
	else if (mouseButton == SDL_BUTTON_X2)
	{
		res = "X2";
	}
	else
	{
		res = "UNKNOWN_MOUSE_BUTTON";
	}
	cout << res;
}


void PrintEventType(Uint32 eventType) {
	char* res;
	if (eventType == SDL_KEYDOWN)
	{
		res = "SDL_KEYDOWN";
	}
	else if (eventType == SDL_KEYUP)
	{
		res = "SDL_KEYUP";
	}
	else if (eventType == SDL_KEYMAPCHANGED)
	{
		res = "SDL_KEYMAPCHANGED";
	}
	else if (eventType == SDL_TEXTEDITING)
	{
		res = "SDL_TEXTEDITING";
	}
	else if (eventType == SDL_TEXTINPUT)
	{
		res = "SDL_TEXTINPUT";
	}

	else if (eventType == SDL_MOUSEMOTION)
	{
		res = "SDL_MOUSEMOTION";
	}
	else if (eventType == SDL_MOUSEBUTTONDOWN)
	{
		res = "SDL_MOUSEBUTTONDOWN";
	}
	else if (eventType == SDL_MOUSEBUTTONUP)
	{
		res = "SDL_MOUSEBUTTONUP";
	}
	else if (eventType == SDL_MOUSEWHEEL)
	{
		res = "SDL_MOUSEWHEEL";
	}

	else if (eventType == SDL_QUIT)
	{
		res = "SDL_QUIT";
	}
	else
	{
		res = "UNKNOWN_EVENT_TYPE";
	}
	cout << res;
}



