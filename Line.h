#pragma once
#include <d3dx9.h>
#include "GameConfiguration.h"
#include "D3DDeviceManager.h"

class Line
{
public:
	static Line* GetInstance();
	RECT GetBoxColRect();
	void SetBoxColRect(int top, int right, int left, int bottom);
	void InitLine(IDirect3DDevice9* d3d9Device);
	void InitBox(D3DXVECTOR2 topLeftPoint, D3DXVECTOR2 topRightPoint, D3DXVECTOR2 botRightPoint, D3DXVECTOR2 botLeftPoint);
	void DrawBox(D3DCOLOR colour);
	void DrawBox();
	void DrawALine(D3DXVECTOR2 startPoint, D3DXVECTOR2 endPoint, D3DCOLOR colour);
	void CleanUpLine();
	void SetColour(D3DCOLOR colour);
	D3DCOLOR GetColour();
	void SetIsFocus(bool isFocus);
	bool GetIsFocus();
	Line();
	~Line();

private:
	static Line* _instance;
	LPD3DXLINE line = NULL;
	RECT boxColRect;
	D3DCOLOR colour;
	bool isFocus = false;
};


