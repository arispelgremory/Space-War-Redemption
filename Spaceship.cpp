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

void Spaceship::InitSpaceship(IDirect3DDevice9* d3d9Device, D3DXVECTOR2 position)
{
	spaceship->SetTextureWidth(SPACESHIP_DIMENSION);
	spaceship->SetTextureHeight(SPACESHIP_DIMENSION);
	spaceship->SetTextureCol(2);
	spaceship->SetTextureRow(2);
	spaceship->SetSpriteWidth(spaceship->GetTextureWidth() / spaceship->GetTextureRow());
	spaceship->SetSpriteHeight(spaceship->GetTextureHeight() / spaceship->GetTextureCol());

	spaceship->CreateTexture(d3d9Device, SPACESHIP_FILEPATH);

	spaceship->SetScaling(D3DXVECTOR2(1.0f, 1.0f));
	spaceship->SetRotation(0.0f);
	spaceship->SetPosition(position);
}

void Spaceship::UpdatePosition()
{
}
