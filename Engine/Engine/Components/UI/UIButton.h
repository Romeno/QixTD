#pragma once
#include "Engine/Components/UIComponent.h"
#include "Engine/Components/Drawable.h"
#include "Math/Math.h"


class InputSensor;


class UIButton : public UIComponent
{
public:
	typedef UIComponent super;

	UIButton();
	virtual ~UIButton();

	virtual int Init() override;
	virtual void Tick(Uint32 diff) override;

	typedef void( *OnFocusClbck )(FocusData* hover, void* userData);
	typedef void( *OnHoverClbck )(HoverData* hover, void* userData);
	typedef void( *OnReleasedClbck )(ReleaseData* release, void* userData);
	typedef void( *OnPressedClbck )(PressData* press, void* userData);
	typedef void( *OnClickClbck )(ClickData* click, void* userData);

	void OnFocus( FocusData* focus );
	void OnHover( HoverData* hover );
	void OnReleased( ReleaseData* release );
	void OnPressed( PressData* press );
	void OnClick( ClickData* click );

	virtual void SetOnClick(OnClickClbck callback);
	virtual void SetOnPressed(OnPressedClbck callback);
	virtual void SetOnReleased(OnReleasedClbck callback);
	virtual void SetOnHover(OnHoverClbck callback);
	virtual void SetOnFocus( OnFocusClbck callback );

	virtual void SetSensor( InputSensor* sensor ) { m_sensor = sensor; }
	virtual void SetText(const std::string& text);
	void SetUserData(void* data);
	virtual void SetClickArea( glm::drect clickArea ) { m_clickArea = clickArea; }

	OnFocusClbck		m_onFocusClbck;
	OnHoverClbck		m_onHoverClbck;
	OnReleasedClbck		m_onReleasedClbck;
	OnPressedClbck		m_onPressedClbck;
	OnClickClbck		m_onClickClbck;

	InputSensor*		m_sensor;

	bool				m_focused;
	bool				m_hovered;
	bool				m_pressed;
	bool				m_clicked;

	void*				m_userData;

	glm::drect			m_clickArea;

	void SetStandardDrawable( Drawable* d ) { m_standardDrawable = d; }
	void SetClickedDrawable( Drawable* d ) { m_clickedDrawable = d; }
	void SetHoveredDrawable( Drawable* d ) { m_hoverDrawable = d; }
	void SeFocusedDrawable( Drawable* d ) { m_focusDrawable = d; }

	Drawable* m_standardDrawable;
	Drawable* m_focusDrawable;
	Drawable* m_hoverDrawable;
	Drawable* m_clickedDrawable;
};

