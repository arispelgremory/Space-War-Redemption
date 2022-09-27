#pragma once
#include "GameConfiguration.h"

class Scenes {
    public:
        Scenes();
        ~Scenes();

        virtual void Initialize(LPD3DXSPRITE spriteBrush, IDirect3DDevice9* d3dDevice);
        virtual void GetInput();
        virtual void Sprite(LPD3DXSPRITE spriteBrush);
        virtual void Font(LPD3DXSPRITE spriteBrush, IDirect3DDevice9* d3dDevice);

        virtual void Line();
        virtual void Update();
        virtual void Clean();
    
};
