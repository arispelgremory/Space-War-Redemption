#include "DirectXManager.h"

DirectXManager* DirectXManager::GetInstance()
{
	if (_instance == 0)
		_instance = new DirectXManager();
	return _instance;
}

void DirectXManager::InitDirectX()
{
	IDirect3DDevice9* d3dDevice;
	//	Define Direct3D 9.
	direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	ZeroMemory(&d3dParameters, sizeof(d3dParameters));

	//	Refer to Direct3D 9 documentation for the meaning of the members.
	d3dParameters.Windowed = true;
	d3dParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dParameters.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dParameters.BackBufferCount = 1;
	d3dParameters.BackBufferWidth = SCREEN_WIDTH;
	d3dParameters.BackBufferHeight = SCREEN_HEIGHT;
	d3dParameters.hDeviceWindow = WINDOW->GetWindowHandler();

	//	Create a Direct3D 9 device.
	HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, WINDOW->GetWindowHandler(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dParameters, &d3dDevice);

	if (FAILED(hr))
	{
		cout << "Create DX failed";
		return;
	}

	this->d3dDevice = d3dDevice;
}

IDirect3DDevice9* DirectXManager::GetD3DDevice()
{
	return d3dDevice;
}
