#include "Spaceship.h"


Spaceship::Spaceship()
{

}


Spaceship::~Spaceship()
{
}

Spaceship* Spaceship::_instance = 0;
Spaceship* Spaceship::GetInstance()
{
	if (_instance == 0)
		_instance = new Spaceship();

	return _instance;
}

void Spaceship::Init(IDirect3DDevice9* d3d9Device, float xPos, float yPos)
{
	// Provide the sprite information
	//InitSprite(int texWidth, int texHeight, int texCol, int texRow, D3DXVECTOR2 scaling, float rotation, float xPos, float yPos);
	spaceship->InitSprite(SPACESHIP_DIMENSION, SPACESHIP_DIMENSION, 2, 2, D3DXVECTOR2(1.0f, 1.0f), 0.0f, xPos, yPos);

	// Create the sprite
	spaceship->CreateTexture(d3d9Device, SPACESHIP_FILEPATH);

	// Initiate the HP
	SetHP(3);
}

void Spaceship::Update()
{
	if (isCollide)
	{
		spaceship->SetColour(D3DCOLOR_XRGB(255, 50, 50));
		SetHP(this->hp - 1);
		SetState(DAMAGED);
	}
	else
		spaceship->SetColour(D3DCOLOR_XRGB(255, 255, 255));
}

void Spaceship::Render(LPD3DXSPRITE spriteBrush)
{
	if (this->hp > 0)
		spaceship->Draw(spriteBrush, spaceship->GetColour());
}
