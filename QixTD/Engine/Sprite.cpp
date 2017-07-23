#include "stdafx.h"
#include "Engine/Sprite.h"
#include "Engine/GameManager.h"
#include "Engine/ColoredRect.h"
#include "Engine/TextureManager.h"
#include "Engine/Utils/Utils.h"
#include "Engine/Utils/Logger.h"



Sprite::Sprite(const std::string& name, const std::string& imagePath, glm::dvec3 size)
	: DrawableRect(name, size)

	, m_imagePath(imagePath)
	, m_texture(nullptr)
{

}


Sprite::~Sprite()
{

}


Sprite::Sprite(const Sprite& other)
	: DrawableRect(other)

	, m_imagePath(other.m_imagePath)
	, m_texture(nullptr)
{
	this->Init(); // ??? should it be here or should a value be initialized manually after copying
}


Sprite& Sprite::operator=(const Sprite& other)
{
	m_imagePath = other.m_imagePath;
	m_texture = nullptr;

	this->Init(); // ??? should it be here or should a value be initialized manually after copying

	return (*this);
}


int Sprite::Init()
{
	std::string imagePath = GetResourcePath() + m_imagePath;

	m_texture = TextureManager::Inst()->GetTexture(imagePath);
	if (!m_texture)
	{ 
		return 1;
	}

    return DrawableRect::Init();
}


void Sprite::Render()
{
	SDL_Rect dstrect = {
		W2Sx(m_wPos.x),
		W2Sy(m_wPos.y),
		m_size.x,
		m_size.y
	};
	SDL_RenderCopy(REN, m_texture, NULL, &dstrect);
}


void Sprite::Tick(Uint32 diff)
{
	GameManager::Inst()->CheckCollision(this);

	DrawableRect::Tick(diff);
}


//bool operator<(const Sprite& one, const Sprite& two)
//{
//	std::cout << "SS" << std::endl;
//	return one.m_wPos.z < two.m_wPos.z;
//}
//
//
//bool operator<(const Sprite& one, const ColoredRect& two)
//{
//	std::cout << "SC" << std::endl;
//	return one.m_wPos.z < two.m_wPos.z;
//}
//
//
//bool operator<(const ColoredRect& one, const Sprite& two)
//{
//	std::cout << "CS" << std::endl;
//	return one.m_wPos.z < two.m_wPos.z;
//}
