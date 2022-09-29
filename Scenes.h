#pragma once
#include "GameConfiguration.h"
#include "InputManager.h"
#include "Line.h"
#include "Sprite.h"
#include "Text.h"

class Scenes {
public:
    Scenes();
    ~Scenes();

    virtual void Initialize(IDirect3DDevice9* d3dDevice);
    virtual void GetInput();
    /* virtual void Sprite(LPD3DXSPRITE spriteBrush);
     virtual void Font(LPD3DXSPRITE spriteBrush, IDirect3DDevice9* d3dDevice);

     virtual void Line();*/
    virtual void Render(LPD3DXSPRITE spriteBrush);
    virtual void RenderLine(LPD3DXSPRITE spriteBrush);
    virtual void Update();
    virtual void Clean();

protected:
    InputManager* input = new InputManager();
};
