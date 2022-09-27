#pragma once
#include "GameConfiguration.h"
#include "InputManager.h"


InputManager::InputManager() {
}

InputManager::~InputManager() {

}
InputManager* InputManager::_instance = 0;
InputManager* InputManager::GetInstance()
{
    if (_instance == 0)
        _instance = new InputManager();
    return _instance;
}

void InputManager::Init(HWND g_hWnd) {
    HRESULT hr = DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);
    if(FAILED(hr)) {
        cout << "Create Direct Input Failed" << std::endl;
    }

    hr = dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);
    if(FAILED(hr)) {
        cout << "Create Keyboard Input Failed!" << endl;
    }

    hr = dInput->CreateDevice(GUID_SysMouse, &dInputMouseDevice, NULL);
    if(FAILED(hr)) {
        cout << "Create Mouse Input Failed!" << endl;
    }

    // Set keyboard format
    hr = dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);

    // Set mouse format
    hr = dInputMouseDevice->SetDataFormat(&c_dfDIMouse);

    // Set Cooperative Level of Keyboard and Mouse Device;
    dInputKeyboardDevice->SetCooperativeLevel(g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
    dInputMouseDevice->SetCooperativeLevel(g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
}

void InputManager::CleanUpInput() {
    // Release Keyboard Device
    dInputKeyboardDevice->Unacquire();
    dInputKeyboardDevice->Release();
    dInputKeyboardDevice = NULL;

    dInputMouseDevice->Unacquire();
    dInputMouseDevice->Release();
    dInputMouseDevice = NULL;

    // Release Direct Input
    dInput->Release();
    dInput = NULL;
}

void InputManager::GetInput() {
    //	Get immediate Keyboard Data.
    dInputKeyboardDevice->GetDeviceState(256, diKeys);
    //	Acquire the device.
    dInputKeyboardDevice->Acquire();
    dInputMouseDevice->Acquire();

    if (KEYDOWN(diKeys, DIK_DOWN)) {
        downButtonPressed = true;
    }
    if (KEYDOWN(diKeys, DIK_UP)){
        upButtonPressed = true;
    }
    if (KEYDOWN(diKeys, DIK_RETURN)) {
        enterButtonPressed = true;
    }


    if (KEYDOWN(diKeys, DIK_LEFT)) {
        leftButtonPressed = true;
        cout << "Left Pressed!" << endl;
    }

    if (KEYDOWN(diKeys, DIK_RIGHT)) {
        rightButtonPressed = true;
        cout << "Right Pressed!" << endl;
    }

    if (mouseState.rgbButtons[0] & 0x80) //first mouse button
    {
        leftMouseClicked = true;
        cout << "Left Mouse Clicked!" << endl;
    }

    if (KEYDOWN(diKeys, DIK_BACKSPACE)) {
        backSpaceButtonPressed = true;
    }

    if (KEYDOWN(diKeys, DIK_W)) {
        wButtonPressed = true;
    }

    if (KEYDOWN(diKeys, DIK_A)) {
        aButtonPressed = true;
    }

    if (KEYDOWN(diKeys, DIK_S)) {
        sButtonPressed = true;
    }

    if (KEYDOWN(diKeys, DIK_D)){
        dButtonPressed = true;
    }



}


// Getters
bool InputManager::GetUpButtonPressed() const {
    return upButtonPressed;
}

bool InputManager::GetDownButtonPressed() const {
    return downButtonPressed;
}
bool InputManager::GetEnterButtonPressed() const {
    return enterButtonPressed;
}

bool InputManager::GetLeftButtonPressed() const {
    return leftButtonPressed;
}

bool InputManager::GetRightButtonPressed() const {
    return rightButtonPressed;
}

bool InputManager::GetLeftMouseClicked() const {
    return leftMouseClicked;
}

bool InputManager::GetBackSpaceButtonPressed() const {
    return backSpaceButtonPressed;
}

bool InputManager::GetWButtonPressed() const {
    return wButtonPressed;
}

bool InputManager::GetAButtonPressed() const {
    return aButtonPressed;
}

bool InputManager::GetSButtonPressed() const {
    return sButtonPressed;
}

bool InputManager::GetDButtonPressed() const {
    return dButtonPressed;
}

// Reset Input (Setters)
void InputManager::ResetUpButton() {
    upButtonPressed = false;
}

void InputManager::ResetDownButton() {
    downButtonPressed = false;
}

void InputManager::ResetEnterButton() {
    enterButtonPressed = false;
}

void InputManager::ResetLeftButton() {
    leftButtonPressed = false;
}

void InputManager::ResetRightButton() {
    rightButtonPressed = false;
}

void InputManager::ResetLeftMouseButton() {
    leftMouseClicked = false;
}

void InputManager::ResetBackSpaceButton() {
    backSpaceButtonPressed = false;
}

void InputManager::ResetWButton() {
    wButtonPressed = false;
}

void InputManager::ResetAButton() {
    aButtonPressed = false;
}

void InputManager::ResetSButton() {
    sButtonPressed = false;
}

void InputManager::ResetDButton() {
    dButtonPressed = false;
}

void InputManager::ResetAllKeys()
{
    upButtonPressed = false;
    downButtonPressed = false;
    enterButtonPressed = false;
    leftButtonPressed = false;
    rightButtonPressed = false;
    leftMouseClicked = false;
    backSpaceButtonPressed = false;
    wButtonPressed = false;
    aButtonPressed = false;
    sButtonPressed = false;
    dButtonPressed = false;
}