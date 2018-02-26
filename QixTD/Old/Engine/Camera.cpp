#include "stdafx.h"
#include "Camera.h"
#include "Engine/GameManager.h"


Camera::Camera()
{

}


Camera::~Camera()
{

}


void Camera::Init(glm::dvec3 worldPos)
{
	m_screenWPos = worldPos;
}


void Camera::Tick(Uint32 diff)
{

}


glm::dvec3 Camera::GetWPos()
{
	return m_screenWPos;
	//glm::dvec3 pos = PlrCtrl::Inst()->GetWPos();
	//return {
	//	pos.x - (int)GameManager::Inst()->vpWidth / 2 + PlrCtrl::Inst()->m_imageWidth / 2,
	//	pos.y + (int)GameManager::Inst()->vpHeight / 2 - PlrCtrl::Inst()->m_imageHeight / 2,
	//	0
	//};
}