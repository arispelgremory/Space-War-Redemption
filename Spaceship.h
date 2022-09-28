#pragma once
#include "GameObject.h"

class Spaceship : public GameObject
{
private:
	Sprite* spaceship = NULL;
	float rotationSpeed = 0.0f;
	static Spaceship* _instance;
public:
	Spaceship();
	~Spaceship();
	static Spaceship* GetInstance();
	Sprite* GetSpaceship();
	float GetRotationSpeed();
	void SetRotationSpeed(float rotationSpeed);
	void Init(IDirect3DDevice9* d3d9Device, float xPos, float yPos);
	void Update();
	void Render(LPD3DXSPRITE spriteBrush);
};