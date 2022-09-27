#include "Text.h"

Text* Text::_instance = 0;
Text* Text::GetInstance()
{
	if (_instance == 0)
		_instance = new Text();
	return _instance;
}

void Text::InitText()
{
	LPD3DXFONT font;
	hr = D3DXCreateFont(d3dDevice, fontHeight, 0, fontWeight, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &font);

	if (FAILED(hr)) {
		cout << "Create font failed" << endl;
		return;
	}

	this->font = font;
}

void Text::SetFontHeight(INT fontHeight)
{
	this->fontHeight = fontHeight;
}

void Text::SetFontWeight(UINT fontWeight)
{
	this->fontWeight = fontWeight;
}

void Text::DrawOutText(LPCTSTR text, int count, UINT format, D3DCOLOR colour)
{
	D3DXVECTOR2 spriteCenter = D3DXVECTOR2(textRect.right - textRect.left, textRect.bottom - textRect.top);

	D3DXMatrixTransformation2D(mat, NULL, 0.0, &scaling, &spriteCenter, NULL, &position);
	D3DDEVICE->GetSpriteBrush()->SetTransform(mat);

	font->DrawText(D3DDEVICE->GetSpriteBrush(), text, count, &textRect, format, colour);
}

void Text::CleanUpText()
{
	//	Release and clean up font
	font->Release();
	font = NULL;
}

Text::Text(int top, int right, int left, int bottom, INT fontHeight, UINT fontWeight, D3DXVECTOR2 position, D3DXVECTOR2 scaling)
{
	textRect.top = top;
	textRect.right = right;
	textRect.bottom = bottom;
	textRect.left = left;
	this->fontHeight = fontHeight;
	this->fontWeight = fontWeight;
	this->scaling = scaling;
	this->position = position;
}

Text::Text()
{
}

Text::~Text()
{
}

D3DXMATRIX* Text::GetTransformationMatrix()
{
	return mat;
}

void Text::SetTransformationMatrix(D3DXMATRIX* mat)
{
	this->mat = mat;
}

D3DXVECTOR2 Text::GetScaling()
{
	return scaling;
}

void Text::SetScaling(D3DXVECTOR2 scaling)
{
	this->scaling = scaling;
}

D3DXVECTOR2 Text::GetSpriteCenter()
{
	return spriteCeenter;
}

void Text::SetSpriteCenter(D3DXVECTOR2 spriteCenter)
{
	this->spriteCenter = spriteCenter;
}

D3DXVECTOR2 Text::GetPosition()
{
	return position;
}

void Text::SetPosition(D3DXVECTOR2 position)
{
	this->position = position;
}
