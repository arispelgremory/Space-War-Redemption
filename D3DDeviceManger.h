#ifndef SPACEWARREDEMPTIONX_D3DDEVICEMANGER_H
#define SPACEWARREDEMPTIONX_D3DDEVICEMANGER_H
#include <d3dx9.h>
#include "WindowManager.h"

class D3DDeviceManger {
    public:
        D3DDeviceManger();
        ~D3DDeviceManger();

        // Create Direct3D9 Device
        void CreateD3D9Device(HWND g_hWnd);
        // Begin Render (Begin scene and set up spriteBrush)
        void BeginRender();
        // Begin Sprite Brush
        void BeginSpriteBrush();
        // End Sprite Brush
        void EndSpriteBrush();
        // Present the back buffer to the screen
        void PresentBuffer();
        // Clean Up Direct3D9 Device
        void CleanUpMyD3D9Device();

        LPD3DXSPRITE GetSpriteBrush();
        IDirect3DDevice9** GetD3D9Reference();
        IDirect3DDevice9* GetD3D9Device();

    private:
        IDirect3DDievice9* d3dDevice;
        IDirect3DDevice9** d3dDeviceReference;
        LPD3DXSPRITE spriteBrush = NULL;
};


#endif //SPACEWARREDEMPTIONX_D3DDEVICEMANGER_H
