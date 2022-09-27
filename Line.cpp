#include "Line.h"

void Line::InitLine()
{
    LPD3DXSPRITE lineBrush;
    //	Create sprite. Study the documentation. 
    HRESULT hr = D3DXCreateSprite(D3DDEVICE->GetD3DDevice(), &lineBrush);
    if (FAILED(hr))
    {
        cout << "Create line brush failed\n";
        return;
    }

    LPD3DXLINE line;
    hr = D3DXCreateLine(D3DDEVICE->GetD3DDevice(), &line);
    if (FAILED(hr)) 
    {
        cout << "Create line failed" << endl;
    }

    this->lineBrush = lineBrush;
    this->line = line;
}
