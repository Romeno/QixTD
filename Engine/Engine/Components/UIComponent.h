#pragma once
#include "Engine/Component.h"


// идея была в том, что одна компонента и 
// создать кнопку будет фнукция? потому всё закоменчено в папке UI?
// по моему так...

class UIComponent : public Component
{
public:
	typedef Component super;

	//////////////////////////////////////////////////////////////////////////

	// Click
	struct ClickData
	{
		ClickData() {}
		virtual ~ClickData() {}

		bool clicked;
	};

	struct PressData
	{
		PressData() {}
		virtual ~PressData() {}

		bool pressed;
	};

	struct ReleaseData
	{
		ReleaseData() {}
		virtual ~ReleaseData() {}

		bool released;
	};

	//////////////////////////////////////////////////////////////////////////

	// Hover
	struct BeginHoverData
	{
		BeginHoverData() {}
		virtual ~BeginHoverData() {}

	};

	struct HoverData
	{
		HoverData() {}
		virtual ~HoverData() {}

		bool hovered;
	};

	struct EndHoverData
	{
		EndHoverData() {}
		virtual ~EndHoverData() {}

	};

	//////////////////////////////////////////////////////////////////////////

	// Focus
	struct FocusData
	{
		FocusData() {}
		virtual ~FocusData() {}

		bool focused;
	};


	UIComponent();
	virtual ~UIComponent();


	//virtual void SetClickSize( glm::dvec3 size );

	//glm::dvec3 m_clickSize;

	//typedef void(*OnClickClbck)(void* data);
	//typedef void(*OnPressedClbck)();
	//typedef void(*OnReleasedClbck)();
	//typedef void(*OnHoverClbck)(double x, double y, void* data);

	//virtual void OnClick() = 0;
	//virtual void OnPressed() = 0;
	//virtual void OnReleased() = 0;
	//virtual void OnHover(double x, double y) = 0;

	//virtual void SetOnClick(OnClickClbck callback) = 0;
	//virtual void SetOnPressed(OnPressedClbck callback) = 0;
	//virtual void SetOnReleased(OnReleasedClbck callback) = 0;
	//virtual void SetOnHover(OnHoverClbck callback) = 0;

	//virtual void SetText(const std::string& text);
	//void SetUserData(void* data);

	//OnClickClbck		m_onClickCallback;
	//OnPressedClbck		m_onPressedCallback;
	//OnReleasedClbck		m_onReleasedCallback;
	//OnHoverClbck		m_onHoverClbck;

	//bool				m_pressed;

	//void*				m_userData;

	//std::string			m_text;
};

