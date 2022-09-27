#pragma once
#include <d3dx9.h>
#include "GameConfiguration.h"
#include "D3DDeviceManager.h"

class Line
{
public:
	static Line* GetInstance();
	void InitLine(IDirect3DDevice9* d3d9Device);
	void DrawBox(D3DXVECTOR2 topLeftPoint, D3DXVECTOR2 topRightPoint, D3DXVECTOR2 botRightPoint, D3DXVECTOR2 botLeftPoint, D3DCOLOR colour);
	void DrawALine(D3DXVECTOR2 startPoint, D3DXVECTOR2 endPoint, D3DCOLOR colour);
	void CleanUpLine();
	Line();
	~Line();

private:
	static Line* _instance;
	LPD3DXLINE line = NULL;
	RECT boxColRect;
};


