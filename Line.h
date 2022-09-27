#pragma once
#include <d3dx9.h>
#include "AppConfiguration.h"
#include "DirectXManager.h"

class Line
{
private:
	static Line* _instance;
	LPD3DXSPRITE lineBrush = NULL;
	LPD3DXLINE line = NULL;
public:
	static Line* GetInstance();
	void InitLine();
	LPD3DXSPRITE GetLineBrush();
	void DrawBox(int topLeftPoint, int topRightPoint, int botRightPoint, int botLeftPoint, D3DCOLOR colour);
	void DrawALine(D3DXVECTOR2 startPoint, D3DXVECTOR2 endPoint, D3DCOLOR colour);
	Line();
	~Line();
};

