#pragma once
#include "GameConfiguration.h"
#include "InputManager.h"


InputManager::InputManager() {
}

InputManager::~InputManager() {

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
        leftKeyPressed = true;
        cout << "Left Pressed!" << endl;
    }

    if (KEYDOWN(diKeys, DIK_RIGHT)) {
        rightKeyPressed = true;
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

    if (KEYDOWN(diKeys, DIK_DOWN)) {
        downButtonPressed = true;
    }
        

    if (KEYDOWN(diKeys, DIK_A)) {
        aButtonPressed = true;
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

bool InputManager::GetLeftKeyPressed() const {
    return leftKeyPressed;
}

bool InputManager::GetRightKeyPressed() const {
    return rightKeyPressed;
}

bool InputManager::GetLeftMouseClicked() const {
    return leftMouseClicked;
}

bool InputManager::GetBackSpaceButtonPressed() const {
    return backSpaceButtonPressed;
}

bool InputManager::GetAButtonPressed() const {
    return aButtonPressed;
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

void InputManager::ResetLeftKey() {
    leftKeyPressed = false;
}

void InputManager::ResetRightKey() {
    rightKeyPressed = false;
}

void InputManager::ResetLeftMouseButton() {
    leftMouseClicked = false;
}

void InputManager::ResetBackSpaceButton() {
    backSpaceButtonPressed = false;
}

void InputManager::ResetAButton() {
    aButtonPressed = false;
}

void InputManager::ResetDButton() {
    dButtonPressed = false;
}

void InputManager::ResetAllKeys()
{
    upButtonPressed = false;
    downButtonPressed = false;
    enterButtonPressed = false;
    leftKeyPressed = false;
    rightKeyPressed = false;
    leftMouseClicked = false;
    backSpaceButtonPressed = false;
    aButtonPressed = false;
    dButtonPressed = false;
}