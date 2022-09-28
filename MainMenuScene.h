#pragma once
#include "Scenes.h"

class MainMenuScene : public Scenes
{
private:
	Sprite* bg = new Sprite();
	Text* mainTitle = new Text();

	// play button
	Line* playBox = new Line();
	Text* playText = new Text();

	// exit button
	Line* exitBox = new Line();
	Text* exitText = new Text();

	bool buttonClicked = false;

public:
	MainMenuScene();
	~MainMenuScene();
	void Initialize(IDirect3DDevice9* d3dDevice);
	void GetInput();
	void Update();
	void Render(LPD3DXSPRITE spriteBrush, IDirect3DDevice9* d3dDevice);
	void Clean();
};

