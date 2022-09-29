#pragma once
#include "Scenes.h"

class GameOverScene : public Scenes
{
private:
	Sprite* bg = new Sprite();
	Text* gameOverText = new Text();

	// retry button
	Line* retryBox = new Line();
	Text* retryText = new Text();

	// exit button
	Line* exitBox = new Line();
	Text* exitText = new Text();

	bool isClicked = false;
public:
	GameOverScene();
	~GameOverScene();
	void Initialize(IDirect3DDevice9* d3dDevice);
	void GetInput();
	void Update();
	void Render(LPD3DXSPRITE spriteBrush, IDirect3DDevice9* d3dDevice);
	void Clean();
	void Render(LPD3DXSPRITE spriteBrush) override;
	void RenderLine(LPD3DXSPRITE spriteBrush) override;
};

