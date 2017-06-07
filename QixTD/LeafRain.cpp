#include "stdafx.h"
#include "Defines.h"

#ifdef PLATFORMER_GAME_TYPE

#include "LeafRain.h"
#include "GameManager.h"
#include "Utils.h"
#include "SC.h"


LeafRain::LeafRain()
	: m_leafTypes()
	, m_leafs()

	, m_leafFallSpeed(1)
	, m_oscialteSpeed(1)
	, m_leafAmplitude(10)

	, m_leafSpawnTickPeriod(15)

	, m_leafSizeX(30)
	, m_leafSizeY(30)
{

}


LeafRain::~LeafRain()
{

}


int LeafRain::Init()
{
	return LoadLeafs();
}


int LeafRain::LoadLeafs()
{
	std::string baseImagePath = GetResourcePath() + "Leaf_0";
	std::string imagePath = "";

	for (size_t i = 0; i < 4; i++)
	{
		imagePath = baseImagePath + std::to_string(i + 1) + ".png";
		SDL_Surface *img = IMG_Load(imagePath.c_str());
		if (img == nullptr) {
			return 1;
		}

		m_leafTypes[i] = SDL_CreateTextureFromSurface(REN, img);
		SDL_FreeSurface(img);
		if (m_leafTypes[i] == nullptr) {
			return 1;
		}
	}

	return 0;
}


void LeafRain::Tick(Uint32 diff)
{
	SDL_Point newp;
	Leaf l;
	static int counter = 0;
	counter++;

	if (counter > m_leafSpawnTickPeriod) {
		counter = 0;

		for (size_t i = 0; i < (int)Random(0, 5); i++)
		{
			double startX = Random(-GameManager::Inst()->vpWidth / 2, GameManager::Inst()->vpWidth / 2);
			glm::dvec3 newp = {
				startX,
				GameManager::Inst()->vpHeight / 2 + 20, 
				0
			};

			l = Leaf({
				R2W(newp),								// pos
				Random(-1, 1) < 0 ? -1 : 1,				// oscilateDir
				0,										// angleX
				R2Wx(startX),							// stratX
				(unsigned char)round(Random(0.5, 3.5)),	// type
				0,										// angleSelf
				Random(30, 50),							// startSelfAngle
				(signed char)round(Random(-0.5, 1.5)),	// onBackground
				R2Wy(Random(10, -20))					// groundY
			});
			m_leafs.push_back(l);
		}
	}

	for (size_t i = 0; i < m_leafs.size(); i++)
	{
		if (m_leafs[i].pos.y > m_leafs[i].groundY)
		{
			m_leafs[i].angleX += m_oscialteSpeed * M_PI / 180.0;
			if (m_leafs[i].angleX > 2 * M_PI)
			{
				m_leafs[i].angleX -= 2 * M_PI;
			}

			m_leafs[i].pos.y -= m_leafFallSpeed;
			m_leafs[i].pos.x = m_leafs[i].stratX + m_leafs[i].oscilateDir * m_leafAmplitude * sin(m_leafs[i].angleX);
			m_leafs[i].angleSelf = m_leafs[i].startSelfAngle + 30.0 * sin(m_leafs[i].angleX);
		}
	}
}


void LeafRain::Render(bool foreground)
{
	SDL_Rect dstrect;
	for (size_t i = 0; i < m_leafs.size(); i++)
	{
		if (m_leafs[i].onBackground != foreground)
		{
			dstrect = {
				W2Sx(m_leafs[i].pos.x),
				W2Sy(m_leafs[i].pos.y),
				30,
				30
			};
			SDL_RenderCopyEx(REN, m_leafTypes[m_leafs[i].type], NULL, &dstrect, m_leafs[i].angleSelf, NULL, SDL_FLIP_NONE);
		}
	}

	//std::vector<Leaf> newLeafs;
	//for (size_t i = 0; i < leafs.size(); i++)
	//{
	//	if (leafs[i].pos.y < vpHeight)
	//	{
	//		newLeafs.push_back(leafs[i]);
	//	}
	//}

	//leafs.clear();
	//for (size_t i = 0; i < newLeafs.size(); i++)
	//{
	//	leafs.push_back(newLeafs[i]);
	//}
}


void LeafRain::Clean()
{

}


#endif