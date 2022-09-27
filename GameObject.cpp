#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}
//
//void GameObject::Update()
//{
//}
//
//void GameObject::Render()
//{
//}

int GameObject::GetHP()
{
	return hp;
}

void GameObject::SetHP(int hp)
{
	this->hp = hp;
}

int GameObject::GetState()
{
	return state;
}

void GameObject::SetState(int state)
{
	this->state = state;
}

bool GameObject::GetIsCollide()
{
	return isCollide;
}

void GameObject::SetIsCollide(bool isCollide)
{
	this->isCollide = isCollide;
}

