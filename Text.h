#pragma once
#include <d3dx9.h>
#include "GameConfiguration.h"
#include "D3DDeviceManager.h"

class Text
{
private:
	static Text* _instance;
	LPD3DXFONT font = NULL;
	INT fontHeight;
	UINT fontWeight;
	RECT textRect;

	// Transformation
	D3DMATRIX* mat; 
	D3DXVECTOR2 scaling;
	D3DXVECTOR2 spriteCenter;
	D3DXVECTOR2 position;
public:
	static Text* GetInstance();

	void InitText(IDirect3DDevice9* d3d9Device);

	void SetFontHeight(INT fontHeight);
	void SetFontWeight(UINT fontWeight);

	// Transformation
	D3DXMATRIX* GetTransformationMatrix();
	void SetTransformationMatrix(D3DXMATRIX* mat);
	D3DXVECTOR2 GetScaling();
	void SetScaling(D3DXVECTOR2 scaling);
	D3DXVECTOR2 GetSpriteCenter();
	void SetSpriteCenter(D3DXVECTOR2 spriteCenter);
	D3DXVECTOR2 GetPosition();
	void SetPosition(D3DXVECTOR2 position);

	void DrawOutText(LPD3DXSPRITE spriteBrush, LPCTSTR text, int count, UINT format, D3DCOLOR colour);

	void CleanUpText();

	Text(int top, int right, int left, int bottom, INT fontHeight, UINT fontWeight, D3DXVECTOR2 position, D3DXVECTOR2 scaling);
	Text();
	~Text();
};

