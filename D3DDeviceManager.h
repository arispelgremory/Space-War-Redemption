#ifndef SPACEWARREDEMPTIONX_D3DDEVICEMANAGER_H
#define SPACEWARREDEMPTIONX_D3DDEVICEMANAGER_H
#include "GameConfiguration.h"

class D3DDeviceManager {
    public:
        D3DDeviceManager();
        ~D3DDeviceManager();
        static D3DDeviceManager* GetInstance();
        // Create Direct3D9 Device
        void CreateD3D9Device(HWND g_hWnd);
        // Begin Render (Begin scene and set up spriteBrush)
        void BeginRender();
        // Begin Sprite Brush
        void BeginSpriteBrush();
        // End Sprite Brush
        void EndSpriteBrush();
        // Present the back buffer to the screen
        void SwapScene();
        // Clean Up Direct3D9 Device
        void CleanUpMyD3D9Device();

        LPD3DXSPRITE GetSpriteBrush();
        IDirect3DDevice9** GetD3D9Reference();
        IDirect3DDevice9* GetD3D9Device();

    private:
        static D3DDeviceManager* _instance;
        IDirect3DDevice9* d3dDevice;
        IDirect3DDevice9** d3dDeviceReference;
        LPD3DXSPRITE spriteBrush = NULL;
};


#endif //SPACEWARREDEMPTIONX_D3DDEVICEMANAGER_H
