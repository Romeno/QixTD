#pragma once
#include "Engine/Components/UIComponent.h"
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

	typedef void (*OnClickClbck)(ClickData* click, void* userData);
	typedef void (*OnPressedClbck)(PressData* press, void* userData);
	typedef void (*OnReleasedClbck)(ReleaseData* release, void* userData);
	typedef void (*OnHoverClbck)(HoverData* hover, void* userData);

	void OnClick( ClickData* hover );
	void OnPressed( PressData* hover );
	void OnReleased( ReleaseData* hover );
	void OnHover(HoverData* hover);

	virtual void SetOnClick(OnClickClbck callback);
	virtual void SetOnPressed(OnPressedClbck callback);
	virtual void SetOnReleased(OnReleasedClbck callback);
	virtual void SetOnHover(OnHoverClbck callback);

	virtual void SetSensor( InputSensor* sensor ) { m_sensor = sensor; }
	virtual void SetText(const std::string& text);
	void SetUserData(void* data);
	virtual void SetClickArea( glm::drect clickArea ) { m_clickArea = clickArea; }

	OnClickClbck		m_onClickCallback;
	OnPressedClbck		m_onPressedCallback;
	OnReleasedClbck		m_onReleasedCallback;
	OnHoverClbck		m_onHoverClbck;

	InputSensor*		m_sensor;

	bool				m_pressed;

	void*				m_userData;

	glm::drect			m_clickArea;

	void SetStandardImage( std::string& path ) { m_iStandardState = path; }
	void SetHoveredImage( std::string& path ) { m_iHoveredState = path; }
	void SetClickedImage( std::string& path ) { m_iClickedState = path; }

	std::string			m_iStandardState;
	std::string			m_iHoveredState;
	std::string			m_iClickedState;
};

