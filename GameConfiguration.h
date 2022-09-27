#pragma once

#define WindowWidth 800
#define WindowHeight 600

#include <iostream>
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <iostream>
#include <string>

using namespace std;

#include "WindowManager.h"
#include "D3DDeviceManger.h"
#include "InputManager.h"
// #include "AudioManager.h"

#pragma comment(lib, "d3d9.lib ")
#pragma comment(lib, "d3dx9.lib ")
#pragma comment(lib, "dinput8.lib ")
#pragma comment(lib, "dxguid.lib ")

#define GAMEFPS 24
#define KEYDOWN(name, key) (name[key] & 0x80)
#define MOUSEBUTTONDOWN(name, key) (name.rgbButtons[key] & 0x80)


