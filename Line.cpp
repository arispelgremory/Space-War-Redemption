#include "Line.h"

Line* Line::_instance = 0;
Line* Line::GetInstance()
{
    if (_instance == 0)
        _instance = new Line();
    return _instance;
}

void Line::InitLine()
{
    LPD3DXLINE line;
    hr = D3DXCreateLine(D3DDEVICE->GetD3D9Device(), &line);
    if (FAILED(hr))
    {
        cout << "Create line failed" << endl;
        return;
    }

    this->line = line;
}

void Line::DrawBox(D3DXVECTOR2 topLeftPoint, D3DXVECTOR2 topRightPoint, D3DXVECTOR2 botRightPoint, D3DXVECTOR2 botLeftPoint, D3DCOLOR colour)
{
    DrawALine(topLeftPoint, topRightPoint, colour);
    DrawALine(topRightPoint, botRightPoint, colour);
    DrawALine(botLeftPoint, botRightPoint, colour);
    DrawALine(topLeftPoint, botLeftPoint, colour);

    boxColRect.top = topLeftPoint.y;
    boxColRect.left = topLeftPoint.x;
    boxColRect.bottom = botRightPoint.y;
    boxColRect.right = botRightPoint.x;
}

void Line::DrawALine(D3DXVECTOR2 startPoint, D3DXVECTOR2 endPoint, D3DCOLOR colour)
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

Line::Line()
{
}

Line::~Line()
{
}
