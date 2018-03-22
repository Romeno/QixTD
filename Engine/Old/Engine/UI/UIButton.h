#pragma once
#include "UIElement.h"


class UIButton : public UIElement
{
public:
	UIButton();
	virtual ~UIButton();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;
	virtual void Render() override;

	typedef void (*OnClickClbck)(void* data);
	typedef void (*OnPressedClbck)();
	typedef void (*OnReleasedClbck)();
	typedef void (*OnHoverClbck)(double x, double y, void* data);

	void OnClick();
	void OnPressed();
	void OnReleased();
	void OnHover(double x, double y);

	virtual void SetOnClick(OnClickClbck callback);
	virtual void SetOnPressed(OnPressedClbck callback);
	virtual void SetOnReleased(OnReleasedClbck callback);
	virtual void SetOnHover(OnHoverClbck callback);

	virtual void SetText(const std::string& text);
	void SetUserData(void* data);

	OnClickClbck		m_onClickCallback;
	OnPressedClbck		m_onPressedCallback;
	OnReleasedClbck		m_onReleasedCallback;
	OnHoverClbck		m_onHoverClbck;

	bool				m_pressed;

	void*				m_userData;
};

