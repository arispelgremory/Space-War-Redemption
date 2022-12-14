#include "GameConfiguration.h"
#include "D3DDeviceManager.h"

D3DDeviceManager::D3DDeviceManager(){}

D3DDeviceManager::~D3DDeviceManager(){}

D3DDeviceManager* D3DDeviceManager::_instance = 0;
D3DDeviceManager* D3DDeviceManager::GetInstance()
{
    if (_instance == 0)
        _instance = new D3DDeviceManager();
    return _instance;
}

void D3DDeviceManager::CreateD3D9Device(HWND g_hWnd){
    //	Define Direct3D 9.
    IDirect3D9* direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);
    //	Define how the screen presents.
    D3DPRESENT_PARAMETERS d3dPP;
    ZeroMemory(&d3dPP, sizeof(d3dPP));

    //	Refer to Direct3D 9 documentation for the meaning of the members.
    d3dPP.Windowed = true;
    d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
    d3dPP.BackBufferCount = 1;
    d3dPP.BackBufferWidth = WINDOW_WIDTH;
    d3dPP.BackBufferHeight = WINDOW_HEIGHT;
    d3dPP.hDeviceWindow = g_hWnd;

    //	Create a Direct3D 9 device.
    HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);

    //	Create sprite. Study the documentation.
    hr = D3DXCreateSprite(d3dDevice, &spriteBrush);

    if (FAILED(hr))
    {
        cout << "Create sprite brush 1 failed" << endl;
    }
}


void D3DDeviceManager::BeginRender() {
    //	Clear the back buffer.
    d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

    //	Begin the scene
    d3dDevice->BeginScene();
}

void D3DDeviceManager::BeginSpriteBrush() {
    //	Drawing.
    //	Specify alpha blend will ensure that the sprite will render the background with alpha.
    spriteBrush->Begin(D3DXSPRITE_ALPHABLEND);
}

void D3DDeviceManager::EndSpriteBrush() {
    spriteBrush->End();
}

void D3DDeviceManager::SwapScene() {
    //	End the scene
    d3dDevice->EndScene();

    //	Present the back buffer to screen
    d3dDevice->Present(NULL, NULL, NULL, NULL);
}

IDirect3DDevice9* D3DDeviceManager::GetD3D9Device() {
    return d3dDevice;
}

IDirect3DDevice9** D3DDeviceManager::GetD3D9Reference() {
    d3dDeviceReference = &d3dDevice;
    return d3dDeviceReference;
}

LPD3DXSPRITE D3DDeviceManager::GetSpriteBrush() {
    return spriteBrush;
}

void D3DDeviceManager::CleanUpMyD3D9Device() {
    //	Release and clean up everything
    spriteBrush->Release();
    spriteBrush = NULL;

    //	Release the device when exiting.
    d3dDevice->Release();
    //	Reset pointer to NULL
    d3dDevice = NULL;
}

