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
	void Init(IDirect3DDevice9* d3d9Device, float xPos, float yPos);
	void Update();
	void Render(LPD3DXSPRITE spriteBrush);
};