#pragma once
#include "GameObject.h"

class Collectible : public GameObject
{
private:
	Sprite* collectible;
public:
	Collectible();
	~Collectible();
	void Init(IDirect3DDevice9* d3d9Device, float xPos, float yPos);
	void Update();
	void Render(LPD3DXSPRITE spriteBrush);
};
