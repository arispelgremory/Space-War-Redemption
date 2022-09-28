#pragma once
#include "Scenes.h"
#include "Spaceship.h"
#include "Collectible.h"

class SpaceshipScene : public Scenes
{
private:
	Sprite* bg = new Sprite;
	Spaceship* player1 = new Spaceship();
	Collectible* collectible[10];
public:
	SpaceshipScene();
	~SpaceshipScene();
	void Initialize(IDirect3DDevice9* d3dDevice);
	void GetInput();
	void Update();
	void Render(LPD3DXSPRITE spriteBrush, IDirect3DDevice9* d3dDevice);
	void Clean();
};

