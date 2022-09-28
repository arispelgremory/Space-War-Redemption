#ifndef SPACEWARREDEMPTIONX_DIRECTINPUT_H
#define SPACEWARREDEMPTIONX_DIRECTINPUT_H
#include "GameConfiguration.h"

// make this more reusable???
class InputManager {
public:
    InputManager();
    ~InputManager();

    static InputManager* GetInstance();
    // Initialize
    void Init(HWND g_hWnd);
    bool IsKeyDown(int KeyCode);

    // Clean Up
    void CleanUpInput();

    // Reset all keys
    void ResetAllKeys();

    void GetInput();

    // Getters
    bool GetUpButtonPressed() const;
    bool GetDownButtonPressed() const;
    bool GetEnterButtonPressed() const;
    bool GetLeftKeyPressed() const;
    bool GetRightKeyPressed() const;
    bool GetLeftMouseClicked() const;
    bool GetBackSpaceButtonPressed() const;
    bool GetMouseMoved() const;
    bool GetAButtonPressed() const;
    bool GetDButtonPressed() const;

    // Reset Input (Setters)
    void ResetUpButton();
    void ResetDownButton();
    void ResetEnterButton();
    void ResetLeftKey();
    void ResetRightKey();
    void ResetLeftMouseButton();
    void ResetBackSpaceButton();
    void ResetAButton();
    void ResetDButton();



private:
    static InputManager* _instance;
    // Direct Input
    LPDIRECTINPUT8 dInput;
    // Direct Input Keyboard Device
    LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
    // Direct Input Mouse Device
    LPDIRECTINPUTDEVICE8 dInputMouseDevice;

    //	Key input buffer
    BYTE  diKeys[256];

    // Mouse input buffer
    DIMOUSESTATE mouseState;

    // Player 1
    bool upButtonPressed;
    bool downButtonPressed;
    bool leftKeyPressed;
    bool rightKeyPressed;

    // Player 2
    bool wButtonPressed;
    bool aButtonPressed;
    bool dButtonPressed;
    bool sButtonPressed;

    bool enterButtonPressed;
    bool leftMouseClicked;
    bool backSpaceButtonPressed;


};


#endif //SPACEWARREDEMPTIONX_DIRECTINPUT_H
