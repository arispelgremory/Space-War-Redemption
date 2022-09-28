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

Sprite* Spaceship::GetSpaceship()
{
	return this->spaceship;
}

float Spaceship::GetRotationSpeed()
{
	return rotationSpeed;
}

void Spaceship::SetRotationSpeed(float rotationSpeed)
{
	this->rotationSpeed = rotationSpeed;
}

void Spaceship::Init(IDirect3DDevice9* d3d9Device, float xPos, float yPos)
{
	// Provide the sprite information
	//InitSprite(int texWidth, int texHeight, int texCol, int texRow, D3DXVECTOR2 scaling, float rotation, float xPos, float yPos);
	spaceship->InitSprite(SPACESHIP_DIMENSION, SPACESHIP_DIMENSION, 2, 2, D3DXVECTOR2(1.0f, 1.0f), 0.0f, xPos, yPos);
	rotationSpeed = 0.1f;

	// Create the sprite
	spaceship->CreateTexture(d3d9Device, SPACESHIP_FILEPATH);

	// Initiate the HP
	SetHP(3);
}

void Spaceship::Update()
{
	switch (state)
	{
	case MOVE_FORWARD:
		spaceship->SetColour(D3DCOLOR_XRGB(255, 255, 255));
		if (spaceship->GetFrameCounter() % GAMEFPS / SPACESHIP_ANIM_FPS)
		{
			spaceship->SetFrameCounter(spaceship->GetFrameCounter() + 1);
			// calculate acceleration
		}
		break;
	case MOVE_BACKWARD:
		spaceship->SetColour(D3DCOLOR_XRGB(255, 255, 255));
		if (spaceship->GetFrameCounter() % GAMEFPS / SPACESHIP_ANIM_FPS)
		{
			spaceship->SetFrameCounter(spaceship->GetFrameCounter() + 1);
			// calculate acceleration
		}
		break;
	case ROTATE_LEFT:
		spaceship->SetColour(D3DCOLOR_XRGB(255, 255, 255));
		spaceship->SetRotation(spaceship->GetRotation() - rotationSpeed);
		break;
	case ROTATE_RIGHT:
		spaceship->SetColour(D3DCOLOR_XRGB(255, 255, 255));
		spaceship->SetRotation(spaceship->GetRotation() + rotationSpeed);
		break;
	case DAMAGED:
		SetHP(this->hp - 1);
		spaceship->SetColour(D3DCOLOR_XRGB(255, 50, 50));
		break;
	case IDLE:
		spaceship->SetColour(D3DCOLOR_XRGB(255, 255, 255));
	}
}

void Spaceship::Render(LPD3DXSPRITE spriteBrush)
{
	if (this->hp > 0)
		spaceship->Draw(spriteBrush, spaceship->GetColour());
}
