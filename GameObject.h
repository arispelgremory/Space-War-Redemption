#pragma once
#include "Sprite.h"
#include "GameConfiguration.h"

class GameObject
{
protected:
	int hp;
public:
	GameObject();
	~GameObject();
	int GetHP();
	int SetHP();
};