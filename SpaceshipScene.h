#pragma once
#include "Scenes.h"
#include "Spaceship.h"
#include "Collectible.h"

class SpaceshipScene : public Scenes
{
private:
	Sprite* bg = new Sprite();
	Spaceship* player1 = new Spaceship();
	Spaceship* player2 = new Spaceship();
	Collectible* collectible[10];
	// see how many items are left on the screen
	int collectibleLeft = 0;

	// Scoreboard - on top of the screen
	Line* line = new Line();
	Text* player1HP = new Text();
	Text* player2HP = new Text();

public:
	SpaceshipScene();
	~SpaceshipScene();
	void Initialize(IDirect3DDevice9* d3dDevice);
	void GetInput();
	void Update(int framesToUpdate);
	void Clean();
	void Render(LPD3DXSPRITE spriteBrush) override;
	void RenderLine(LPD3DXSPRITE spriteBrush) override;
	void Update() override;
};

