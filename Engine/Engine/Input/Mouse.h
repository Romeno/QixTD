#pragma once
#include "Engine/Utils/Singleton.h"

#define LMB_PRESSED Mouse::Inst()->isLMBPressed()
#define MMB_PRESSED Mouse::Inst()->isMMBPressed()
#define RMB_PRESSED Mouse::Inst()->isRMBPressed()
#define MOUSE_POS Mouse::Inst()->GetPosition()


class Mouse : public Singleton<Mouse>
{
public:
	typedef Singleton<Mouse> super;

	Mouse();
	virtual ~Mouse();

	virtual void Tick(Uint32 diff);

	glm::dvec3 GetPosition(); // returns rPos

	bool isLMBPressed();
	bool isMMBPressed();
	bool isRMBPressed();

	int*	m_x;
	int*	m_y;
	Uint32	m_state;

	// Cursor stuff
	class Cursor 
	{
	public:
		Cursor();
		~Cursor();

		void Enable();
		static Cursor* Load(const std::string& path, int pointerX, int pointerY, int id );

		SDL_Cursor* cur;
	};

	void SetCursor( int id );

	std::map<int, Cursor*> m_cursors;
};
