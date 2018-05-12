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

	virtual void PreTick( Uint32 diff ) override;
	virtual void Tick(Uint32 diff) override;
	virtual void PostTick( Uint32 diff ) override;

	typedef void( *OnFocusClbck )(FocusData* hover, void* userData);
	typedef void( *OnBeginHoverClbck )(BeginHoverData* hover, void* userData);
	typedef void( *OnHoverClbck )(HoverData* hover, void* userData);
	typedef void( *OnEndHoverClbck )(EndHoverData* hover, void* userData);
	typedef void( *OnReleasedClbck )(ReleaseData* release, void* userData);
	typedef void( *OnPressedClbck )(PressData* press, void* userData);
	typedef void( *OnClickClbck )(ClickData* click, void* userData);


	void OnFocus( FocusData* focus );

	void OnBeginHover( BeginHoverData* hover );
	void OnHover( HoverData* hover );
	void OnEndHover( EndHoverData* hover );

	void OnReleased( ReleaseData* release );
	void OnPressed( PressData* press );
	void OnClick( ClickData* click );


	virtual void SetOnClick(OnClickClbck callback);
	virtual void SetOnPressed(OnPressedClbck callback);
	virtual void SetOnReleased(OnReleasedClbck callback);
	virtual void SetOnBeginHover( OnBeginHoverClbck callback );
	virtual void SetOnHover(OnHoverClbck callback);
	virtual void SetOnEndHover( OnEndHoverClbck callback );
	virtual void SetOnFocus( OnFocusClbck callback );

	virtual void SetSensor( InputSensor* sensor ) { m_sensor = sensor; }
	void SetUserData(void* data);
	virtual void SetClickArea( glm::drect clickArea ) { m_clickArea = clickArea; }

	OnFocusClbck		m_onFocusClbck;
	OnBeginHoverClbck	m_onBeginHoverClbck;
	OnHoverClbck		m_onHoverClbck;
	OnEndHoverClbck		m_onEndHoverClbck;
	OnReleasedClbck		m_onReleasedClbck;
	OnPressedClbck		m_onPressedClbck;
	OnClickClbck		m_onClickClbck;

	InputSensor*		m_sensor;

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

