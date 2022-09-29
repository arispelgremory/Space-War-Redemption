#include "Line.h"

Line* Line::_instance = 0;
Line* Line::GetInstance()
{
    if (_instance == 0)
        _instance = new Line();
    return _instance;
}

RECT Line::GetBoxColRect()
{
    return boxColRect;
}

void Line::SetBoxColRect(int top, int right, int left, int bottom)
{
    this->boxColRect.top = top;
    this->boxColRect.right = right;
    this->boxColRect.left = left;
    this->boxColRect.bottom = bottom;
}

void Line::InitLineObject(IDirect3DDevice9* d3d9Device)
{
    LPD3DXLINE line;
    HRESULT hr = D3DXCreateLine(d3d9Device, &line);
    if (FAILED(hr))
    {
        cout << "Create line failed" << endl;
        return;
    }

    this->line = line;
}

void Line::InitLine(D3DXVECTOR2 startPoint, D3DXVECTOR2 endPoint, D3DCOLOR colour)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
    this->colour = colour;
}

void Line::InitLine(D3DXVECTOR2 startPoint, D3DXVECTOR2 endPoint)
{
    this->startPoint = startPoint;
    this->endPoint = endPoint;
}

void Line::InitBox(D3DXVECTOR2 topLeftPoint, D3DXVECTOR2 topRightPoint, D3DXVECTOR2 botRightPoint, D3DXVECTOR2 botLeftPoint)
{
    /*
    * Example box for visualization
    * (100, 300)                 (400, 300)
    *
    *
    * (100, 500)                 (400, 500)
    *
    * topLeft.x = botLeft.x
    * topRight.x = botRight.x
    *
    * topLeft.y = topRight.y
    * botLeft.y = botRight.y
    */
    boxColRect.top = topLeftPoint.y;
    boxColRect.left = topLeftPoint.x;
    boxColRect.bottom = botRightPoint.y;
    boxColRect.right = botRightPoint.x;
}

void Line::DrawBox(D3DCOLOR colour)
{
    /*DrawALine(topLeftPoint, topRightPoint, colour);
    DrawALine(topRightPoint, botRightPoint, colour);
    DrawALine(botLeftPoint, botRightPoint, colour);
    DrawALine(topLeftPoint, botLeftPoint, colour);*/
    DrawALine(D3DXVECTOR2(boxColRect.left, boxColRect.top), D3DXVECTOR2(boxColRect.right, boxColRect.top), colour);
    DrawALine(D3DXVECTOR2(boxColRect.right, boxColRect.top), D3DXVECTOR2(boxColRect.right, boxColRect.bottom), colour);
    DrawALine(D3DXVECTOR2(boxColRect.right, boxColRect.bottom), D3DXVECTOR2(boxColRect.left, boxColRect.bottom), colour);
    DrawALine(D3DXVECTOR2(boxColRect.left, boxColRect.bottom), D3DXVECTOR2(boxColRect.left, boxColRect.top), colour);
}

void Line::DrawBox()
{
    DrawALine(D3DXVECTOR2(boxColRect.left, boxColRect.top), D3DXVECTOR2(boxColRect.right, boxColRect.top), colour);
    DrawALine(D3DXVECTOR2(boxColRect.right, boxColRect.top), D3DXVECTOR2(boxColRect.right, boxColRect.bottom), colour);
    DrawALine(D3DXVECTOR2(boxColRect.right, boxColRect.bottom), D3DXVECTOR2(boxColRect.left, boxColRect.bottom), colour);
    DrawALine(D3DXVECTOR2(boxColRect.left, boxColRect.bottom), D3DXVECTOR2(boxColRect.left, boxColRect.top), colour);
}

void Line::BeginLineDraw()
{
    line->Begin();
}

void Line::EndLineDraw()
{
    line->End();
}

void Line::DrawALine(D3DXVECTOR2 startPoint, D3DXVECTOR2 endPoint, D3DCOLOR colour)
{
    D3DXVECTOR2 vertices[] = { startPoint, endPoint };
    line->Draw(vertices, 2, colour);
}

void Line::DrawALine(D3DCOLOR colour)
{
    D3DXVECTOR2 vertices[] = { startPoint, endPoint };
    line->Draw(vertices, 2, colour);
}

void Line::DrawALine()
{
    D3DXVECTOR2 vertices[] = { startPoint, endPoint };
    line->Draw(vertices, 2, colour);
}

void Line::CleanUpLine()
{
    //	Release and clean up line
    line->Release();
    line = NULL;
}

D3DCOLOR Line::GetColour()
{
    return colour;
}

void Line::SetIsFocus(bool isFocus)
{
    this->isFocus = isFocus;
}

bool Line::GetIsFocus()
{
    return isFocus;
}

void Line::SetColour(D3DCOLOR colour)
{
    this->colour = colour;
}

Line::Line()
{
}

Line::~Line()
{
}
