#include "Collectible.h"

Collectible::Collectible()
{
}

Collectible::~Collectible()
{
}

void Collectible::Init(IDirect3DDevice9* d3d9Device, float xPos, float yPos)
{
	// Specify sprite info
	// X and Y position to be set when object is initiated in the Level
	collectible->InitSprite(COLLECTIBLE_DIMENSION, COLLECTIBLE_DIMENSION, COLLECTIBLE_SPRITEWIDTH, COLLECTIBLE_SPRITEHEIGHT, D3DXVECTOR2(1.0f, 1.0f), 0.0f, D3DXVECTOR2(xPos, yPos));

	// Create the texture
	collectible->CreateTexture(d3d9Device, COLLECTIBLE_FILEPATH);

	// Set hp
	SetHP(1);
}

void Collectible::Update()
{
	if (isCollide)
		SetHP(this->hp - 1);
}

void Collectible::Render(LPD3DXSPRITE spriteBrush)
{
	if (this->hp > 0)
		collectible->Draw(spriteBrush, D3DCOLOR_XRGB(255, 255, 255));
}