#pragma once
#include "GameObject.h"

class Spaceship : public GameObject
{
	Sprite* spaceship = NULL;
	static Spaceship* _instance;
public:
	Spaceship();
	~Spaceship();
	static Spaceship* GetInstance();
	void InitSpaceship(D3DXVECTOR2 position);
	void UpdatePosition();
};