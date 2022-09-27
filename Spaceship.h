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
	void InitSpaceship(IDirect3DDevice9* d3d9Device, D3DXVECTOR2 position);
	void UpdatePosition();
};