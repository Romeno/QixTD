#pragma once


class Sprite;


class PlayerController
{
public:
	PlayerController();
	virtual ~PlayerController();

	virtual int Init();
	virtual void Tick(Uint32 diff);
	virtual void Clear();
    virtual void Possess(Sprite* sprite);
    virtual void Render();
};

