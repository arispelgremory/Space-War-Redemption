#pragma once
#include <iostream>
#include <vector>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#include <iostream> // only keep this for error checking?
#include <string>

using namespace std;

// isn't this part bad XD cause it'll try to read all the header files in every cpp file
#include "WindowManager.h"
#include "D3DDeviceManager.h"
#include "InputManager.h"
// #include "AudioManager.h"

#pragma comment(lib, "d3d9.lib ")
#pragma comment(lib, "d3dx9.lib ")
#pragma comment(lib, "dinput8.lib ")
#pragma comment(lib, "dxguid.lib ")


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define GAMEFPS 24
#define KEYDOWN(name, key) (name[key] & 0x80)
#define MOUSEBUTTONDOWN(name, key) (name.rgbButtons[key] & 0x80)

// Space background info
#define BG_FILEPATH							"Assets/Images/space_bg.png"
#define BG_DIMENSION						1024
#define BG_SPRITEWIDTH						800
#define BG_SPRITEHEIGHT						600

// Spaceship Info
#define SPACESHIP_FILEPATH					"Assets/Images/spaceship.png"
#define SPACESHIP_DIMENSION					64
#define SPACESHIP_ANIM_FPS					10
enum SPACESHIP_STATE { IDLE, MOVE_FORWARD, MOVE_BACKWARD, ROTATE_RIGHT, ROTATE_LEFT, DAMAGED, DIED };

// Collectible Info
#define COLLECTIBLE_FILEPATH				"Assets/Images/collectible.png"
#define COLLECTIBLE_DIMENSION				32
#define COLLECTIBLE_SPRITEWIDTH				9
#define COLLECTIBLE_SPRITEHEIGHT			9