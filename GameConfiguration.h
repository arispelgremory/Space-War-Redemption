#pragma once
#include <iostream>
using namespace std;

// Window Screen
#define CLASS_NAME							"SnookerGame"
#define TITLE_STR							"8-bit Snooker Game"
#define SCREEN_WIDTH						800
#define SCREEN_HEIGHT						600

// Direct input
#define DIRECTINPUT_VERSION					0x0800
#define KEYBOARD_BUFFER_SIZE				1024

#define KEYDOWN(name, key) (name[key] & 0x80)
#define MOUSEBUTTONDOWN(name, key) (name.rgbButtons[key] & 0x80)

// Game fps
#define GAME_FPS							10

// Instances of Objects
#define WINDOW								WindowManager::GetInstance()
#define D3DDEVICE							DirectXManager::GetInstance()
#define SPRITE								Sprite::GetInstance()
#define LINE								Line::GetInstance()

// Scene IDs
#define MAINMENU_SCENE_ID					9999
#define SNOOKER_SCENE_ID					9998
#define GAMEWIN_SCENE_ID					9997

// 

// Sound File Paths
#define BGM1								"Assets/Sounds/bgm.mp3"
#define BGM2								"Assets/Sounds/bgm2.mp3"
#define WIN_BGM								"Assets/Sounds/win.mp3"
#define HITSOUND							"Assets/Sounds/hit.mp3"