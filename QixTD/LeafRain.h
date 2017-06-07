#pragma once
#include "Singleton.h"
#include "Defines.h"

#ifdef PLATFORMER_GAME_TYPE


struct Leaf
{
	glm::dvec3 pos;

	signed char oscilateDir;	// direction of oscillation about line of fall
	double angleX;				// angle of oscillation about line of fall
	double stratX;				//  start pos x
	unsigned char type;			// variance of a leaf
	double angleSelf;			// angle of oscillation about center of leaf (in degrees)
	double startSelfAngle;		// start angle of oscillation about center of leaf (in degrees)
	signed char onBackground;	// is this leaf on background or foreground
	double groundY;				// this particular leaf "ground" y
};


class LeafRain : public Singleton<LeafRain>
{
public:
	LeafRain();
	~LeafRain();

	int Init();
	void Tick(Uint32 diff);
	void Render(bool foreground);
	void Clean();

	int LoadLeafs();

private:
	SDL_Texture		   *m_leafTypes[4];
	std::vector<Leaf>   m_leafs;

	double				m_leafFallSpeed;
	double				m_oscialteSpeed;
	double				m_leafAmplitude;

	int					m_leafSpawnTickPeriod;

	int					m_leafSizeX;
	int					m_leafSizeY;
};

#endif