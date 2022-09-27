#pragma once
#include "Sprite.h"
//#include "Physic.h"
#include "GameConfiguration.h"

class GameObject
{
protected:
	int hp;
	int state;
	bool isCollide = false;
public:
	GameObject();
	~GameObject();
	////virtual void Init();
	//virtual void Update();
	//virtual void Render();
	int GetHP();
	void SetHP(int hp);
	int GetState();
	void SetState(int state);
	bool GetIsCollide();
	void SetIsCollide(bool isCollide);
};