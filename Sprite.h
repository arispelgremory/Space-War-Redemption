#pragma once
#pragma once
#include <d3dx9.h>
#include "D3DDeviceManager.h"

class Sprite
{
private:
	static Sprite* _instance;
	LPDIRECT3DTEXTURE9 texture = NULL;
	int textureWidth;
	int textureHeight;
	int textureRow;
	int textureCol;
	int spriteWidth;
	int spriteHeight;


	int frameCounter;
	int maxFrame;

	RECT animRect;
	RECT colRect;

	D3DCOLOR colour;

	// Transformation
	D3DXMATRIX* mat;
	D3DXVECTOR2 scaling;
	D3DXVECTOR2 spriteCenter;
	float rotation = 0.0f;
	D3DXVECTOR2 position;

public:
	static Sprite* GetInstance();
	void InitSprite(int texWidth, int texHeight, int spriteWidth, int spriteHeight, D3DXVECTOR2 scaling, float rotation, D3DXVECTOR2 position);
	void InitSprite(int texWidth, int texHeight, int texCol, int texRow, D3DXVECTOR2 scaling, float rotation, float xPos, float yPos);
	void CreateTexture(IDirect3DDevice9* d3d9Device, LPCSTR texturePath);
	void Draw(LPD3DXSPRITE spriteBrush, D3DCOLOR colour);
	void Draw(LPD3DXSPRITE spriteBrush);

	// Texture Height & Width, Row & Column
	int GetTextureWidth();
	void SetTextureWidth(int textureWidth);
	int GetTextureHeight();
	void SetTextureHeight(int textureHeight);
	int GetTextureRow();
	void SetTextureRow(int textureRow);
	int GetTextureCol();
	void SetTextureCol(int textureCol);

	// Sprite Height & Width
	int GetSpriteWidth();
	void SetSpriteWidth(int spriteWidth);
	int GetSpriteHeight();
	void SetSpriteHeight(int spriteHeight);


	int GetMaxFrame();
	void SetMaxFrame(int maxFrame);
	int GetFrameCounter();
	void SetFrameCounter(int frameCounter);

	//Animation Rectangle
	RECT GetAnimRect();
	// Collision Rectangle
	RECT GetColRect();

	// Colour
	void SetColour(D3DCOLOR colour);
	D3DCOLOR GetColour();

	// Transformation
	D3DXMATRIX* GetTransformationMatrix();
	void SetTransformationMatrix(D3DXMATRIX* mat);
	D3DXVECTOR2 GetScaling();
	void SetScaling(D3DXVECTOR2 scaling);
	D3DXVECTOR2 GetSpriteCenter();
	void SetSpriteCenter(D3DXVECTOR2 spriteCenter);
	float GetRotation();
	void SetRotation(float rotation);
	D3DXVECTOR2 GetPosition();
	void SetPosition(D3DXVECTOR2 position);
	float GetXPosition();
	void SetXPosition(float xPos);
	float GetYPosition();
	void SetYPosition(float yPos);

	void DestroyTexture();
	Sprite(int texWidth, int texHeight, int spriteWidth, int spriteHeight, D3DXVECTOR2 scaling, float rotation, D3DXVECTOR2 position);
	Sprite(int texWidth, int texHeight, int texCol, int texRow, D3DXVECTOR2 scaling, float rotation, float xPos, float yPos);
	Sprite();
	~Sprite();
};
