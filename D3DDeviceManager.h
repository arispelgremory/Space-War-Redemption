#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include "AppConfiguration.h"
#include "WindowScreen.h"

class DirectXManager
{
private:
	IDirect3DDevice9* d3dDevice;
	IDirect3D9* direct3D9;
	D3DPRESENT_PARAMETERS d3dParameters;
	static DirectXManager* _instance;
public:
	static DirectXManager* GetInstance();
	void InitDirectX();
	IDirect3DDevice9* GetD3DDevice();
};

void CreateMyDX()
{
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
	d3dPP.BackBufferWidth = SCREEN_WIDTH;
	d3dPP.BackBufferHeight = SCREEN_HEIGHT;
	d3dPP.hDeviceWindow = WINDOW->GetWindowHandler();

	//	Create a Direct3D 9 device.
	hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, WINDOW->GetWindowHandler(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);

	if (FAILED(hr))
		cout << "Create DX failed";

	//	Create sprite. Study the documentation. 
	hr = D3DXCreateSprite(d3dDevice, &spriteBrush);

	if (FAILED(hr)) {
		cout << "Create sprite failed" << endl;
	}

	hr = D3DXCreateFont(d3dDevice, 200, 0, FW_BOLD, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Arial", &font);

	if (FAILED(hr)) {
		cout << "Create font failed" << endl;
	}

	hr = D3DXCreateLine(d3dDevice, &line);
	if (FAILED(hr)) {
		cout << "Create line failed" << endl;
	}

}

