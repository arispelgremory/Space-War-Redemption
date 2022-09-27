#pragma once
#include <d3dx9.h>
#include "AppConfiguration.h"
#include "DirectXManager.h"

class Text
{
private:
	Text* _instance;
	LPD3DXFONT font = NULL;
	INT fontHeight;
	UINT fontWeight;
	LPD3DXSPRITE textBrush = NULL;
public:
	Text* GetInstance();

	void DrawOutText(LPCTSTR text, int count, UINT format, D3DCOLOR colour);
};

