#pragma once
#include "Engine/Utils/Singleton.h"


class Keyboard : public Singleton<Keyboard>
{
public:
	Keyboard();
	virtual ~Keyboard();

	virtual void Tick( Uint32 diff );

	// ALT
	bool IsAltPressed();

	bool IsLAltPressed();
	bool IsRAltPressed();

	// CTRL
	bool IsCtrlPressed();

	bool IsLCtrlPressed();
	bool IsRCtrlPressed();

	// SHIFT
	bool IsShiftPressed();

	bool IsLShiftPressed();
	bool IsRShiftPressed();

	// SPECIAL (Win, ?)
	bool IsSpecialPressed();

	bool IsLSpecialPressed();
	bool IsRSpecialPressed();

	// Num Lock
	bool IsNumLockPressed();
	bool IsNumLockActive();

	// Caps Lock
	bool IsCapsLockPressed();
	bool IsCapsLockActive();

	// Scroll Lock
	bool IsScrollLockPressed();
	bool IsScrollLockActive();
};

